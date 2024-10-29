/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    _LAYER_BASE = 0,
    _LAYER_GAMING,
    _LAYER_FN,
    _LAYER_MAC,
    _LAYER_LNX,
    _LAYER_POINTER
};

#define CHARYBDIS_AUTO_SNIPING_ON_LAYER _LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // C

#define LOWER MO(_LAYER_FN)
#define RAISE MO(_LAYER_MAC)
#define PT_Z LT(_LAYER_POINTER, KC_Z)
#define PT_SLSH LT(_LAYER_POINTER, KC_SLSH)
#define LNX_ESC LT(_LAYER_LNX, KC_ESC)
#define TO_B TO(_LAYER_BASE)
#define TO_G TO(_LAYER_GAMING)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// #define CHARYBDIS_MINIMUM_DEFAULT_DPI 800

enum custom_keycodes {
  A_GR_MAC = SAFE_RANGE,
  E_GR_MAC,
  I_GR_MAC,
  O_GR_MAC,
  U_GR_MAC,

  A_AC_MAC,
  E_AC_MAC,
  I_AC_MAC,
  O_AC_MAC,
  U_AC_MAC,

  A_GR_LNX,
  E_GR_LNX,
  I_GR_LNX,
  O_GR_LNX,
  U_GR_LNX,

  A_AC_LNX,
  E_AC_LNX,
  I_AC_LNX,
  O_AC_LNX,
  U_AC_LNX,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case A_GR_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "a");
      }
      return false;
    case E_GR_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "e");
      }
      return false;
    case I_GR_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "i");
      }
      return false;
    case O_GR_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "o");
      }
      return false;
    case U_GR_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "u");
      }
      return false;
    case A_AC_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "a");
      }
      return false;
    case E_AC_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "e");
      }
      return false;
    case I_AC_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "i");
      }
      return false;
    case O_AC_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "o");
      }
      return false;
    case U_AC_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "u");
      }
      return false;
    case A_GR_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_GRV) SS_UP(X_CAPS) SS_TAP(X_A));
      }
      return false;
    case E_GR_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_GRV) SS_UP(X_CAPS) SS_TAP(X_E));
      }
      return false;
    case I_GR_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_GRV) SS_UP(X_CAPS) SS_TAP(X_I));
      }
      return false;
    case O_GR_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_GRV) SS_UP(X_CAPS) SS_TAP(X_O));
      }
      return false;
    case U_GR_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_GRV) SS_UP(X_CAPS) SS_TAP(X_U));
      }
      return false;
    case A_AC_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_QUOT) SS_UP(X_QUOT) SS_TAP(X_A));
      }
      return false;
    case E_AC_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_QUOT) SS_UP(X_QUOT) SS_TAP(X_E));
      }
      return false;
    case I_AC_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_QUOT) SS_UP(X_QUOT) SS_TAP(X_I));
      }
      return false;
    case O_AC_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_QUOT) SS_UP(X_QUOT) SS_TAP(X_O));
      }
      return false;
    case U_AC_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_QUOT) SS_UP(X_QUOT) SS_TAP(X_U));
      }
      return false;

    // Shift + Backspace sends Delete
    case KC_BSPC: {
      static uint16_t registered_key = KC_NO;
      if (record->event.pressed) {  // On key press.
        const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
        uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
#else
        uint8_t shift_mods = mods & MOD_MASK_SHIFT;
#endif  // NO_ACTION_ONESHOT
        if (shift_mods) {  // At least one shift key is held.
          registered_key = KC_DEL;
          // If one shift is held, clear it from the mods. But if both
          // shifts are held, leave as is to send Shift + Del.
          if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
            del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
            unregister_mods(MOD_MASK_SHIFT);
          }
        } else {
          registered_key = KC_BSPC;
        }

        register_code(registered_key);
        set_mods(mods);
      } else {  // On key release.
        unregister_code(registered_key);
      }
    } return false;
  }
  return true;
}

#define LAYOUT_LAYER_COLEMAK                                                                                            \
      KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
          \
      KC_TAB,     KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_MINS, KC_BSPC, \
      KC_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,       KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_RSFT,    \
      KC_LCTL,    PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_K,    KC_M, KC_COMM,  KC_DOT, PT_SLSH, KC_RCTL,    \
                                    KC_LGUI, KC_SPC,  LOWER,      RAISE,   KC_ENT,                                      \
                                             KC_LALT, KC_BSPC,    LNX_ESC


#define LAYOUT_LAYER_QWERTY                                                                                           \
      KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  \
      KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,  \
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_MINS, KC_RSFT,  \
      KC_LCTL,    PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, PT_SLSH, KC_RCTL,  \
                                    KC_LGUI, KC_SPC,  LOWER,      RAISE,   KC_ENT,                                    \
                                             KC_LALT, KC_BSPC,    LNX_ESC

#define LAYOUT_LAYER_FUNCTION                                                                                                      \
      _______, _______, _______, _______, _______, _______,   _______, _______,    _______,  _______,       _______,      _______, \
      KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F5,   KC_F5,     XXXXXXX, XXXXXXX,    KC_GRAVE, KC_EQUAL,      KC_BACKSLASH, _______, \
      KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    XXXXXXX, LSFT(KC_9), KC_LBRC,  LSFT(KC_LBRC), KC_QUOTE,     _______, \
      KC_LCTL, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, LSFT(KC_0), KC_RBRC,  LSFT(KC_RBRC), KC_SEMICOLON, _______, \
                                 _______, _______, _______,   _______, _______,                                                    \
                                          _______, _______,   _______

#define LAYOUT_LAYER_MAC                                                                                                   \
      _______, _______,  _______,  _______,  _______,  _______,    _______, _______, _______,  _______, _______,  _______, \
      XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  _______, \
      _______, A_GR_MAC, E_GR_MAC, I_GR_MAC, O_GR_MAC, U_GR_MAC,   KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, _______, \
      _______, A_AC_MAC, E_AC_MAC, I_AC_MAC, O_AC_MAC, U_AC_MAC,   KC_PGDN, KC_DEL,  KC_HOME, KC_END,   KC_LCAP,  _______, \
                                   _______,  _______,  _______,    _______, _______,                                       \
                                             _______,  _______,    _______

#define LAYOUT_LAYER_LNX                                                                                                   \
      _______, _______,  _______,  _______,  _______,  _______,    _______, _______, _______,  _______, _______,  _______, \
      XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  _______, \
      _______, A_GR_LNX, E_GR_LNX, I_GR_LNX, O_GR_LNX, U_GR_LNX,   KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, _______, \
      _______, A_AC_LNX, E_AC_LNX, I_AC_LNX, O_AC_LNX, U_AC_LNX,   KC_PGDN, KC_DEL,  KC_HOME, KC_END,   KC_LCAP,  _______, \
                                   _______,  _______,  _______,    _______, _______,                                       \
                                             _______,  _______,    _______

#define LAYOUT_LAYER_POINTER                                                                                          \
      XXXXXXX, QK_BOOT, EE_CLR,  XXXXXXX, TO_B,     TO_G,        KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,\
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_RMOD, S_D_RMOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  XXXXXXX,     XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,\
      XXXXXXX, _______, DRGSCRL, SNIPING, XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, SNIPING, DRGSCRL, _______, XXXXXXX,\
                                 KC_BTN2, KC_BTN1,  KC_BTN3,     KC_BTN3, KC_BTN1,                                    \
                                          XXXXXXX,  KC_BTN2,     KC_BTN2

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER_BASE] = LAYOUT_wrapper(LAYOUT_LAYER_COLEMAK),
  [_LAYER_GAMING] = LAYOUT_wrapper(LAYOUT_LAYER_QWERTY),
  [_LAYER_FN] = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTION),
  [_LAYER_MAC] = LAYOUT_wrapper(LAYOUT_LAYER_MAC),
  [_LAYER_LNX] = LAYOUT_wrapper(LAYOUT_LAYER_LNX),
  [_LAYER_POINTER] = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
};

// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
