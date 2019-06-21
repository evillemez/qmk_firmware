#include QMK_KEYBOARD_H

// linux key shortcuts
#define LIN_MOD1          KC_LCTRL
#define LIN_MOD2          KC_LALT
#define LIN_MOD3          KC_LGUI
#define LIN_NEXT_APP      LALT(KC_TAB)
#define LIN_PREV_APP      LALT(LSFT(KC_TAB))
#define LIN_NEXT_TAB      LCTL(KC_TAB)
#define LIN_PREV_TAB      LCTL(LSFT(KC_TAB))
#define LIN_NEXT_WORD     LCTL(KC_RGHT)
#define LIN_PREV_WORD     LCTL(KC_LEFT)
#define LIN_CUT           LCTL(KC_X)
#define LIN_COPY          LCTL(KC_C)
#define LIN_PASTE         LCTL(KC_V)
#define LIN_UNDO          LCTL(KC_Z)
#define LIN_REDO          LCTL(KC_Y)
#define LIN_SEL_ALL       LCTL(KC_A)

// macOS key shortcuts
#define MAC_MOD1            KC_LGUI
#define MAC_MOD2            KC_LALT
#define MAC_MOD3            KC_LCTRL
#define MAC_NEXT_APP        LGUI(KC_TAB)
#define MAC_PREV_APP        LGUI(LSFT(KC_TAB))
#define MAC_NEXT_TAB        LCTL(KC_TAB)
#define MAC_PREV_TAB        LCTL(LSFT(KC_TAB))
#define MAC_NEXT_WORD       LALT(KC_RGHT)
#define MAC_PREV_WORD       LALT(KC_LEFT)
#define MAC_CUT             LGUI(KC_X)
#define MAC_COPY            LGUI(KC_C)
#define MAC_PASTE           LGUI(KC_V)
#define MAC_UNDO            LGUI(KC_Z)
#define MAC_REDO            LGUI(LSFT(KC_Z))
#define MAC_SEL_ALL         LGUI(KC_A)

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
    OS_SEL_ALL,

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
    _OS_SEL_ALL,

    _SET_OS_LINUX,
    _SET_OS_MAC,
};

// OS macro keycode lookup
uint16_t os_keys[][2] = {
    [_OS_MOD1] = {LIN_MOD1, MAC_MOD1},
    [_OS_MOD2] = {LIN_MOD2, MAC_MOD2},
    [_OS_MOD3] = {LIN_MOD3, MAC_MOD3},
    [_OS_NEXT_APP] = {LIN_NEXT_APP, MAC_NEXT_APP},
    [_OS_PREV_APP] = {LIN_PREV_APP, MAC_PREV_APP},
    [_OS_NEXT_TAB] = {LIN_NEXT_TAB, MAC_NEXT_TAB},
    [_OS_PREV_TAB] = {LIN_PREV_TAB, MAC_PREV_TAB},
    [_OS_NEXT_WORD] = {LIN_NEXT_WORD, MAC_NEXT_WORD},
    [_OS_PREV_WORD] = {LIN_PREV_WORD, MAC_PREV_WORD},
    [_OS_CUT] = {LIN_CUT, MAC_CUT},
    [_OS_COPY] = {LIN_COPY, MAC_COPY},
    [_OS_PASTE] = {LIN_PASTE, MAC_PASTE},
    [_OS_UNDO] = {LIN_UNDO, MAC_UNDO},
    [_OS_REDO] = {LIN_REDO, MAC_REDO},
    [_OS_SEL_ALL] = {LIN_SEL_ALL, MAC_SEL_ALL},
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
  _CURSOR,
  _NAV,
  _SYMBOLS,
  _PUNCT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT_planck_grid(
        KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_BSPC,
        KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT,
        TD(TD_SFTLOCK), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(TD_SFTLOCK),
        XXXXXXX, OS_MOD3, OS_MOD2, OS_MOD1, MO(_CURSOR), KC_SPC, KC_SPC, MO(_SYMBOLS), OS_MOD1, OS_MOD2, OS_MOD3, XXXXXXX
    ),
	[_CURSOR] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OS_CUT, OS_PREV_WORD, KC_UP, OS_NEXT_WORD, OS_SEL_ALL, KC_DEL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OS_COPY, KC_LEFT, KC_DOWN, KC_RGHT, OS_UNDO, KC_ENT,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OS_PASTE, KC_HOME, XXXXXXX, KC_END, OS_REDO,_______,
        XXXXXXX, _______, _______, _______, XXXXXXX, KC_SPC, KC_SPC, MO(_NAV), _______, _______, _______, XXXXXXX
    ),
    [_NAV] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OS_PREV_TAB, XXXXXXX, OS_NEXT_TAB, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OS_PREV_APP, XXXXXXX, OS_NEXT_APP, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,
        SET_OS_LINUX, _______, _______, _______, XXXXXXX, KC_SPC, KC_SPC, XXXXXXX, _______, _______, _______, SET_OS_MAC
    ),
	[_SYMBOLS] = LAYOUT_planck_grid(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PIPE,
        KC_UNDS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
        LSFT(KC_GRV), KC_PPLS, KC_PMNS, KC_PEQL, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, XXXXXXX,
        XXXXXXX, _______, _______, _______, MO(_PUNCT), KC_SPC, KC_SPC, XXXXXXX, _______, _______, _______, XXXXXXX
    ),
    [_PUNCT] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, KC_SLSH,  XXXXXXX,
        XXXXXXX, XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC, KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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
        case OS_NEXT_APP: process_os_macro(record, _OS_NEXT_APP); break;
        case OS_PREV_APP: process_os_macro(record, _OS_PREV_APP); break;
        case OS_NEXT_TAB: process_os_macro(record, _OS_NEXT_TAB); break;
        case OS_PREV_TAB: process_os_macro(record, _OS_PREV_TAB); break;
        case OS_NEXT_WORD: process_os_macro(record, _OS_NEXT_WORD); break;
        case OS_PREV_WORD: process_os_macro(record, _OS_PREV_WORD); break;
        case OS_CUT: process_os_macro(record, _OS_CUT); break;
        case OS_COPY: process_os_macro(record, _OS_COPY); break;
        case OS_PASTE: process_os_macro(record, _OS_PASTE); break;
        case OS_UNDO: process_os_macro(record, _OS_UNDO); break;
        case OS_REDO: process_os_macro(record, _OS_REDO); break;
        case OS_SEL_ALL: process_os_macro(record, _OS_SEL_ALL); break;

        case SET_OS_LINUX:  process_os_set(record, OS_LINUX); break;
        case SET_OS_MAC:    process_os_set(record, OS_MAC); break;
    }
    return true;
}
