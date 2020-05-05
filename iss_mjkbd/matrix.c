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
 * ISS TKL V2
 * Isto Saarinen 2019-03-14
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
static matrix_row_t matrix;

// Read matrix by setting column and reading every row.
// Rotated after read.
static uint8_t matrix_debouncing;

static uint8_t read_cols(void);


void matrix_init(void)
{
    matrix = 0;
    matrix_debouncing = 0;
}





uint8_t matrix_scan(void)
{
	// Read cols
    uint8_t cols = read_cols();
	//print("cols = "); print_bin8(cols);  print("\n");
    if (matrix_debouncing != cols) {
        matrix_debouncing = cols;
        if (debouncing) {
            print("bounce!: "); print_bin8(debouncing); print("\n");
        }
        debouncing = DEBOUNCE;
    }
	
	// Handle debouncing
    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            matrix = matrix_debouncing;
        }
    }

    return 1;
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix;
}


/* Column pin configuration
 * key:  F9   F8   F3   F2   F1
 * col:   0    1    2    3    4
 * pin: PF7  PF6  PB7  PB6  PB5
 */
 
 
static uint8_t read_cols(void)
{
	return ((PINF & 0b11000000) >> 3) |
		   ((PINB & 0b11100000) >> 5)
		   ;

}



