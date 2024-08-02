/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum crkbd_layers {
    _QWERTY,
    _LOWER,
    _NAVCON,
    _SYSNUM,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    NAVCON,
    SYSNUM,
    RGBRST,

    LOW_SPC,
    NAV_ESC,
    NAV_QTE,

    SG_LBRC,
    SG_RBRC,
    LGUI_GRV,
    RGUI_ENT
};

// Custom keycodes for keymap shorthand
#define SG_LBRC     SGUI(KC_LBRC)
#define SG_RBRC     SGUI(KC_RBRC)
#define LGUI_GRV    LGUI(KC_GRV)

#define RGUI_ENT    RGUI_T(KC_ENT)

// Custom keycodes for layer keys
#define LOW_SPC     LT(_LOWER,  KC_SPC)         // Dual function LOWER  with Space
#define NAV_ESC     LT(_NAVCON, KC_ESC)         // Dual function NAVPAD with Escape
#define NAV_QTE     LT(_NAVCON, KC_QUOT)        // Dual function NAVPAD with Quote
#define SYSNUM      MO(_SYSNUM)                 //

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      NAV_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, NAV_QTE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SC_SENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          SC_LAPO, LOW_SPC, KC_LGUI,   RGUI_ENT, LOW_SPC, SC_RCPC
  //                                    `--------------------------'  `--------------------------'
  ),
  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       SYSNUM,   KC_NO,   KC_NO, SG_LBRC, SG_RBRC,LGUI_GRV,                        KC_NO, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,  SYSNUM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
  //                                    `--------------------------'  `--------------------------'
  ),
  [_NAVCON] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO, KC_MUTE, KC_VOLD, KC_VOLU,   KC_NO,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_NO,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_NO, KC_MRWD, KC_MPLY, KC_MFFD,   KC_NO,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,  SYSNUM, KC_TRNS,    KC_TRNS,  SYSNUM, KC_TRNS
  //                                    `--------------------------'  `--------------------------'
  ),
  [_SYSNUM] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,   KC_NO,  RGBRST,RGB_RMOD, RGB_MOD, RGB_TOG,                        KC_NO,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, KC_PAST,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_NO, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                        KC_NO,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                        KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO, KC_TRNS,  KC_NUM,    KC_TRNS,   KC_P0, KC_PDOT
  //                                    `--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGBRST:
            #ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                RGB_current_mode = rgblight_config.mode;
            }
            #endif
            #ifdef RGB_MATRIX_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
                rgb_matrix_enable();
            }
            #endif
            break;
        default:
            return true;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}
#endif
