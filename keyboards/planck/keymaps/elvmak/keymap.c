#include QMK_KEYBOARD_H

enum planck_layers {
  _COLEMAK,
  _NAV,
  _SYMBOLS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   '  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  | Enter|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Shift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Gui  | Alt  | Ctrl |_NAV |    Space    |_SYMBL | Ctrl | Alt  |  Gui |      |
     * `-----------------------------------------------------------------------------------'
     */
	[_COLEMAK] = LAYOUT_planck_grid(
        KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_BSPC,
        KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, MO(_NAV), KC_SPC, KC_SPC, MO(_SYMBOLS), KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX
    ),
	[_NAV] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CUT, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), XXXXXXX, KC_DEL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COPY, KC_LEFT, KC_DOWN, KC_RGHT, KC_UNDO, KC_ENT,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSTE, KC_HOME, XXXXXXX, KC_END, KC_AGIN,KC_RSFT,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX, KC_SPC, KC_SPC, XXXXXXX, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX
    ),
	[_SYMBOLS] = LAYOUT_planck_grid(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PIPE,
        KC_UNDS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
        LSFT(KC_GRV), KC_PPLS, KC_PMNS, KC_PEQL, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, XXXXXXX,
        // KC_A, KC_A, KC_A, KC_A, KC_A, KC_SPC, KC_SPC, KC_A, KC_A, KC_A, KC_A, KC_A // for testing
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX, KC_SPC, KC_SPC, XXXXXXX, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX
    )
};
