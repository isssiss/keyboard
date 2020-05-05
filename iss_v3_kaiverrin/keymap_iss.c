#include "keymap_iss.h"

/*
 * ISS KBD v3
 * Isto Saarinen 2020-03-26
 */

     /* 0: Default layer
     * ,-------------------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |   |   |
     * |-------------------------------------------------------------------|
     * |§  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  +|  `|  Bspc     |Hom|
     * |-------------------------------------------------------------------|
     * |Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  Å|  ~|          |PgU|
     * |-------------------------------------------------------------------|
     * |Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  Ö|  Ä|  '| Return  |PgD|
     * |-------------------------------------------------------------------|
     * |Shift |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  -|         Shift  |End|
     * |-------------------------------------------------------------------|
     * |Ctrl| < |   |   |Alt|    Space        |  |AltGr|Ins|Del|   | U |   |
	 * |                                                       | L | D | R |
     * `-------------------------------------------------------------------'
     */
/*

            0      1    2     3     4     5     6     7     8     9    10    11    12
0            A,    D,    S,    F,    J,    L,          K, LEFT,       SCLN,       PGDN, \
1            Q,    E,    W,    R,    U,    O,          I, RALT,       LBRC, RBRC, PGUP, \
2            1,    3,    2,    4,    7,    9,          8, LALT,          P, BSPC, HOME, \
3          GRV, CAPS,  ESC,    5,    6,  F10,         F5,                0,  EQL,  DEL, \
4          TAB,   F4,   F1,    T,    Y,  F11,         F6,   F9,        F12,             \
5        LCTRL,   F3,   F2,    G,    H, NUHS,         F7,   F8,       MINS,    MS_BTN3, \
6                SPC,    Z,    B,    N, DOWN, LSFT,  INS,       NUBS,   UP,  ENT, RGHT, \
7                  C,    X,    V,    M,  DOT, RSFT, COMM,             SLSH, QUOT,  END),

*/	

 
 const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// Layer 0: default
	KEYMAP( \
            A,    D,    S,    F,    J,    L,          K, LEFT,       SCLN,       PGDN, \
            Q,    E,    W,    R,    U,    O,          I, RALT,       LBRC, RBRC, PGUP, \
            1,    3,    2,    4,    7,    9,          8, LALT,          P, BSPC, HOME, \
          GRV, CAPS,  ESC,    5,    6,  F10,         F5,                0,  EQL,  DEL, \
          TAB,   F4,   F1,    T,    Y,  F11,         F6,   F9,        F12,             \
        LCTRL,   F3,   F2,    G,    H, NUHS,         F7,   F8,       MINS,    MS_BTN3, \
                SPC,    Z,    B,    N, DOWN, LSFT,  INS,       NUBS,   UP,  ENT, RGHT, \
                  C,    X,    V,    M,  DOT, RSFT, COMM,             SLSH, QUOT,  END),
};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
};
