// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
    LAYER_BASE = 0,
    LAYER_GAMING,
    LAYER_FN
};

enum custom_keycodes {
  A_GRAVE = SAFE_RANGE,
  E_GRAVE,
  I_GRAVE,
  O_GRAVE,
  U_GRAVE,
  A_ACUTE,
  E_ACUTE,
  I_ACUTE,
  O_ACUTE,
  U_ACUTE
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case A_GRAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "a");
      }
      return false;
    case E_GRAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "e");
      }
      return false;
    case I_GRAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "i");
      }
      return false;
    case O_GRAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "o");
      }
      return false;
    case U_GRAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`") "u");
      }
      return false;
    case A_ACUTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "a");
      }
      return false;
    case E_ACUTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "e");
      }
      return false;
    case I_ACUTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "i");
      }
      return false;
    case O_ACUTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "o");
      }
      return false;
    case U_ACUTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("e") "u");
      }
      return false;
  }
  return true;
}

/*
* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
* │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ + │Del│
* ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
* │Tab│ Q │ W │ F │ P │ G │ J │ L │ U │ Y │ ; │ [ │ ] │Bks│
* ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┤
* │Cap│ A │ R │ S │ T │ D │ H │ N │ E │ I │ O │ ' │ Enter │
* ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┬───┤
* │Sft│ Z │ X │ C │ V │ B │ K │ M │ , │ . │ / │ ` │Up │Sft│
* ├───┼───┼───┼───┼───┴───┼───┴───┼───┴───┼───┼───┼───┼───┤
* │Ctl│Gui│Alt│Fn1│ Space │ Enter │ Backs │Fn1│Lft│Dwn│Rht│
* └───┴───┴───┴───┴───────┴───────┴───────┴───┴───┴───┴───┘
*/
#define LAYOUT_LAYER_COLEMAK                                                                                                                          \
      KC_ESC,  KC_1,    KC_2,     KC_3,         KC_4,    KC_5,      KC_6,    KC_7,  KC_8,     KC_9,          KC_0,     KC_MINUS, KC_EQL,   KC_DEL,    \
      KC_TAB,  KC_Q,    KC_W,     KC_F,         KC_P,    KC_G,      KC_J,    KC_L,  KC_U,     KC_Y,          KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSPC,   \
      KC_CAPS, KC_A,    KC_R,     KC_S,         KC_T,    KC_D,      KC_H,    KC_N,  KC_E,     KC_I,          KC_O,     KC_QUOT,  KC_ENT,              \
      KC_LSFT, KC_Z,    KC_X,     KC_C,         KC_V,    KC_B,      KC_K,    KC_M,  KC_COMM,  KC_DOT,        KC_SLSH,  KC_GRV,   KC_UP,    KC_RSFT,   \
      KC_LCTL, KC_LGUI, KC_LALT,  MO(LAYER_FN), KC_SPC,             KC_ENT,         KC_BSPC,  MO(LAYER_FN),  KC_LEFT,  KC_DOWN,  KC_RIGHT

/*
* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
* │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ + │Del│
* ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
* │Tab│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │Bks│
* ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┤
* │Cap│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter │
* ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┬───┤
* │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ ` │Up │Sft│
* ├───┼───┼───┼───┼───┴───┼───┴───┼───┴───┼───┼───┼───┼───┤
* │Ctl│Gui│Alt│Fn1│ Space │ Enter │ Backs │Fn1│Lft│Dwn│Rht│
* └───┴───┴───┴───┴───────┴───────┴───────┴───┴───┴───┴───┘
*/
#define LAYOUT_LAYER_QWERTY                                                                                                                           \
      KC_ESC,  KC_1,    KC_2,     KC_3,         KC_4,    KC_5,      KC_6,    KC_7,  KC_8,     KC_9,          KC_0,     KC_MINUS, KC_EQL,   KC_DEL,    \
      KC_TAB,  KC_Q,    KC_W,     KC_E,         KC_R,    KC_T,      KC_Y,    KC_U,  KC_I,     KC_O,          KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,   \
      KC_CAPS, KC_A,    KC_S,     KC_D,         KC_F,    KC_G,      KC_H,    KC_J,  KC_K,     KC_L,          KC_SCLN,  KC_QUOT,  KC_ENT,              \
      KC_LSFT, KC_Z,    KC_X,     KC_C,         KC_V,    KC_B,      KC_N,    KC_M,  KC_COMM,  KC_DOT,        KC_SLSH,  KC_GRV,   KC_UP,    KC_RSFT,   \
      KC_LCTL, KC_LGUI, KC_LALT,  MO(LAYER_FN), KC_SPC,             KC_ENT,         KC_BSPC,  MO(LAYER_FN),  KC_LEFT,  KC_DOWN,  KC_RIGHT

/*
* ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
* │Esc│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│Bks│
* ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
* │Tab│   │   │   │   │   │   │   │   │   │   │(0)│(1)│   │
* ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┤
* │Cap│ à │ è │ ì │ ò │ ù │   │ ( │ [ │ { │   │   │ Enter │
* ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┬───┤
* │Sft│ á │ é │ í │ ó │ ú │   │ ) │ ] │ } │   │   │Up │Sft│
* ├───┼───┼───┼───┼───┴───┼───┴───┼───┴───┼───┼───┼───┼───┤
* │Ctl│Gui│Alt│Fn1│ Space │ Enter │ Backs │Fn1│Lft│Dwn│Rht│
* └───┴───┴───┴───┴───────┴───────┴───────┴───┴───┴───┴───┘
*/
#define LAYOUT_LAYER_FUNCTION                                                                                                                                          \
      _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,    KC_F7,      KC_F8,    KC_F9,          KC_F10,   KC_F11,         KC_F12,            _______, \
      _______,  KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX,  QK_BOOT,        QK_RBT,   TO(LAYER_BASE), TO(LAYER_GAMING),  _______, \
      _______,  A_GRAVE,  E_GRAVE,  I_GRAVE,  O_GRAVE,  U_GRAVE, XXXXXXX,  LSFT(KC_9), KC_LBRC,  LSFT(KC_LBRC),  XXXXXXX,  XXXXXXX,        _______,                    \
      _______,  A_ACUTE,  E_ACUTE,  I_ACUTE,  O_ACUTE,  U_ACUTE, XXXXXXX,  LSFT(KC_0), KC_RBRC,  LSFT(KC_RBRC),  XXXXXXX,  XXXXXXX,        _______,           _______, \
      _______,  _______,  _______,  _______,  _______,           _______,              _______,                  _______,  _______,        _______,           _______


#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(LAYOUT_LAYER_COLEMAK),
  [LAYER_GAMING] = LAYOUT_wrapper(LAYOUT_LAYER_QWERTY),
  [LAYER_FN] = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTION),
};
