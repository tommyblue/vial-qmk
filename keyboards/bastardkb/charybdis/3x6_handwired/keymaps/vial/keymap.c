// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
    _LAYER_BASE = 0,
    _LAYER_GAMING,
    _LAYER_FN,
    _LAYER_MAC,
    _LAYER_LNX,
    _LAYER_POINTER
};

#undef CHARYBDIS_AUTO_SNIPING_ON_LAYER
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER _LAYER_POINTER
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 800

enum custom_keycodes {
  A_GRAVE_MAC = SAFE_RANGE,
  E_GRAVE_MAC,
  I_GRAVE_MAC,
  O_GRAVE_MAC,
  U_GRAVE_MAC,

  A_ACUTE_MAC,
  E_ACUTE_MAC,
  I_ACUTE_MAC,
  O_ACUTE_MAC,
  U_ACUTE_MAC,

  A_GRAVE_LNX,
  E_GRAVE_LNX,
  I_GRAVE_LNX,
  O_GRAVE_LNX,
  U_GRAVE_LNX,

  A_ACUTE_LNX,
  E_ACUTE_LNX,
  I_ACUTE_LNX,
  O_ACUTE_LNX,
  U_ACUTE_LNX,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case A_GRAVE_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "a");
      }
      return false;
    case E_GRAVE_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "e");
      }
      return false;
    case I_GRAVE_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "i");
      }
      return false;
    case O_GRAVE_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "o");
      }
      return false;
    case U_GRAVE_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "u");
      }
      return false;
    case A_ACUTE_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "a");
      }
      return false;
    case E_ACUTE_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "e");
      }
      return false;
    case I_ACUTE_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "i");
      }
      return false;
    case O_ACUTE_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "o");
      }
      return false;
    case U_ACUTE_MAC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "u");
      }
      return false;
    case A_GRAVE_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_GRV) SS_UP(X_CAPS) SS_TAP(X_A));
      }
      return false;
    case E_GRAVE_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_GRV) SS_UP(X_CAPS) SS_TAP(X_E));
      }
      return false;
    case I_GRAVE_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_GRV) SS_UP(X_CAPS) SS_TAP(X_I));
      }
      return false;
    case O_GRAVE_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_GRV) SS_UP(X_CAPS) SS_TAP(X_O));
      }
      return false;
    case U_GRAVE_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_GRV) SS_UP(X_CAPS) SS_TAP(X_U));
      }
      return false;
    case A_ACUTE_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_QUOT) SS_UP(X_QUOT) SS_TAP(X_A));
      }
      return false;
    case E_ACUTE_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_QUOT) SS_UP(X_QUOT) SS_TAP(X_E));
      }
      return false;
    case I_ACUTE_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_QUOT) SS_UP(X_QUOT) SS_TAP(X_I));
      }
      return false;
    case O_ACUTE_LNX:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_QUOT) SS_UP(X_QUOT) SS_TAP(X_O));
      }
      return false;
    case U_ACUTE_LNX:
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

#define LAYOUT_LAYER_COLEMAK                                                                                                                                                          \
      KC_TAB,  KC_Q,                    KC_W,    KC_F,    KC_P,                 KC_G,      KC_J,    KC_L,                      KC_U,    KC_Y,    KC_MINUS,                   KC_BSPC, \
      KC_LSFT, KC_A,                    KC_R,    KC_S,    KC_T,                 KC_D,      KC_H,    KC_N,                      KC_E,    KC_I,    KC_O,                       KC_RSFT, \
      KC_LCTL, LT(_LAYER_POINTER, KC_Z), KC_X,    KC_C,    KC_V,                 KC_B,      KC_K,    KC_M,                      KC_COMM, KC_DOT,  LT(_LAYER_POINTER, KC_SLSH), KC_RCTL, \
                                                 KC_LGUI, LT(_LAYER_FN, KC_SPC), KC_LALT,   LT(_LAYER_LNX, KC_ESC),  LT(_LAYER_MAC, KC_ENT)

#define LAYOUT_LAYER_QWERTY                                                                                                                                                           \
      KC_TAB,  KC_Q,                    KC_W,    KC_E,    KC_R,                 KC_T,      KC_Y,    KC_U,                      KC_I,    KC_O,    KC_P,                       KC_BSPC, \
      KC_LSFT, KC_A,                    KC_S,    KC_D,    KC_F,                 KC_G,      KC_H,    KC_J,                      KC_K,    KC_L,    KC_SCLN,                    KC_RSFT, \
      KC_LCTL, LT(_LAYER_POINTER, KC_Z), KC_X,    KC_C,    KC_V,                 KC_B,      KC_N,    KC_M,                      KC_COMM, KC_DOT,  LT(_LAYER_POINTER, KC_SLSH), KC_RCTL, \
                                                 KC_LGUI, LT(_LAYER_FN, KC_SPC), KC_LALT,   LT(_LAYER_LNX, KC_ESC),  LT(_LAYER_MAC, KC_ENT)
#define LAYOUT_LAYER_FUNCTION                                                                                                                             \
      _______, KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,      XXXXXXX,    XXXXXXX,      KC_GRAVE,         KC_EQUAL,                 KC_BACKSLASH, _______, \
      _______, KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,     XXXXXXX,    LSFT(KC_9), KC_LEFT_BRACKET,  LSFT(KC_LEFT_BRACKET),  KC_QUOTE,     _______, \
      _______, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    LSFT(KC_0), KC_RIGHT_BRACKET, LSFT(KC_RIGHT_BRACKET), KC_SEMICOLON, _______, \
                               _______, _______, _______,    _______, _______

#define LAYOUT_LAYER_MAC                                                                                                                                 \
      _______, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,           KC_6,         KC_7,      KC_8,    KC_9,   KC_0,                 _______, \
      _______, A_GRAVE_MAC, E_GRAVE_MAC, I_GRAVE_MAC, O_GRAVE_MAC, U_GRAVE_MAC,    KC_PAGE_UP,   KC_LEFT,   KC_DOWN, KC_UP,  KC_RIGHT,             _______, \
      _______, A_ACUTE_MAC, E_ACUTE_MAC, I_ACUTE_MAC, O_ACUTE_MAC, U_ACUTE_MAC,    KC_PAGE_DOWN, KC_DELETE, KC_HOME, KC_END, KC_LOCKING_CAPS_LOCK, _______, \
                               _______, _______, _______,      _______, _______

#define LAYOUT_LAYER_LNX                                                                                                                                 \
      _______, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,           KC_6,         KC_7,      KC_8,    KC_9,   KC_0,                 _______, \
      _______, A_GRAVE_LNX, E_GRAVE_LNX, I_GRAVE_LNX, O_GRAVE_LNX, U_GRAVE_LNX,    KC_PAGE_UP,   KC_LEFT,   KC_DOWN, KC_UP,  KC_RIGHT,             _______, \
      _______, A_ACUTE_LNX, E_ACUTE_LNX, I_ACUTE_LNX, O_ACUTE_LNX, U_ACUTE_LNX,    KC_PAGE_DOWN, KC_DELETE, KC_HOME, KC_END, KC_LOCKING_CAPS_LOCK, _______, \
                               _______, _______, _______,      _______, _______

#define LAYOUT_LAYER_POINTER                                                                                               \
      _______, QK_BOOTLOADER, XXXXXXX, XXXXXXX, TO(_LAYER_BASE), TO(_LAYER_GAMING),    KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, \
      _______, KC_LGUI,       KC_LALT, KC_LCTL, KC_LSFT,        XXXXXXX,             KC_WH_U, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______, \
      _______, XXXXXXX,       DRGSCRL, SNIPING, XXXXXXX,        XXXXXXX,             KC_WH_D, DPI_MOD, DPI_RMOD, S_D_MOD, S_D_RMOD, _______, \
                                       KC_BTN2, KC_BTN1,        KC_BTN3,             KC_BTN3, KC_BTN1                                                                                                                                                          \

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER_BASE] = LAYOUT_wrapper(LAYOUT_LAYER_COLEMAK),
  [_LAYER_GAMING] = LAYOUT_wrapper(LAYOUT_LAYER_QWERTY),
  [_LAYER_FN] = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTION),
  [_LAYER_MAC] = LAYOUT_wrapper(LAYOUT_LAYER_MAC),
  [_LAYER_LNX] = LAYOUT_wrapper(LAYOUT_LAYER_LNX),
  [_LAYER_POINTER] = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
};

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
