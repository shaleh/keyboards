#include QMK_KEYBOARD_H
#include "personal.h"
#include "work.h"

static const char my_email[] PROGMEM = personal_email_address;
static const char my_username[] PROGMEM = personal_user_name;
static const char my_with_name[] PROGMEM = personal_user_name_full;

/* Macros */

enum custom_keycodes {
    RGB_SLD = SAFE_RANGE,
    HSV_0_255_255,
    HSV_74_255_255,
    HSV_169_255_255,
    WORK_EMAIL,
    PERSONAL_EMAIL,
    DBL_CLN,
    DIR_UP,
    ARROW,
};


#define DBLQT S(KC_QUOTE)
#define TLC TOGGLE_LAYER_COLOR

#define B_DOWN KC_BRIGHTNESS_DOWN
#define B_UP   KC_BRIGHTNESS_UP

#define V_DOWN KC_AUDIO_VOL_DOWN
#define V_UP   KC_AUDIO_VOL_UP
#define V_MUTE KC_AUIDIO_MUTE

#define L_ENTER LT(SYM_F,    KC_ENTER)
#define L_SPACE LT(SYS_MOVE, KC_SPACE)
#define L_MINUS LT(SPECIAL,  KC_MINUS)

#define M_QT    MT(MOD_LSFT, KC_QUOTE)
#define M_Z     MT(MOD_LGUI, KC_Z)
#define M_X     MT(MOD_LALT, KC_X)
#define M_SLASH MT(MOD_RGUI, KC_SLASH)
#define M_DOT   MT(MOD_RALT, KC_DOT)

enum layers {BASE = 0, SYM_F, SYS_MOVE, SPECIAL};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*                                                                                                                                */
   [BASE] = LAYOUT(
/* ┌─────────────────────────────────────────────────┐                                                                            */
/* │ c o l e m a k                                   │       ╭╮╭╮╭╮╭╮                                                             */
/* └─────────────────────────────────────────────────┘       │╰╯╰╯╰╯│                                                             */
/* ┌──────────┬─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┬────────────┐ */
/* │   ESC    │   1/!   │   2/@   │   3/#   │   4/$   │   5/%   ││   6/^   │   7/&   │   8/\*  │   9/(   │   0/)   │    -/_     │ */
     QK_GESC,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     L_MINUS,
/* │   `/~    │         │         │         │         │         ││         │         │         │         │         │ L(SPECIAL) │ */
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │ CAPSWORD │    Q    │    W    │    F         P         B    ││    J         L         U         Y        ;           \        */
     CW_TOGG,    KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,      KC_J,     KC_L,     KC_U,     KC_Y,    KC_SCLN,   KC_BSLS,
/* │          │         │         │         │         │         ││         │         │         │         │         │              */
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │  SHIFT   │    A    │    R    │    S    │    T    │    G    ││    M    │    N    │    E    │    I    │    O    │    '/"     │ */
     KC_LSFT,    KC_A,     KC_R,     KC_S,    KC_T,      KC_G,      KC_M,     KC_N,     KC_E,     KC_I,     KC_O,       M_QT,
/* │          │         │         │         │         │         ││         │         │         │         │         │   Shift    │ */
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │ Control  │   Z     │    X    │    C    │    D    │    V    ││    K    │    H    │   ,/<   │   ./>   │   //?   │  Control   │ */
     KC_LCTL,     M_Z,      M_X,     KC_C,     KC_D,     KC_V,       KC_K,    KC_H,   KC_COMMA,   M_DOT,   M_SLASH,   KC_RCTL,
/* │          │   GUI   │ CMD/Alt │         │         │         ││         │         │         │ CMD/ALT │   GUI   │            │ */
/* └──────────┴─────────┴─────────┴─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┴─────────┴─────────┴────────────┘ */
/*                                  ┌─────────────┬─────────────┐┌─────────────┬─────────────┐                                    */
/*                                  │    TAB      │    Enter    ││    SPACE    │  Backspace  │                                    */
                                        KC_TAB,       L_ENTER,       L_SPACE,      KC_BSPC
/*                                  │             │   L(SYM_F)  ││ L(SYS_MOVE) │             │                                    */
/*                                  └─────────────┴─────────────┘└─────────────┴─────────────┘                                    */
   ),

   [SYM_F] = LAYOUT(
/* ┌─────────────────────────────────────────────────┐                                                                            */ 
/* │ SYM_F                                           │       ╭╮╭╮╭╮╭╮                                                             */
/* └─────────────────────────────────────────────────┘       │╰╯╰╯╰╯│                                                             */
/* ┌──────────┬─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┬────────────┐ */
/* │   ESC    │    F1   │    F2   │   F3    │    F4   │   F5    ││   F6    │   F7    │   F8    │   F9    │   F10   │    F11     │ */
     _______,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │    `    │    <    │   >     │    "    │    .    ││    &    │   ::    │   [     │    ]    │    %    │    F12     │ */
     _______,   KC_GRV,   KC_LABK,  KC_RABK,   DBLQT,   KC_DOT,    KC_AMPR,  DBL_CLN, KC_LBRC,   KC_RBRC,  KC_PERC,    KC_F12,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │    !    │    -    │   +     │    =    │    #    ││    |    │    :    │   (     │    )    │    ?    │   ARROW    │ */
     _______,   KC_EXLM,  KC_MINS,  KC_PLUS,  KC_EQL,   KC_HASH,   KC_PIPE,  KC_COLN,  KC_LPRN,  KC_RPRN,  KC_QUES,    ARROW,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │    ^    │    /    │   *     │    \    │   ../   ││    ~    │    $    │    {    │    }    │    @    │            │ */
     _______,   KC_CIRC, KC_SLASH,  KC_ASTR,  KC_BSLS,  DIR_UP,    KC_TILD,  KC_DLR,   KC_LCBR,  KC_RCBR,   KC_AT,    _______,
/* └──────────┴─────────┴─────────┘─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘─────────┴─────────┴────────────┘ */
/*                                          ┌─────────┬─────────┐┌─────────┬─────────┐                                            */
/*                                          │         │         ││         │         │                                            */
                                              _______,  _______,   _______,  _______
/*                                          └─────────┴─────────┘└─────────┴─────────┘                                            */
   ),

   [SYS_MOVE] = LAYOUT(
/* ┌─────────────────────────────────────────────────┐                                                                            */ 
/* │ SYS_MOVE                                        │       ╭╮╭╮╭╮╭╮                                                             */
/* └─────────────────────────────────────────────────┘       │╰╯╰╯╰╯│                                                             */
/* ┌──────────┬─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┬────────────┐ */
     RGB_TOG,   RGB_MOD,    TLC,    _______,  B_DOWN,    B_UP,     KC_VOLD,  KC_VOLU,  KC_MUTE,  _______,  _______,   _______,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │         │         │         │         │         ││         │         │         │         │         │            │ */
     _______,   _______,   _______, _______,  _______,  _______,   KC_PGUP,  KC_HOME,  _______,  KC_END,   _______,   _______,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │         │         │         │         │         ││         │         │         │         │         │            │ */
     _______,   _______,  _______,  _______,  _______,  _______,   KC_PGDN,  KC_LEFT,   KC_UP,   KC_DOWN,  KC_RIGHT,  _______,
/* ├──────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤ */
/* │          │         │         │         │         │         ││         │         │         │         │         │            │ */
     _______,   _______,  _______,  HSV_0_255_255, HSV_74_255_255, HSV_169_255_255, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_MS_WH_UP, KC_MS_WH_DOWN, _______,  _______,
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
        case HSV_0_255_255: {
          rgblight_mode(1);
          rgblight_sethsv(0,255,255);
          return false;
        }
        case HSV_74_255_255: {
          rgblight_mode(1);
          rgblight_sethsv(74,255,255);
          return false;
        }
        case HSV_169_255_255: {
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
