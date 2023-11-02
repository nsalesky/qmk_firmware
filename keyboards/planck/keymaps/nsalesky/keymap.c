/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,  // the default layer for Windows and Linux
  _GAMING,  // has a simpler layout with some modifiers moved around for Gaming
  _EMACS,   // no home row mods, just simple palm modifiers that are easy to hit with Emacs keybindings
  _COLEMAK, // Colemak layout
  _LOWER,
  _RAISE,
  /* _PLOVER, */
  _ADJUST,
  _NAVIGATION
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  EMACS,
  COLEMAK,
  BACKLIT,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAV MO(_NAVIGATION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |   Tab   |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |    [    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |   Esc   |  GUI(A) |  ALT(S) |  CTL(D) |  SFT(F) |    G    |    H    |  SFT(J) |  CTL(K) |  ALT(L) |  GUI(;) |    '    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |  Shift  |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |    /    | Shift ] |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |   Alt   |  Super  |         |   NAV   |En(LOWER)|  Space  |  Space  |En(RAISE)|   Bspc  |   NAV   |  Super  |   Alt   |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,              KC_T,    KC_Y,     KC_U,              KC_I,         KC_O,         KC_P,            KC_LBRC,
    KC_ESC,  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),      KC_G,    KC_H,     RSFT_T(KC_J),      RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
    KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,              KC_B,    KC_N,     KC_M,              KC_COMM,      KC_DOT,       KC_SLSH,         SFT_T(KC_RBRC),
    KC_LALT, KC_LGUI,      _______,      NAV,          LT(LOWER, KC_ENT), KC_SPC,  KC_SPC,   LT(RAISE, KC_ENT), KC_BSPC,      NAV,          KC_LGUI,         KC_LALT
),

/* Gaming
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |   Tab   |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |   Tab   |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |   Esc   |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    |    '    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |  Shift  |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |    /    | Shift   |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |   LCtl  |  Alt    |  Super  |   NAV   |En(LOWER)|  Space  |  Space  |En(RAISE)|   Bspc  |   NAV   |   Alt   |   RCtl   |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,  KC_W,   KC_E,   KC_R,       KC_T,    KC_Y,     KC_U,              KC_I,         KC_O,         KC_P,            KC_TAB,
        KC_ESC,  KC_A, KC_S, KC_D, KC_F,    KC_G,    KC_H,     KC_J,      KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,    KC_N,     KC_M,              KC_COMM,      KC_DOT,       KC_SLSH,         KC_RSFT,
        KC_LCTL, KC_LALT,      KC_LGUI,      NAV,   LT(LOWER, KC_ENT), KC_SPC,  KC_SPC,   LT(RAISE, KC_ENT), KC_BSPC,      NAV,          KC_RALT,         KC_RCTL
),

/* Emacs
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |   Tab   |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |    [    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * | CTL(ESC)|    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    |    '    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |  Shift  |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |    /    | Shift ] |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |   Alt   |  Super  |         |   NAV   |En(LOWER)|  Space  |  Space  |En(RAISE)|   Bspc  |   NAV   |  Super  |   Alt   |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_EMACS] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,              KC_T,    KC_Y,     KC_U,              KC_I,         KC_O,         KC_P,            KC_LBRC,
    LCTL_T(KC_ESC),  KC_A, KC_S, KC_D, KC_F,      KC_G,    KC_H,     KC_J,      KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,              KC_B,    KC_N,     KC_M,              KC_COMM,      KC_DOT,       KC_SLSH,         SFT_T(KC_RBRC),
    KC_LALT, KC_LGUI,      _______,      NAV,          LT(LOWER, KC_ENT), KC_SPC,  KC_SPC,   LT(RAISE, KC_ENT), KC_BSPC,      NAV,          KC_LGUI,         KC_LALT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |   Tab   |    Q    |    W    |    F    |    P    |    B    |    J    |    L    |    U    |    Y    |    ;    |    [    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |   Esc   |  GUI(A) |  ALT(R) |  CTL(S) |  SFT(T) |    G    |    M    |  SFT(N) |  CTL(E) |  ALT(I) |  GUI(O) |    '    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |  Shift  |    Z    |    X    |    C    |    D    |    V    |    K    |    H    |    ,    |    .    |    /    | Shift ] |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |   Alt   |  Super  |         |   NAV   |En(LOWER)|  Space  |  Space  |En(RAISE)|   Bspc  |   NAV   |  Super  |   Alt   |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,         KC_W,         KC_F,         KC_P,              KC_B,    KC_J,     KC_L,              KC_U,         KC_Y,         KC_SCLN,       KC_LBRC,
    KC_ESC,  LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),      KC_G,    KC_M,     RSFT_T(KC_N),      RCTL_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O),  KC_QUOT,
    KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_D,              KC_V,    KC_K,     KC_H,              KC_COMM,      KC_DOT,       KC_SLSH,       SFT_T(KC_RBRC),
    KC_LALT, KC_LGUI,      _______,      NAV,          LT(LOWER, KC_ENT), KC_SPC,  KC_SPC,   LT(RAISE, KC_ENT), KC_BSPC,      NAV,          KC_LGUI,       KC_LALT
),

/* Lower
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |    ~    |    !    |    @    |    #    |    $    |    %    |    ^    |    &    |    *    |    -    |    =    |    (    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |   F1    |   F2    |   F3    |   F4    |   F5    |   F6    |         |         |         |         |    |    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |   F7    |   F8    |   F9    |   F10   |   F11   |   F12   |         |         |         |         |    )    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |         |         |         |  ADJUST |         |         |         |         |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH,    KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR,  KC_MINS, KC_EQL,   LSFT(KC_9),
    _______, KC_F1,   KC_F2,   KC_F3,      KC_F4,   KC_F5,   KC_F6,   _______,   _______,  _______, _______,  KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,      KC_F10,  KC_F11,  KC_F12,  _______,   _______,  _______, _______,  LSFT(KC_0),
    _______, _______, _______, _______, _______, _______,    _______, _______,   _______,  _______, _______,  _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |    `    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    |    (    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |         |         |         |         |         |    -    |    +    |    \    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |         |         |         |         |         |         |         |    )    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |  ADJUST |         |         |         |         |         |         |         |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,          KC_0,         LSFT(KC_9),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, LSFT(KC_MINS), LSFT(KC_EQL), KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,      LSFT(KC_0),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,      _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |QWERTY| Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |GAMING|      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |EMACS |Voice-|Voice+|Mus on|Musoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |COLEMK|      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    QWERTY,  QK_BOOT, DB_TOGG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______ ,
    GAMING, _______, _______,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______,  _______,
    EMACS, AU_PREV,  AU_NEXT,  MU_ON,   MU_OFF,  _______,   _______,  _______, _______, _______, _______, _______,
    COLEMAK, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Navigation
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |    `    |  PgDown |   Up    |  PgUp   |         |         |         |         |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |  Left   |  Down   |  Right  |         |         |  Left   |  Down   |   Up    |  Right  |         |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |  Insert |  Home   |  Delete |         |         |         |         |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |         |         |         |         |         |         |         |         |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_NAVIGATION] = LAYOUT_planck_grid(
    _______, KC_PGDN, KC_UP  , KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
    _______, KC_INS , KC_HOME, KC_DEL , _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
  This is an empty layer definition that I can copy for future layers

[_NAVIGATION] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

 */

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
  case GAMING:
      if (record->event.pressed) {
        print("mode just switched to gaming and this is a huge string\n");
        set_single_persistent_default_layer(_GAMING);
      }
      return false;
  case EMACS:
      if (record->event.pressed) {
        print("mode just switched to emacs and this is a huge string\n");
        set_single_persistent_default_layer(_EMACS);
      }
      return false;
  case COLEMAK:
      if (record->event.pressed) {
        print("mode just switched to colemak and this is a huge string\n");
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;

    /* case COLEMAK: */
    /*   if (record->event.pressed) { */
    /*     set_single_persistent_default_layer(_COLEMAK); */
    /*   } */
    /*   return false; */
    /*   break; */
    /* case DVORAK: */
    /*   if (record->event.pressed) { */
    /*     set_single_persistent_default_layer(_DVORAK); */
    /*   } */
    /*   return false; */
    /*   break; */
    case BACKLIT:
        if (record->event.pressed) {
            register_code(KC_RSFT);

            #ifdef BACKLIGHT_ENABLE
            backlight_step();
            #endif
            #ifdef KEYBOARD_planck_rev5
            writePinLow(E6);
            #endif
        } else {
            unregister_code(KC_RSFT);
            #ifdef KEYBOARD_planck_rev5
            writePinHigh(E6);
            #endif
        }
        return false;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
