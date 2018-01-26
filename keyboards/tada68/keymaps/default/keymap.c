#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

// https://opensource.apple.com/source/IOHIDFamily/IOHIDFamily-606.1.7/IOHIDFamily/Cosmo_USB2ADB.c
// May need to be changed to F15 or some other F* key
#define MAC_EXPOSE_ALL      0xA0
#define MAC_EXPOSE_DESKTOP  0xA1

#define _______ KC_TRNS


enum custom_keycodes {
    M_PARENS = SAFE_RANGE,
    M_SQBR,
    M_CRBR
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


// https://github.com/aaronvb/saber68-keymap/blob/master/keymap.c
// https://github.com/RazorSiM/tada68/blob/master/keymaps/default/keymap.c


/* _BL: (Base Layer) Default Layer */
[_BL] = KEYMAP_ANSI(
KC_GESC,        KC_1,       KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,       KC_9,           KC_0,       KC_MINS,    KC_EQL,         KC_BSPC,  KC_GRV, \
KC_TAB,         KC_Q,       KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O,           KC_P,       KC_LBRC,    KC_RBRC,        KC_BSLS,  KC_DEL, \
KC_LCTL,        KC_A,       KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,       KC_L,           KC_SCLN,    KC_QUOT,                    KC_ENT,   KC_PGUP,  \
KC_LSHIFT,      KC_Z,       KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT,         KC_SLSH,    KC_RSHIFT,                  KC_UP,    KC_PGDN, \
MO(_FL),        KC_LALT,    KC_LGUI,                KC_SPC,                             KC_RALT,        MO(_FL),    KC_HYPR,    KC_LEFT,        KC_DOWN,  KC_RGHT),


/* _FL: Function Layer */
[_FL] = KEYMAP_ANSI(
_______, KC_F1,     KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,     KC_POWER,  \
_______, _______,   KC_VOLU,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_INS, \
_______, BL_DEC,    KC_VOLD,    BL_INC,     _______,    _______,    _______,    M_PARENS,   M_SQBR,     M_CRBR,     _______,    _______,                _______,    KC_HOME, \
_______, _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                KC_PGUP,    KC_END, \
_______, _______,   _______,                _______,                                                    _______,    _______,    _______,    KC_HOME,    KC_PGDN,    KC_END),


};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case M_PARENS:
                SEND_STRING("()" SS_TAP(X_LEFT));
                return false;
                break;

            case M_SQBR:
                SEND_STRING("[]" SS_TAP(X_LEFT));
                return false;
                break;

            case M_CRBR:
                SEND_STRING("{}" SS_TAP(X_LEFT));
                return false;
                break;
        }
    }
    return true;
}
