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

#include <avr/io.h>
#include "stdint.h"
#include "led.h"

/*
 * ISS TKL V2
 * Isto Saarinen 2018
 */

void led_set(uint8_t usb_led)
	// PE6 = CAPS LOCK led
{
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        // led on = output high
		DDRE  |= 0b01000000;
		PORTE |= 0b01000000;
    } else {
        // led off = output low
		DDRE  |= 0b01000000;
		PORTE &= 0b10111111;
    }
}
