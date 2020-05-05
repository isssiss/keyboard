/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


/*
 * ISS KBD v3
 * Isto Saarinen 2020-03-26
 */
 

 
/* 0: Default layer
 * ,-------------------------------------------------------------------.
 * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|no |no |no |no |
 * |-------------------------------------------------------------------|
 * |§  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  +|  `|  Bspc     |Hom|
 * |-------------------------------------------------------------------|
 * |Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  Å|  ~|          |PgU|
 * |-------------------------------------------------------------------|
 * |Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  Ö|  Ä|  '| Return  |PgD|
 * |-------------------------------------------------------------------|
 * |Shift |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  -|         Shift  |End|
 * |-------------------------------------------------------------------|
 * |Ctrl| < |no |no |Alt|     Space      |no |AltGr|Ins|Del|   | U |   |
 * |                                                       | L | D | R |
 * `-------------------------------------------------------------------'
 */
/*	 
            A,    D,    S,    F,    J,    L,          K, LEFT,       SCLN,       PGDN, \
            Q,    E,    W,    R,    U,    O,          I, RALT,       LBRC, RBRC, PGUP, \
            1,    3,    2,    4,    7,    9,          8, LALT,          P, BSPC, HOME, \
          GRV, CAPS,  ESC,    5,    6,  F10,         F5,                0,  EQL,  DEL, \
          TAB,   F4,   F1,    T,    Y,  F11,         F6,   F9,        F12,             \
        LCTRL,   F3,   F2,    G,    H, NUHS,         F7,   F8,       MINS,    MS_BTN3, \
                SPC,    Z,    B,    N, DOWN, LSFT,  INS,     , NUBS,   UP,  ENT, RGHT, \
                  C,    X,    V,    M,  DOT, RSFT, COMM,             SLSH, QUOT,  END),


*/ 

#define KEYMAP( \
    K00, K01, K02, K03, K04, K05,      K07, K08,      K0A,      K0C, \
    K10, K11, K12, K13, K14, K15,      K17, K18,      K1A, K1B, K1C, \
    K20, K21, K22, K23, K24, K25,      K27, K28,      K2A, K2B, K2C, \
    K30, K31, K32, K33, K34, K35,      K37,           K3A, K3B, K3C, \
    K40, K41, K42, K43, K44, K45,      K47, K48,      K4A,           \
    K50, K51, K52, K53, K54, K55,      K57, K58,      K5A,      K5C, \
         K61, K62, K63, K64, K65, K66, K67,      K69, K6A, K6B, K6C, \
         K71, K72, K73, K74, K75, K76, K77,           K7A, K7B, K7C  \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05,    KC_NO, KC_##K07, KC_##K08,    KC_NO, KC_##K0A,    KC_NO, KC_##K0C }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15,    KC_NO, KC_##K17, KC_##K18,    KC_NO, KC_##K1A, KC_##K1B, KC_##K1C }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25,    KC_NO, KC_##K27, KC_##K28,    KC_NO, KC_##K2A, KC_##K2B, KC_##K2C }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35,    KC_NO, KC_##K37,    KC_NO,    KC_NO, KC_##K3A, KC_##K3B, KC_##K3C }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45,    KC_NO, KC_##K47, KC_##K48,    KC_NO, KC_##K4A,    KC_NO,    KC_NO }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55,    KC_NO, KC_##K57, KC_##K58,    KC_NO, KC_##K5A,    KC_NO, KC_##K5C }, \
    {    KC_NO, KC_##K61, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_##K66, KC_##K67,    KC_NO, KC_##K69, KC_##K6A, KC_##K6B, KC_##K6C }, \
    {    KC_NO, KC_##K71, KC_##K72, KC_##K73, KC_##K74, KC_##K75, KC_##K76, KC_##K77,    KC_NO,    KC_NO, KC_##K7A, KC_##K7B, KC_##K7C }, \
  }

#endif
