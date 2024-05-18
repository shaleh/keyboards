#include QMK_KEYBOARD_H
#include "personal.h"
#include "work.h"

static const char my_email[] PROGMEM = personal_email_address;
static const char my_username[] PROGMEM = personal_user_name;
static const char my_with_name[] PROGMEM = personal_user_name_full;

/* Macros */

enum custom_keycodes {
    RGB_SLD = SAFE_RANGE,
    HSV_1,
    HSV_2,
    HSV_3,
    WORK_EMAIL,
    PERSONAL_EMAIL,
    DBL_CLN,
    DIR_UP,
    ARROW,
    NOT_EQL,
};

#define TLC TOGGLE_LAYER_COLOR

#define B_DOWN KC_BRIGHTNESS_DOWN
#define B_UP   KC_BRIGHTNESS_UP

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define SPC_L G(KC_LEFT)
#define SPC_R G(KC_RGHT)
#define LA_SYM MO(SYM_F)
#define LA_NAV MO(SYS_NAV)

#define OS_SHIFT OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT  OSM(MOD_LALT)
#define OS_CMD  OSM(MOD_LGUI)

enum layers {BASE = 0, SYM_F, SYS_NAV, SPECIAL};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*                                                                                                                                */
   [BASE] = LAYOUT(
/* ┌─────────────────────────────────────────────────┐                                                                            */
/* │ c o l e m a k                                   │       ╭╮╭╮╭╮╭╮                                                             */
/* └─────────────────────────────────────────────────┘       │╰╯╰╯╰╯│                                                             */
/* ┌──────────┬─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┬────────────┐ */
/* │   ESC    │   1/!   │   2/@   │   3/#   │   4/$   │   5/%   ││   6/^   │   7/&   │   8/\*  │   9/(   │   0/)   │    -/_     │ */
     QK_GESC,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
/* │   `/~    │         │         │         │         │         ││         │         │         │         │         │            │ */
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │   TAB    │    Q    │    W    │    F         P         B    ││    J         L         U         Y         ;          \        */
      KC_TAB,    KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,      KC_J,     KC_L,     KC_U,     KC_Y,    KC_SCLN,   KC_BSLS,
/* │          │         │         │         │         │         ││         │         │         │         │         │              */
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │ CAPSWORD │    A    │    R    │    S    │    T    │    G    ││    M    │    N    │    E    │    I    │    O    │    '/"     │ */
     CW_TOGG,    KC_A,     KC_R,     KC_S,    KC_T,      KC_G,      KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
/* │          │         │         │         │         │         ││         │         │         │         │         │            │ */
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │   ../    │    Z    │    X    │    C    │    D    │    V    ││    K    │    H    │   ,/<   │   ./>   │   //?   │            │ */
      DIR_UP,    KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,      KC_K,     KC_H,   KC_COMMA,   KC_DOT,  KC_SLSH,    KC_ENT,
/* │          │         │         │         │         │         ││         │         │         │         │         │            │ */
/* └──────────┴─────────┴─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┴─────────┴────────────┘ */
/*                                  ┌─────────────┬─────────────┐┌─────────────┬─────────────┐                                    */
/*                                  │             │    Shift    ││    SPACE    │             │                                    */
                                        LA_NAV,       KC_LSFT,       KC_SPC,       LA_SYM
/*                                  │             │             ││             │             │                                    */
/*                                  └─────────────┴─────────────┘└─────────────┴─────────────┘                                    */
   ),

   [SYM_F] = LAYOUT(
/* ┌─────────────────────────────────────────────────┐                                                                            */ 
/* │ SYM_F                                           │       ╭╮╭╮╭╮╭╮                                                             */
/* └─────────────────────────────────────────────────┘       │╰╯╰╯╰╯│                                                             */
/* ┌──────────┬─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┬────────────┐ */
/* │    F1    │    F2   │    F3   │   F4    │    F5   │   F6    ││   F7    │   F8    │   F9    │   F10   │   F11   │    F12     │ */
      KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │    @    │    [    │    {    │    (    │    ~    ││    ^    │    )    │    }    │    ]    │         │            │ */
     _______,    KC_AT,   KC_LBRC,  KC_LCBR,  KC_LPRN,  KC_TILD,   KC_CIRC,  KC_RPRN,  KC_RCBR,  KC_RBRC,  _______,    _______,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │    -    │    *    │    =    │    _    │    $    ││    #    │   CMD   │   ALT   │   CTRL  │  SHIFT  │   ARROW    │ */
     _______,   KC_MINS,  KC_ASTR,  KC_EQL,   KC_UNDS,  KC_DLR,    KC_HASH,   OS_CMD,   OS_ALT,  OS_CTRL,  OS_SHIFT,   ARROW,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │    +    │    /    │   !=    │    |    │    %    ││         │    \    │    &    │    :    │    !    │    ::      │ */
     _______,   KC_PLUS,  KC_SLASH, NOT_EQL,  KC_PIPE,  KC_PERC,   _______,  KC_BSLS,  KC_AMPR,  KC_COLN,  KC_EXLM,   DBL_CLN,
/* └──────────┴─────────┴─────────┘─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘─────────┴─────────┴────────────┘ */
/*                                          ┌─────────┬─────────┐┌─────────┬─────────┐                                            */
/*                                          │         │         ││         │         │                                            */
                                              _______,  _______,   _______,  _______
/*                                          └─────────┴─────────┘└─────────┴─────────┘                                            */
   ),

   [SYS_NAV] = LAYOUT(
/* ┌─────────────────────────────────────────────────┐                                                                            */ 
/* │ SYS_NAV                                         │       ╭╮╭╮╭╮╭╮                                                             */
/* └─────────────────────────────────────────────────┘       │╰╯╰╯╰╯│                                                             */
/* ┌──────────┬─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┬────────────┐ */
     RGB_TOG,   RGB_MOD,    TLC,    _______,  _______,  KC_MUTE,   B_DOWN,    B_UP,    _______,  _______,  _______,   _______,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │         │         │  TAB L  │  TAB R  │ VOL UP  ││         │         │         │         │         │    DEL     │ */
      HSV_1,    _______,  _______,   TAB_L,    TAB_R,   KC_VOLU,   QK_BOOT,  KC_HOME,  KC_PGUP,  KC_END,   KC_PGDN,    KC_DEL,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │  SHIFT  │  CTRL   │  ALT    │   CMD   │ VOL DN  ││         │         │         │         │         │ BACKSPACE  │ */
      HSV_2,   OS_SHIFT,  OS_CTRL,  OS_ALT,   OS_CMD,   KC_VOLD,   _______,  KC_LEFT,   KC_UP,   KC_DOWN,  KC_RIGHT,  KC_BSPC,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │ SPACE L │ SPACE R │         │         │  PLAY   ││         │         │         │         │         │            │ */
      HSV_3,     SPC_L,    SPC_R,    BACK,      FWD,    KC_MPLY,   _______,  _______,  _______,  _______,  _______,  _______,
/* └──────────┴─────────┴─────────┘─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘─────────┴─────────┴────────────┘ */
/*                                          ┌─────────┬─────────┐┌─────────┬─────────┐                                            */
/*                                          │         │         ││         │         │                                            */
                                              _______,  _______,   _______,  _______
/*                                          └─────────┴─────────┘└─────────┴─────────┘                                            */
   ),

   [SPECIAL] = LAYOUT(
/* ┌─────────────────────────────────────────────────┐                                                                            */ 
/* │ SPECIAL                                         │       ╭╮╭╮╭╮╭╮                                                             */
/* └─────────────────────────────────────────────────┘       │╰╯╰╯╰╯│                                                             */
/* ┌──────────┬─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┬────────────┐ */
        _______, _______, _______,    _______, _______,        _______,  _______, _______, _______, _______, _______, _______,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
        _______, _______, WORK_EMAIL, _______, PERSONAL_EMAIL, _______,  _______, _______, _______, _______, _______, _______,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
        _______, _______, _______,    _______, _______,        _______,  _______, _______, _______, _______, _______, _______,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
        _______, _______, _______,    _______, _______,        _______,  _______, _______, _______, _______, _______, _______,
/* └──────────┴─────────┴─────────┘─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘─────────┴─────────┴────────────┘ */
/*                                          ┌─────────┬─────────┐┌─────────┬─────────┐                                            */
/*                                          │         │         ││         │         │                                            */
                                              _______,  _______,   _______,  _______
/*                                          └─────────┴─────────┘└─────────┴─────────┘                                            */
   )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM_F, SYS_NAV, SPECIAL);
}

bool my_handle_key_pressed_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    const uint8_t all_mods = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                        | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT
    );
    const bool ctrl = all_mods & MOD_MASK_CTRL;
    const bool shifted = all_mods & MOD_MASK_SHIFT;

    switch (keycode) {
        case RGB_SLD: {
          rgblight_mode(1);
          return false;
        }
        case HSV_1: {
          rgblight_mode(1);
          rgblight_sethsv(0,255,255);
          return false;
        }
        case HSV_2: {
          rgblight_mode(1);
          rgblight_sethsv(74,255,255);
          return false;
        }
        case HSV_3: {
          rgblight_mode(1);
          rgblight_sethsv(169,255,255);
          return false;
        }
        case WORK_EMAIL: {
          SEND_STRING(work_email_address);
          return false;
        }
        case PERSONAL_EMAIL: {
          clear_weak_mods();
          unregister_mods(mods);  // Clear mods before send_string.
          SEND_STRING(shifted ? (ctrl
                                 ? personal_user_name_full : personal_user_name)
                              : personal_email_address);
          register_mods(mods);  // Restore mods.
          return false;
        }
        case DBL_CLN: {
          SEND_STRING("::");
          return false;
        }
        case DIR_UP: {
          SEND_STRING("../");
          return false;
        }
        case NOT_EQL: {
          SEND_STRING("!=");
          return false;
        }
        case ARROW: {
          SEND_STRING(ctrl ? (shifted
                              ? "<=>"
                              : "<->")
                           : (shifted
                              ? "=>"
                              : "->"));
          return false;
        }
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        return my_handle_key_pressed_user(keycode, record);
    }
    return true;
}
