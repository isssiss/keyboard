/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * ISS KBD v3
 * Isto Saarinen 2020-03-26
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];

// Read matrix by setting column and reading every row.
// Rotated after read.
static matrix_row_t matrix_debouncing[MATRIX_ROWS];


static matrix_row_t d_cols[MATRIX_ROWS];
static matrix_row_t d_cols_p[MATRIX_ROWS];



static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


void matrix_init(void)
{
	debug_enable=true;
	
    // JTAG disable for PORT F. write JTD bit twice within four cycles.
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);
	
    // initialize row and col
    unselect_rows();
    init_cols();

	
    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
		
		d_cols[i] = 0;
		d_cols_p[i] = 0;
    }
}






uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(30);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
		if (cols != d_cols_p[i]) {
			if (cols != 0) {
				print("read row = ");
				print_dec(i);
				print(", cols = ");
				print_bin16(cols);
				println();
			}
			d_cols_p[i] = cols;
		}

        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}




/* Column pin configuration
 * column:    0    1    2    3    4    5    6    7    8    9   10   11   12
 *    pin   PC7  PD6  PB7  PB6  PB5  PB4  PE6  PD7  PC6  PD4  PD0  PD2  PE2
 *    aRD:   13   12   11   10    9    8    7    6    5    4    3    0  HWB
 */
static void  init_cols(void)
{
    // Input with pull-up(DDR:0, PORT:1)
	// PC7, PC6
	DDRC &= ~0b11000000;
	PORTC |= 0b11000000;
	// PD7, PD6, PD4, PD2, PD0
	DDRD &= ~0b11010101;
	PORTD |= 0b11010101;
	// PB7, PB6, PB5, PB4
	DDRB &= ~0b11110000;
	PORTB |= 0b11110000;
	// PE6, PE2
	DDRE &= ~0b01000100;
	PORTE |= 0b01000100;
}

static matrix_row_t read_cols(void)
{
    return (PINC & (1 << PC7) ? 0 : (1 << 0)) |  // PC7
           (PIND & (1 << PD6) ? 0 : (1 << 1)) |  // PD5
           (PINB & (1 << PB7) ? 0 : (1 << 2)) |  // PB7
           (PINB & (1 << PB6) ? 0 : (1 << 3)) |  // PB6
           (PINB & (1 << PB5) ? 0 : (1 << 4)) |  // PB5
           (PINB & (1 << PB4) ? 0 : (1 << 5)) |  // PB4
           (PINE & (1 << PE6) ? 0 : (1 << 6)) |  // PE6
           (PIND & (1 << PD7) ? 0 : (1 << 7)) |  // PD7
           (PINC & (1 << PC6) ? 0 : (1 << 8)) |  // PC6
           (PIND & (1 << PD4) ? 0 : (1 << 9)) |  // PD4
           (PIND & (1 << PD0) ? 0 : (1 << 10)) | // PD0
           (PIND & (1 << PD2) ? 0 : (1 << 11)) | // PD2
           (PINE & (1 << PE2) ? 0 : (1 << 12));  // PB3
}



/* Row pin configuration
 * row:    0    1    2    3    4    5    6    7
 * pin:  PB2  PB1  PF0  PF1  PF4  PF5  PF6  PF7
 * Ard: MOSI  SCK   A5   A4   A3   A2   A1   A0
 */
static void unselect_rows(void)
{
    // Hi-Z(DDR:0, PORT:0) to unselect
    DDRF  &= ~0b11110011;
    PORTF &= ~0b11110011;
    DDRB  &= ~0b00000110;
    PORTB &= ~0b00000110;
}

static void select_row(uint8_t row)
{
    // Output low(DDR:1, PORT:0) to select
    switch (row) {
        case 7:
            DDRF  |=  (1 << PF7);
            PORTF &= ~(1 << PF7);
            break;
        case 6:
            DDRF  |=  (1 << PF6);
            PORTF &= ~(1 << PF6);
            break;
        case 5:
            DDRF  |=  (1 << PF5);
            PORTF &= ~(1 << PF5);
            break;
        case 4:
            DDRF  |=  (1 << PF4);
            PORTF &= ~(1 << PF4);
            break;
        case 3:
            DDRF  |=  (1 << PF1);
            PORTF &= ~(1 << PF1);
            break;
        case 2:
            DDRF  |=  (1 << PF0);
            PORTF &= ~(1 << PF0);
            break;
        case 1:
            DDRB  |=  (1 << PB1);
            PORTB &= ~(1 << PB1);
            break;
        case 0:
            DDRB  |=  (1 << PB2);
            PORTB &= ~(1 << PB2);
            break;
    }
}
