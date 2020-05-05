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

#ifndef CONFIG_H
#define CONFIG_H

/*
 * ISS MJKBD v1 Layout
 * Isto Saarinen 2019-03-14
 */
 
/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x1552
#define DEVICE_VER      0x0001
#define MANUFACTURER    Isto Saarinen
#define PRODUCT         ISS MJKBD v1
#define DESCRIPTION     t.m.k. keyboard firmware for ISS MJKBD v1

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 5

/*
	BOARD = Jtron Beetle = Arduino Leonardo
	D11	PB7 = col2	= F3
	D10	PB6 = col3	= F2
	D9	PB5	= col4	= F1
	A1	PF7 = col0	= F8
	A0	PF6 = col1	= F9
	A2	PF5 = unused
	
	All pins must have resistor to ground (47k) and switch to VCC
	
*/

/* Column pin configuration
 * key:  F9   F8   F3   F2   F1
 * col:   0    1    2    3    4
 * pin: PF7  PF6  PB7  PB6  PB5
 */

	



/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)



/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
#define NO_ACTION_LAYER
#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#endif
