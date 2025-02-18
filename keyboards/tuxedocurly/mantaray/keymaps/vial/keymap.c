// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
    _LAYER_BASE = 0,
    _LAYER_GAMING,
    _LAYER_FN,
    _LAYER_MAC,
    _LAYER_LNX
};

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

#define LAYOUT_LAYER_COLEMAK                                                             \
      KC_ESC,    KC_1,         KC_2,    KC_3,   KC_4,    KC_5,                           \
      KC_TAB,    KC_Q,         KC_W,    KC_F,   KC_P,    KC_G,                           \
      KC_LSFT,   KC_A,         KC_R,    KC_S,   KC_T,    KC_D,                           \
      KC_LCTL,   ALT_T(KC_Z),  KC_X,    KC_C,   KC_V,    KC_B,                           \
                                                         LT(_LAYER_FN, KC_SPC), KC_LALT, \
      KC_6,      KC_7,         KC_8,    KC_9,   KC_0,    KC_MINS,                        \
      KC_J,      KC_L,         KC_U,    KC_Y,   KC_SCLN, KC_BSLS,                        \
      KC_H,      KC_N,         KC_E,    KC_I,   KC_O,    KC_RSFT,                        \
      KC_K,      KC_M,         KC_COMM, KC_DOT, KC_SLSH, KC_RGUI,                        \
                                                         LT(_LAYER_LNX, KC_BSPC),  LT(_LAYER_MAC, KC_ENT)

#define LAYOUT_LAYER_QWERTY                                                              \
      KC_ESC,    KC_1,         KC_2,    KC_3,   KC_4,    KC_5,                           \
      KC_TAB,    KC_Q,         KC_W,    KC_E,   KC_R,    KC_T,                           \
      KC_LSFT,   KC_A,         KC_S,    KC_D,   KC_F,    KC_G,                           \
      KC_LCTL,   ALT_T(KC_Z),  KC_X,    KC_C,   KC_V,    KC_B,                           \
                                                         LT(_LAYER_FN, KC_SPC), KC_LALT, \
      KC_6,      KC_7,         KC_8,    KC_9,   KC_0,    KC_MINS,                        \
      KC_Y,      KC_U,         KC_I,    KC_O,   KC_P,    KC_BSLS,                        \
      KC_H,      KC_J,         KC_K,    KC_L,   KC_SCLN, KC_RSFT,                        \
      KC_N,      KC_M,         KC_COMM, KC_DOT, KC_SLSH, KC_RGUI,                        \
                                                         LT(_LAYER_LNX, KC_BSPC),  LT(_LAYER_MAC, KC_ENT)

#define LAYOUT_LAYER_FUNCTION                                                                        \
      _______, KC_F1,      KC_F2,            KC_F3,                  KC_F4,        KC_F5,            \
      KC_GRV,  KC_EXLM,    KC_AT,            KC_HASH,                KC_DLR,       KC_PERC,          \
      _______, KC_CIRC,    KC_AMPR,          KC_ASTR,                KC_LPRN,      KC_RPRN,          \
      _______, _______,    KC_LBRC,          KC_RBRC,                KC_LCBR,      KC_RCBR,          \
                                                                                   _______, _______, \
      KC_F6,   KC_F7,      KC_F8,            KC_F9,                  KC_F10,       KC_F11,           \
      XXXXXXX, XXXXXXX,    KC_GRAVE,         KC_EQUAL,               KC_BACKSLASH, KC_F12,           \
      XXXXXXX, LSFT(KC_9), KC_LEFT_BRACKET,  LSFT(KC_LEFT_BRACKET),  KC_QUOTE,     _______,          \
      XXXXXXX, LSFT(KC_0), KC_RIGHT_BRACKET, LSFT(KC_RIGHT_BRACKET), KC_SEMICOLON, _______,          \
                                                                                   _______, _______

#define LAYOUT_LAYER_MAC                                                                           \
      _______,      _______,     _______,     _______,     _______,              _______,          \
      _______,      _______,     _______,     _______,     _______,              _______,          \
      _______,      A_GRAVE_MAC, E_GRAVE_MAC, I_GRAVE_MAC, O_GRAVE_MAC,          U_GRAVE_MAC,      \
      _______,      A_ACUTE_MAC, E_ACUTE_MAC, I_ACUTE_MAC, O_ACUTE_MAC,          U_ACUTE_MAC,      \
                                                                                 _______, _______, \
      _______,      _______,     _______,     _______,     _______,              _______,          \
      _______,      _______,     _______,     _______,     _______,              _______,          \
      KC_PAGE_UP,   KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,             _______,          \
      KC_PAGE_DOWN, KC_DELETE,   KC_HOME,     KC_END,      KC_LOCKING_CAPS_LOCK, _______,          \
                                                                                 _______, _______

#define LAYOUT_LAYER_LNX                                                                           \
      _______,      _______,     _______,     _______,     _______,              _______,          \
      _______,      _______,     _______,     _______,     _______,              _______,          \
      _______,      A_GRAVE_LNX, E_GRAVE_LNX, I_GRAVE_LNX, O_GRAVE_LNX,          U_GRAVE_LNX,      \
      _______,      A_ACUTE_LNX, E_ACUTE_LNX, I_ACUTE_LNX, O_ACUTE_LNX,          U_ACUTE_LNX,      \
                                                                                 _______, _______, \
      _______,      _______,     _______,     _______,     _______,              _______,          \
      _______,      _______,     _______,     _______,     _______,              _______,          \
      KC_PAGE_UP,   KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,             _______,          \
      KC_PAGE_DOWN, KC_DELETE,   KC_HOME,     KC_END,      KC_LOCKING_CAPS_LOCK, _______,          \
                                                                                 _______, _______

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER_BASE] = LAYOUT_wrapper(LAYOUT_LAYER_COLEMAK),
  [_LAYER_GAMING] = LAYOUT_wrapper(LAYOUT_LAYER_QWERTY),
  [_LAYER_FN] = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTION),
  [_LAYER_MAC] = LAYOUT_wrapper(LAYOUT_LAYER_MAC),
  [_LAYER_LNX] = LAYOUT_wrapper(LAYOUT_LAYER_LNX),
};

#ifdef OLED_ENABLE

// Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Draw to OLED
bool oled_task_user() {
    // set cursor position
    oled_set_cursor(0, 0);

    // Caps lock status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln(led_state.caps_lock ? PSTR("Caps\nLock\n  ON") : PSTR("Caps\nLock\n  OFF"), false);

    oled_set_cursor(0,5);
    oled_write_ln_P("Layer", false);
    switch(get_highest_layer(layer_state)) {
        case _LAYER_BASE:
        oled_write_ln(" BASE", false);
            break;
        case _LAYER_GAMING:
            oled_write_ln(" GAME", false);
            break;
        case _LAYER_FN:
            oled_write_ln(" FUNC", false);
            break;
        case _LAYER_MAC:
            oled_write_ln(" MAC ", false);
            break;
        case _LAYER_LNX:
            oled_write_ln("LINUX", false);
            break;
    }

    oled_set_cursor(0,10);
    // Get and display WPM
    uint8_t wpm = get_current_wpm();
    char wpm_str[16];
    snprintf(wpm_str, sizeof(wpm_str), "WPM:\n  %u", wpm);
    oled_write_ln(wpm_str, false);

    return false;
}

#endif

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
