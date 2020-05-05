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
 * scan matrix
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
static uint8_t matrix_debouncing[MATRIX_ROWS];

static uint8_t read_cols(void);
static void clear_rows(void);


void matrix_init(void)
{
    // initialize row and col
	// PF7 = upper data
	// PF6 = upper clock
	// PF5 = lower data
	// PF4 = lower clock
    DDRF  |= 0b11110000;
	// All outputs off
    PORTF  = 0b00000000;
	clear_rows();
    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}



void clear_rows() {
	// One extra clock is needed (RCLK & SRCLK tied together)
	PORTF = 0b01010000;
	PORTF = 0b00000000;
	// Both shift registers are clocked at the same time, only 8 clocks are needed
	for (uint8_t i = 0; i < 8; i++) {
		PORTF = 0b01010000;
		PORTF = 0b00000000;
	}
	// One extra
	PORTF = 0b01010000;
	PORTF = 0b00000000;
}





uint8_t matrix_scan(void)
{
	uint8_t i = 0;


	clear_rows();

	uint8_t column = 0;
	// Scan upper part
	// NOTE: SRCLK & RCLK are tied together
    //  => 74HC595 shift register is one clock ahead of output register
	//  => one initial clock with data = 1 is needed before reading. All other clocks with data = 0

	// First clock with data = 1
	PORTF = 0b10000000;
	PORTF = 0b11000000;
	PORTF = 0b00000000;
	// 8 clocks with data = 0 => shift through output 0 => 7
	for (uint8_t i = 0; i < 8; i++) {
		PORTF = 0b01000000;
		PORTF = 0b00000000;
		// 2us needed for output set. 1 us DOES NOT WORK. Maybe use 3 or 4 to be safe
		_delay_us(2);
		// Read rows
        uint8_t cols = read_cols();
        if (matrix_debouncing[column] != cols) {
            matrix_debouncing[column] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
		column++;
	}
	// Last clock with data = 0 to clear output 7


	// combined data & clocks for both 74HC595
	PORTF = 0b00100000;
	PORTF = 0b01110000;
	PORTF = 0b00000000;

	// 8 clocks with data = 0 => shift through output 0 => 7
	for (uint8_t i = 0; i < 8; i++) {
		PORTF = 0b00010000;
		PORTF = 0b00000000;
		// 2us needed for output set. 1 us DOES NOT WORK. Maybe use 3 or 4 to be safe
		_delay_us(2);
		// Read rows
        uint8_t cols = read_cols();
        if (matrix_debouncing[column] != cols) {
            matrix_debouncing[column] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
		column++;
	}
	// Last clock with data = 0 to clear output 7
	PORTF = 0b00010000;
	PORTF = 0b00000000;


	// Handle debouncing
    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
			// rotate matrix from matrix_deboubcing => matrix (rows to cols)
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


/* Row pin configuration
 * row:   0    1    2    3    4    5
 * pin: PB1  PB4  PB5  PB6  PB2  PB3
 */
static uint8_t read_cols(void)
{
	return ((PINB & 0b00000010) >> 1) |		// row 1 == PB1
		   ((PINB & 0b01110000) >> 3) |		// row 4, 3, 2 are in this order, just shift
		   ((PINB & 0b00001100) << 2)		// row 6, 5 are in this order, just shift
		;
}



