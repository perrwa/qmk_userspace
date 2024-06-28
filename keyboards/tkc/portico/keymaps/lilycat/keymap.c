/*
Copyright 2020 Terry Mathews

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

#include QMK_KEYBOARD_H

//  RGB-specific keys:
//  EF_INC, EF_DEC,   // next/previous backlight effect
//  H1_INC, H1_DEC,   // Color 1 hue increase/decrease
//  S1_INC, S1_DEC,   // Color 1 saturation increase/decrease
//  H2_INC, H2_DEC,   // Color 2 hue increase/decrease
//  S2_INC, S2_DEC,   // Color 2 saturation increase/decrease
//  BR_INC, BR_DEC,   // backlight brightness increase/decrease

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
            KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,  KC_DEL,
            KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,  KC_ESC,
           KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,           KC_ENT, KC_PGUP,
           KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,   KC_UP, KC_PGDN,
           KC_LCTL, KC_LALT, KC_LGUI,                             KC_SPC,                   KC_RGUI,   MO(1),          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi_blocker(
            KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_MUTE,
           RGB_TOG, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______,
           _______,RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______,           EE_CLR, KC_HOME,
           _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU,  KC_END,
           _______, _______, _______,                            _______,                   _______, _______,          KC_MPRV, KC_VOLD, KC_MNXT
    )
};
