/* Copyright 2018 MechMerlin
 * Copyright 2018 Logan Huskins
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define SPACEFN LT(1, KC_SPC)
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
   * |-----------------------------------------------------------------------------------------+
   * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * |   ESC   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |      Shift      |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl  |  GUI  |  Alt  |             SpaceFn             |  Alt  |  GUI  |  L1   | Ctrl  |
   * `-----------------------------------------------------------------------------------------'
   */

  // MO(1) - Momentary toggle onto layer 1
  [0] = LAYOUT_60_ansi(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,          KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,                            SPACEFN,                             KC_RALT, KC_RGUI, MO(3),   KC_RCTL
  ),

  /* Function
   * ,-----------------------------------------------------------------------------------------.
   * |  `  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |    Del    |
   * |-----------------------------------------------------------------------------------------+
   * |        | Ins |PgUp |HOME |     |     |     |     | Up  |     |PrtSc|ScrLk|Pause|        |
   * |-----------------------------------------------------------------------------------------+
   * |         | Del |PgDn | END |     |     |     |Left |Down |Right|     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |VolUp|VolDn|VolMu|     |     |     |     |     |     |     |                 |
   * |-----------------------------------------------------------------------------------------+
   * |       |       |       |                                 |       |  L2   |       |       |
   * `-----------------------------------------------------------------------------------------'
   */
  [1] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, KC_INS,  KC_PGUP, KC_HOME, _______, _______, _______, _______, KC_UP,    _______, KC_PSCR, KC_SLCK, KC_PAUS, _______,
    _______, KC_DEL,  KC_PGDN, KC_END,  _______, _______, _______, KC_LEFT, KC_DOWN,  KC_RGHT, _______, _______,          _______,
    _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______,           _______, _______,          _______,
    _______, _______, _______,                            _______,                             _______, MO(2),   _______, _______
  ),

  /* RGB
   * ,-----------------------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |     |     |   Reset   |
   * |-----------------------------------------------------------------------------------------+
   * | BL Tog |BLOn |BLOff|BLInc|BLDec|BLStp|BLBrtg|     |     |     |     |     |     |       |
   * |-----------------------------------------------------------------------------------------+
   * | RGB Tog |RGB +|Hue I|Sat I|Val I|Spd I|Plain|Breat|Rnbow|Swirl|     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |RGB -|Hue D|Sat D|Val D|Spd D|Snake|Knigh|Xmas |Gradi|     |                 |
   * |-----------------------------------------------------------------------------------------+
   * |       |       |       |                                 |       |       |       |       |
   * `-----------------------------------------------------------------------------------------'
   */
  [2] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, RESET,
    BL_TOGG, BL_ON,   BL_OFF,  BL_INC,  BL_DEC,  BL_STEP, BL_BRTG, _______, _______,  _______, _______, _______, _______, _______,
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, _______, _______,          _______,
    _______, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_M_SN,RGB_M_K, RGB_M_X,           RGB_M_G, _______,          _______,
    _______, _______, _______,                            _______,                             _______, _______, _______, _______
  ),
  /* Mouse layer
   * ,-----------------------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |     |     |     |WhlD |LClck|MS_UP|RClck|     |     |     |        |
   * |-----------------------------------------------------------------------------------------+
   * |         │Accl0│Accl1│Accl2│     |     |WhlU |MS_LT|MS_DN|MS_RT|     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |WhlL |MClck|WhlR |     |                 |
   * |-----------------------------------------------------------------------------------------+
   * |       |       |       |                                 |       |       |       |       |
   * `-----------------------------------------------------------------------------------------'
   */
  [3] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_WH_D, KC_BTN1, KC_UP,    KC_BTN2, _______, _______, _______, _______,
    _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, KC_WH_U, KC_LEFT, KC_DOWN,  KC_RGHT, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_BTN3,  KC_WH_R, _______, _______,          _______,
    _______, _______, _______,                            _______,                             _______, _______, _______, _______
  ),
};
