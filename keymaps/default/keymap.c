// Copyright 2020-2023 Stefan Kerkmann (@karlk90)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "printf.h"

enum Layers {
    _BASE  = 0,
    _NAV   = 1,
    _GAME  = 2,
    _RGB   = 3,
};

enum Encoder {
    _ENCODER_LEFT  = 0,
    _ENCODER_RIGHT = 1,
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT( \
     KC_GRV         , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , KC_6          ,                                 _______      ,KC_6            , KC_7           , KC_8          , KC_9          , KC_0          , KC_MINS      ,\
     KC_CAPS        , LCTL_T(KC_Q)  , KC_W          , KC_E          , KC_R          , KC_T          , KC_Y          ,                                 KC_ENT       ,KC_Y            , KC_U           , KC_I          , KC_O          , KC_P          , KC_LBRC      ,\
     KC_LSFT        , LALT_T(KC_A)  , KC_S          , KC_D          , KC_F          , KC_G          , KC_H          ,                                 KC_BSPC      ,KC_H            , KC_J           , KC_K          , KC_L          , KC_SCLN       , KC_QUOT      ,\
     KC_LCTL        , LSFT_T(KC_Z)  , KC_X          , KC_C          , KC_V          , KC_B          , KC_N          , TG(_BASE)     , _______       , _______      ,KC_N            , KC_M           , KC_COMM,      , KC_DOT        , KC_SLSH       , _______      ,\
                                                      TG(_NAV)      , _______       , KC_SPC        , KC_SPC        , KC_SPC        , _______       , _______      ,KC_SPC          , _______        , _______       , TG(_NAV)\
  ),
   [_NAV] = LAYOUT( \
    RGB_TOG         , _______       , _______       , _______       , _______       , _______       , _______       ,                                 KC_BTN4      , KC_BTN5        , _______       , _______       , _______       , _______       , RGB_TOG       ,\
    _______         , KC_PGUP       , KC_BSPC       , KC_UP         , KC_DELETE     , KC_PGDN       , _______       ,                                 KC_WH_U      , KC_BTN1        , KC_MS_U       , KC_BTN1       , _______       , _______       , _______       ,\
    _______         , KC_HOME       , KC_LEFT       , KC_DOWN       , KC_RIGHT      , KC_END        , _______       ,                                 KC_WH_D      , KC_MS_L        , KC_MS_D       , KC_MS_R       , KC_BTN2       , _______       , _______       ,\
    _______         , KC_ESC        , KC_TAB        , _______       , KC_ENT        , _______       , _______       , _______       , _______       , _______      , KC_WH_L        , KC_WH_R       , _______       , _______       , _______       , _______       ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , _______      , _______        , _______       , _______ \
  ),
  [_GAME] = LAYOUT( \
     KC_ESC         , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , LCTL(KC_GRV)  ,                                 KC_ESC       , KC_6           , KC_7          , KC_8          , KC_9          , KC_0          , KC_MINS       ,\
     KC_TAB         , KC_LSFT       , KC_Q          , KC_X          , KC_E          , KC_R          , KC_T          ,                                 KC_D         , KC_Y           , KC_U          , KC_I          , KC_O          , KC_P          , KC_LBRC       ,\
     KC_LSFT        , KC_LSFT       , KC_A          , KC_W          , KC_D          , KC_F          , KC_G          ,                                 KC_D         , KC_H           , KC_J          , KC_K          , KC_L          , KC_SCLN       , KC_QUOT       ,\
     KC_LALT        , KC_LCTL       , KC_Z          , KC_S          , KC_C          , KC_V          , KC_SPC        , KC_BSPC       , KC_BSPC       , KC_ENT       , KC_ENT         , KC_N          , KC_M          , KC_COMM       , KC_DOT        , KC_SLSH       ,\
                                                      _______       , KC_LCTL       , KC_SPC        , KC_SPC        , KC_LGUI       , KC_CAPS       , KC_ENT       , KC_SPC         , KC_LALT       , KC_D
  ),
  [_RGB] = LAYOUT( \
    RGB_TOG         , RGB_M_SW      , _______       , _______       , _______       , _______       , _______       ,                                 _______       , _______       , RGB_TOG       , RGB_M_SW      , _______       , _______       , _______       ,\
    RGB_HUI         , RGB_HUD       , RGB_SAI       , RGB_SAD       , _______       , _______       , _______       ,                                 _______       , _______       , RGB_HUI       , RGB_HUD       , RGB_SAI       , RGB_SAD       , _______       ,\
    RGB_MOD         , RGB_RMOD      , RGB_SPI       , RGB_SPD       , _______       , _______       , _______       ,                                 _______       , _______       , RGB_MOD       , RGB_RMOD      , RGB_SPI       , RGB_SPD       , _______       ,\
    RGB_VAI         , RGB_VAD       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , RGB_VAI       , RGB_VAD       , _______       , _______       , _______       ,\
                                                      _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______       , _______ \
  ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]  = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [_NAV]   = { ENCODER_CCW_CW(KC_WH_R, KC_WH_L), ENCODER_CCW_CW(KC_WH_R, KC_WH_L) },
    [_GAME]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_RGB]   = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};

// clang-format on

#if defined(HOLD_ON_OTHER_KEY_PRESS_PER_KEY)
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPC):
            return true;
        case RSFT_T(KC_SPC):
            return true;
        default:
            return false;
    }
}
#endif

#if defined(OLED_ENABLE)

#    define w_val(str, val)                         \
        snprintf(buffer, sizeof(buffer), str, val); \
        oled_write_ln(buffer, false)

void render_display(void) {
    static layer_state_t last_state    = ~0;
    layer_state_t        current_state = get_highest_layer(layer_state);

    if (last_state < _NAV && current_state < _NAV) {
        // Don't do anything if we are on the default layers
        return;
    } else if (last_state != current_state) {
        oled_clear();
        last_state = current_state;
    } else {
        return;
    }

    // char buffer[25];
    switch (current_state) {
        case _NAV:
            oled_write_ln("Nav", false);
            break;
        case _GAME:
            oled_write_ln("Game", false);
            break;
        default:
            if (is_keyboard_master()) {
                oled_write_ln("\x7QWERTY\x7", false);
            } else {
                oled_write_ln("QWERTY", false);
            }
            break;
    }
}
#endif
