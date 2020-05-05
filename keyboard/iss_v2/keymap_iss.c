#include "keymap_iss.h"

/*
 * ISS TKL v2 Layout
 * Isto Saarinen 2018
 */

     /* 0: Default layer
     * ,---------------------------------------------------------------------------.
     * |Esc|   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |           |
     * |---------------------------------------------------------------------------|
     * |§  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  +|  `|  Bspc |   |Ins|Hom|PgU|
     * |---------------------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  Å|  ~|     |   |Del|End|PgD|
     * |---------------------------------------------------------------------------|
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L| Ö|  Ä|  '| Return  |       |   |
     * |-----------------------------------------------------------------------|Ent|
     * |Shift| <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  -|   Shift  |   |   | U |   |
     * |---------------------------------------------------------------------------|
     * |Ctrl|Win |Alt |      Space             | AltGr|  Fn  |  Ctrl   | L | D | R |
     * `---------------------------------------------------------------------------'
     */
/*
  	     ESC,          F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,       PGUP, 
		 GRV,     1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, BSPC,  INS, HOME, 
         TAB,     Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC,        DEL,  END, 
        CAPS,     A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT, NUHS,  ENT,       PGDN, 
        LSFT,  NUBS,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, RSFT,               UP, 
		LCTRL, LGUI, LALT,                    SPC,             RALT,   FN,      RCTRL, LEFT, DOWN, RGHT),
*/	

 
 const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// Layer 0: default
	KEYMAP( \
   	     ESC,          F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,       PGUP, \
		 GRV,     1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, BSPC,  INS, HOME, \
         TAB,     Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC,        DEL,  END, \
        CAPS,     A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT, NUHS,  ENT,       PGDN, \
        LSFT,  NUBS,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, RSFT,               UP, \
		LCTRL, LGUI, LALT,                    SPC,             RALT,  FN0,      RCTRL, LEFT, DOWN, RGHT),
	// Layer 0: default + F12 replaced with Print Screen
	KEYMAP( \
   	    TRNS,        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, PSCR,       TRNS, \
		TRNS,  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS,  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, \
        TRNS,  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, \
        TRNS,  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,             TRNS, \
		TRNS,  TRNS, TRNS,                   TRNS,             TRNS, TRNS,       TRNS, TRNS, TRNS, TRNS),

};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
};
