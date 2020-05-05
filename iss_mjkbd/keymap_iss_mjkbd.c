#include "keymap_iss_mjkbd.h"

/*
 * ISS MJKBD Layout
 * Isto Saarinen 2019-03-14
 */


     /* 0: Default layer
     * ,-------------------.
     * | F1| F2| F3| F8| F9|
     * `-------------------'
     */
/*
  	     F1, F2, F3, F8, F9,
*/	


/* Column pin configuration
 * key:  F9   F8   F3   F2   F1
 * col:   0    1    2    3    4
 * pin: PF7  PF6  PB7  PB6  PB5
 */

 
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// Layer 0: default
	KEYMAP( F1, F2, F3, F8, F9 ),
};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
	[0] = ACTION_LAYER_MOMENTARY(0),
};
