// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
    LAYER_BASE = 0,
    LAYER_GAMING,
    LAYER_FN,
    LAYER_ADJUST,
    LAYER_POINTER
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
* ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
* │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
* ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
* │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
* ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
* │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
* └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
*               ┌───┐                   ┌───┐
*               │GUI├───┐           ┌───┤Alt│
*               └───┤Bsp├───┐   ┌───┤Ent├───┘
*                   └───┤   │   │   ├───┘
*                       └───┘   └───┘
*/
#define LAYOUT_LAYER_COLEMAK                                                                                                                                                          \
      KC_TAB,  KC_Q,                    KC_W,    KC_F,    KC_P,                 KC_G,      KC_J,    KC_L,                      KC_U,    KC_Y,    KC_MINUS,                   KC_BSPC, \
      KC_LSFT, KC_A,                    KC_R,    KC_S,    KC_T,                 KC_D,      KC_H,    KC_N,                      KC_E,    KC_I,    KC_O,                       KC_RSFT, \
      KC_LCTL, LT(LAYER_POINTER, KC_Z), KC_X,    KC_C,    KC_V,                 KC_B,      KC_K,    KC_M,                      KC_COMM, KC_DOT,  LT(LAYER_POINTER, KC_SLSH), KC_RCTL, \
                                                 KC_LGUI, LT(LAYER_FN, KC_SPC), KC_TAB,    KC_ESC,  LT(LAYER_ADJUST, KC_ENT),  KC_RALT

#define LAYOUT_LAYER_QWERTY                                                                                                                                                           \
      KC_TAB,  KC_Q,                    KC_W,    KC_E,    KC_R,                 KC_T,      KC_Y,    KC_U,                      KC_I,    KC_O,    KC_P,                       KC_BSPC, \
      KC_LSFT, KC_A,                    KC_S,    KC_D,    KC_F,                 KC_G,      KC_H,    KC_J,                      KC_K,    KC_L,    KC_SCLN,                    KC_RSFT, \
      KC_LCTL, LT(LAYER_POINTER, KC_Z), KC_X,    KC_C,    KC_V,                 KC_B,      KC_N,    KC_M,                      KC_COMM, KC_DOT,  LT(LAYER_POINTER, KC_SLSH), KC_RCTL, \
                                                 KC_LGUI, LT(LAYER_FN, KC_SPC), KC_TAB,    KC_ESC,  LT(LAYER_ADJUST, KC_ENT),  KC_RALT
#define LAYOUT_LAYER_FUNCTION                                                                                                                             \
      _______, KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,      XXXXXXX,    XXXXXXX,      KC_GRAVE,         KC_EQUAL,                 KC_BACKSLASH, _______, \
      _______, KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,     XXXXXXX,    LSFT_T(KC_9), KC_LEFT_BRACKET,  LSFT_T(KC_LEFT_BRACKET),  KC_QUOTE,     _______, \
      _______, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    LSFT_T(KC_0), KC_RIGHT_BRACKET, LSFT_T(KC_RIGHT_BRACKET), KC_SEMICOLON, _______, \
                               _______, _______, _______,    _______, _______, _______

#define LAYOUT_LAYER_ADJUST                                                                                                             \
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,         KC_7,      KC_8,    KC_9,   KC_0,                 _______, \
      _______, A_GRAVE, E_GRAVE, I_GRAVE, O_GRAVE, U_GRAVE,    KC_PAGE_UP,   KC_LEFT,   KC_DOWN, KC_UP,  KC_RIGHT,             _______, \
      _______, A_ACUTE, E_ACUTE, I_ACUTE, O_ACUTE, U_ACUTE,    KC_PAGE_DOWN, KC_DELETE, KC_HOME, KC_END, KC_LOCKING_CAPS_LOCK, _______, \
                               _______, _______, _______,      _______, _______, _______

#define LAYOUT_LAYER_POINTER                                                                                               \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, TO(LAYER_BASE), TO(LAYER_GAMING),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOTLOADER, _______, \
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,        XXXXXXX,             KC_WH_U, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,       _______, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,             KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       _______, \
                                 KC_BTN2, KC_BTN1,        KC_BTN3,             KC_BTN3, KC_BTN1, KC_BTN2                                                                                                                                                          \
// MS_BTN2, MS_BTN1, MS_BTN3,    MS_BTN3, MS_BTN1, MS_BTN2

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(LAYOUT_LAYER_COLEMAK),
  [LAYER_GAMING] = LAYOUT_wrapper(LAYOUT_LAYER_QWERTY),
  [LAYER_FN] = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTION),
  [LAYER_ADJUST] = LAYOUT_wrapper(LAYOUT_LAYER_ADJUST),
  [LAYER_POINTER] = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
};
