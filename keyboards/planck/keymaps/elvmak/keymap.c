#include QMK_KEYBOARD_H

// linux key shortcuts
#define LIN_MOD1          KC_LCTRL
#define LIN_MOD2          KC_LALT
#define LIN_MOD3          KC_LGUI
#define LIN_NEXT_APP      KC_LGUI(KC_TAB)
#define LIN_PREV_APP      KC_LGUI(KC_LSHIFT(KC_TAB))
#define LIN_NEXT_TAB      KC_LALT(KC_TAB)
#define LIN_PREV_TAB      KC_LALT(KC_LSHIFT(KC_TAB))
#define LIN_NEXT_WORD     KC_LCTRL(KC_RGHT)
#define LIN_PREV_WORD     KC_LCTRL(KC_LEFT)
#define LIN_CUT           KC_LCTRL(KC_X)
#define LIN_COPY          KC_LCTRL(KC_C)
#define LIN_PASTE         KC_LCTRL(KC_V)
#define LIN_UNDO          KC_LCTRL(KC_X)
#define LIN_REDO          KC_LCTRL(KC_Y)

// macOS key shortcuts
#define MAC_MOD1            KC_LGUI
#define MAC_MOD2            KC_LALT
#define MAC_MOD3            KC_LCTRL
#define MAC_NEXT_APP        KC_LGUI(KC_TAB)
#define MAC_PREV_APP        KC_LGUI(KC_LSHIFT(KC_TAB))
#define MAC_NEXT_TAB        KC_LCTRL(KC_TAB)
#define MAC_PREV_TAB        KC_LCTRL(KC_LSHIFT(KC_TAB))
#define MAC_NEXT_WORD       KC_LALT(KC_RGHT)
#define MAC_PREV_WORD       KC_LALT(KC_LEFT)
#define MAC_CUT             KC_LGUI(KC_X)
#define MAC_COPY            KC_LGUI(KC_C)
#define MAC_PASTE           KC_LGUI(KC_V)
#define MAC_UNDO            KC_LGUI(KC_Z)
#define MAC_REDO            KC_LGUI(KC_LSHIFT(KC_Z))

// OS setting for macro keys
enum {
    OS_LINUX = 0,
    OS_MAC,
    OS_WIN,
};
int OS = OS_LINUX;

// OS macro keycodes
enum custom_keycodes {
    OS_MOD1 = SAFE_RANGE,
    OS_MOD2,
    OS_MOD3,
    OS_NEXT_APP,
    OS_PREV_APP,
    OS_NEXT_TAB,
    OS_PREV_TAB,
    OS_NEXT_WORD,
    OS_PREV_WORD,
    OS_CUT,
    OS_COPY,
    OS_PASTE,
    OS_UNDO,
    OS_REDO,

    SET_OS_LINUX,
    SET_OS_MAC,
};

// index for mapping custom os key to os-specific keycodes
enum custom_keycode_index {
    _OS_MOD1 = 0,
    _OS_MOD2,
    _OS_MOD3,
    _OS_NEXT_APP,
    _OS_PREV_APP,
    _OS_NEXT_TAB,
    _OS_PREV_TAB,
    _OS_NEXT_WORD,
    _OS_PREV_WORD,
    _OS_CUT,
    _OS_COPY,
    _OS_PASTE,
    _OS_UNDO,
    _OS_REDO,

    _SET_OS_LINUX,
    _SET_OS_MAC,
};

// OS macro keycode lookup
uint16_t os_keys[][2] = {
    [_OS_MOD1] = {LIN_MOD1, MAC_MOD1},
    [_OS_MOD2] = {LIN_MOD2, MAC_MOD2},
    [_OS_MOD3] = {LIN_MOD3, MAC_MOD3},
};

// Tap dance declarations
enum {
  TD_SFTLOCK = 0  // Tap once for OSM shift, twice for Caps Lock
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SFTLOCK]  = ACTION_TAP_DANCE_DOUBLE(OSM(KC_LSFT), KC_CAPS)
};


enum planck_layers {
  _COLEMAK,
  _NAV,
  _SYMBOLS,
  _PUNCT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT_planck_grid(
        KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_BSPC,
        KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT,
        TD(TD_SFTLOCK), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(TD_SFTLOCK),
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

void process_os_macro(keyrecord_t *record, uint16_t codes_index) {
    uint16_t code = os_keys[codes_index][OS];
    if (record->event.pressed) {
        register_code16(code);
    } else {
        unregister_code16(code);
    }
}

void process_os_set(keyrecord_t *record, int os) {
    if (record->event.pressed) {
        OS = os;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_MOD1: process_os_macro(record, _OS_MOD1); break;
        case OS_MOD2: process_os_macro(record, _OS_MOD2); break;
        case OS_MOD3: process_os_macro(record, _OS_MOD3); break;

        case SET_OS_LINUX:  process_os_set(record, OS_LINUX); break;
        case SET_OS_MAC:    process_os_set(record, OS_MAC); break;
    }
    return true;
}
