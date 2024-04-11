#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
 *
 * ,---------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |   0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |   0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |
 * `---------------------------------------------------------------------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_svlinky(
  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
  KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
  KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9,
  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
  KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
  KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9
)
};
