#include QMK_KEYBOARD_H
#include "version.h"
#include "personal.h"
#include "work.h"

/* Macros */

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    HSV_0_255_255,
    HSV_74_255_255,
    HSV_169_255_255,
    WORK_EMAIL,
    PERSONAL_EMAIL,
    DBL_CLN,
    DIR_UP,
    ARROW,
};


#define US_CW QK_CAPS_WORD_TOGGLE

#define L1 LT(SYM_F,    KC_ENTER)
#define L2 LT(SYS_MOVE, KC_SPACE)
#define L3 LT(SPECIAL,  KC_MINUS)

#define M1 MT(MOD_LSFT, KC_QUOTE)
#define M2 MT(MOD_LALT, KC_Z)
#define M3 MT(MOD_LALT, KC_SLASH)
#define M4 MT(MOD_LCTL, KC_TAB)
#define M5 MT(MOD_RGUI, KC_K)

enum layers {BASE = 0, SYM_F, SYS_MOVE, SPECIAL};

/*
   ┌─────────────────────────────────────────────────┐
   │ t e m p l a t e                                 │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
   ┌─────────┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┬─────────┐
   │         │         │         │         │         │         ││         │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         │         ││         │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         │         ││         │         │         │         │         │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         │         ││         │         │         │         │         │         │
   └─────────┴─────────┴─────────┘─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘─────────┴─────────┴─────────┘
                                           ┌─────────┌─────────┐┌─────────┌─────────┐
                                           │         │         ││         │         │
                                           └─────────┴─────────┘└─────────┴─────────┘
 */
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
/*
   ┌─────────────────────────────────────────────────┐
   │ c o l e m a k                                   │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
   ┌─────────┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┬────────────┐
   │   `/~   │   1/!   │   2/@   │   3/#   │   4/$   │   5/%   ││   6/^   │   7/&   │   8/\*  │   9/(   │   0/)   │    -/_     │
   │         │         │         │         │         │         ││         │         │         │         │         │ L(SPECIAL) │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤
   │CAPSWORD │    Q    │    W    │    F    │    P    │    B    ││    J    │    L    │    U    │    Y    │   ;/:   │    \/|     │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤
   │  SHIFT  │    A    │    R    │    S    │    T    │    G    ││    M    │    N    │    E    │    I    │    O    │    '/"     │
   │         │         │         │         │         │         ││         │         │         │         │         │   Shift    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼────────────┤
   │   CMD   │    X    │    C    │    D    │    V    │    Z    ││    K    │    H    │   ,/<   │   ./>   │   //?   │  Control   │
   │         │  OPTION │         │         │         │         ││   CMD   │         │         │         │  OPTION │            │
   └─────────┴─────────┴─────────┘─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘─────────┴─────────┴────────────┘
                                           ┌─────────┌─────────┐┌─────────┌─────────────┐
                                           │  Enter  │   TAB   ││  BKSPC  │    SPACE    │
                                           │ L(SYM_F)│ Control ││         │ L(SYS_MOVE) │
                                           └─────────┴─────────┘└─────────┴─────────────┘
 */
    [BASE] = LAYOUT_voyager(
        KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5,
        US_CW,   KC_Q, KC_W, KC_F, KC_P, KC_B,
        KC_LSFT, KC_A, KC_R, KC_S, KC_T, KC_G,
        KC_LGUI, M2,   KC_X, KC_C, KC_D, KC_V,
                                   L1,   M4,

                 KC_6,    KC_7, KC_8,     KC_9,   KC_0,    L3,
                 KC_J,    KC_L, KC_U,     KC_Y,   KC_SCLN, KC_BSLS,
                 KC_M,    KC_N, KC_E,     KC_I,   KC_O,    M1,
                 M5,      KC_H, KC_COMMA, KC_DOT, M3,      KC_RCTL,
                 KC_BSPC, L2
    ),

/*
   ┌─────────────────────────────────────────────────┐
   │ SYM_F                                           │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
   ┌─────────┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┬─────────┐
   │   ESC   │    F1   │    F2   │   F3    │    F4   │   F5    ││   F6    │   F7    │   F8    │   F9    │   F10   │   F11   │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │    `    │    <    │   >     │    "    │    .    ││    &    │   ::    │   [     │    ]    │    %    │   F12   │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │    !    │    -    │   +     │    =    │    #    ││    |    │    :    │   (     │    )    │    ?    │  ARROW  │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │    ^    │    /    │   *     │    \    │   ../   ││    ~    │    $    │   {     │    }    │    @    │         │
   └─────────┴─────────┴─────────┘─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘─────────┴─────────┴─────────┘
                                           ┌─────────┌─────────┐┌─────────┌─────────┐
                                           │         │         ││         │         │
                                           └─────────┴─────────┘└─────────┴─────────┘
 */
    [SYM_F] = LAYOUT_voyager(
       KC_ESC,   KC_F1,   KC_F2,    KC_F3,    KC_F4,   KC_F5,
       _______,  KC_GRV,  KC_LABK,  KC_RABK,  DBLQT,   KC_DOT,
       _______,  KC_EXLM, KC_MINS,  KC_PLUS,  KC_EQL,  KC_HASH,
       _______,  KC_CIRC, KC_SLASH, KC_ASTR,  KC_BSLS, DIR_UP,
                                              _______, _______,

                 KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,
                 KC_AMPR, DBL_CLN, KC_LBRC,  KC_RBRC, KC_PERC, KC_F12,
                 KC_PIPE, KC_COLN, KC_LPRN,  KC_RPRN, KC_QUES, ARROW,
                 KC_TILD, KC_DLR,  KC_LCBR,  KC_RCBR, KC_AT,   _______,
                 _______, _______
    ),

    [SYS_MOVE] = LAYOUT_voyager(
        RGB_TOG,     TOGGLE_LAYER_COLOR,  _______,             _______,         KC_BRIGHTNESS_DOWN,  KC_BRIGHTNESS_UP,
        _______,     _______,             KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP, KC_AUDIO_MUTE,       _______,
        KC_KB_POWER, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK, KC_MEDIA_STOP,   KC_MEDIA_PLAY_PAUSE, _______,
        _______,     _______,             _______,             HSV_0_255_255,   HSV_74_255_255,      HSV_169_255_255,
                                                                                _______,             _______,

                     _______,            _______,      _______,     _______,       _______,  RESET,
                     KC_PAGE_UP,         KC_HOME,      _______,     KC_END,        _______,  _______,
                     KC_PGDN,            KC_LEFT,      KC_UP,       KC_DOWN,       KC_RIGHT, _______,
                     LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_MS_WH_UP, KC_MS_WH_DOWN, _______,  _______,
                     _______,            _______
    ),

    [SPECIAL] = LAYOUT_voyager(
        _______, _______, _______,    _______, _______,        _______,
        _______, _______, WORK_EMAIL, _______, PERSONAL_EMAIL, _______,
        _______, _______, _______,    _______, _______,        _______,
        _______, _______, _______,    _______, _______,        _______,
                                               _______,        _______,

                 _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
                 _______, _______
    )
};

bool my_handle_key_pressed_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    const uint8_t all_mods = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                        | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT const bool shifted = all_mods & MOD_MASK_SHIFT;
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
          static const char email[] PROGMEM = personal_email_address;
          static const char username[] PROGMEM = personal_user_name;
          static const char with_name[] PROGMEM = personal_user_name_full;
          clear_weak_mods();
          unregister_mods(mods);  // Clear mods before send_string.
          SEND_STRING(shifted ? (ctrl
                                 ? with_name : username)
                              : email);
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
                              ? "<=>"   // <=>
                              : "<->")  // <->
                           : (shifted
                              ? "=>"    // =>
                              : "->")); // ->
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
};
