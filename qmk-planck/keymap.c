#include QMK_KEYBOARD_H
#define __v__  KC_TRNS
#define _____  KC_NO

#define _SYM 1
#define _NAV 2
#define _FUN 3
#define _MMM 4
#define _GAM 5
#define _LOC 6

#define xx_LOPT KC_LGUI
/* #define xx_LSFT KC_LSFT */
#define xx_LSFT TD(TD_SFT)
#define xx_LCMD TD(TD_CMD)
#define xx_SYM  MO(_SYM)
/* #define xx_SYM  TD(TD_SYM) */

/* Macros */
enum custom_keycodes {
  MC_MUTE = SAFE_RANGE,
  MC_HAND,
  MC_SHOT,
};

/* Tap dance definitions */
enum {
  TD_CMD = 0,
  TD_SFT,
  TD_SYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Colemak   ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
  mod-DH    │ q  │ w  │ f  │ p  │ b  │     │ j  │ l  │ u  │ y  │ ⌫  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ a  │ r  │ s  │ t  │ g  │     │ m  │ n  │ e  │ i  │ o  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ z  │ x  │ c  │ d  │ v  │     │ k  │ h  │ ,  │ .  │ ↵ ⌃│
            └────┴────┼────┴────┴────┴─────┴────┴────┴────┼────┴────┘
            │ ⌃  │ ⌥  │ ⌘  │SYM │   ⇧   │   ␣   │NAV │ ⌥  │ mⁿ │ mⁿ │
  ┄         └────┴─── └─┆──┴────┴─┆─────┴───────┴────┴────┘ ───┴────┘
                        └ ⌥       └ ⌃     Double-tap
  */

  [0] = LAYOUT_planck_2x2u(
    KC_Q,    KC_W,    KC_F,    KC_P,   KC_B, _____,   _____,  KC_J, KC_L,     KC_U,    KC_Y,    KC_BSPC,
    KC_A,    KC_R,    KC_S,    KC_T,   KC_G, _____,   _____,  KC_M, KC_N,     KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,   KC_V, _____,   _____,  KC_K, KC_H,     KC_COMM, KC_DOT,  LCTL_T(KC_ENT),
    KC_LCTL, KC_LGUI, xx_LCMD, xx_SYM, /**/  xx_LSFT, KC_SPC, /**/  MO(_NAV), KC_LGUI, MC_HAND, MC_MUTE
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Symbols   ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │ '  │ "  │ ^  │ ?  │ `  │ quo │ [  │ <  │ =  │ >  │ ]  │ brace
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ !  │ @  │ #  │ $  │ %  │ 123 │ {  │ (  │ :  │ )  │ }  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
  ┆SYM ┆ ┄› │ \  │ ~  │ |  │ &  │ ;  │ etc │ /  │ *  │ -  │ +  │ _  │ math
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘──┬──└────┴────┴────┴────┴────┘
                      │    │ ▓▓ │ NAV   │
                      └────┴────┴───────┘ */

  [_SYM] = LAYOUT_planck_2x2u(
    KC_QUOT, KC_DQUO, KC_CIRC, KC_QUES, KC_GRV,  _____,    _____, KC_LBRC, KC_LT,   KC_EQL,  KC_GT,   KC_RBRC,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _____,    _____, KC_LCBR, KC_LPRN, KC_COLN, KC_RPRN, KC_RCBR,
    KC_SCLN, KC_TILD, KC_PIPE, KC_AMPR, KC_BSLS, _____,    _____, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_UNDS,
    __v__,   __v__,   __v__,   __v__,   /**/     MO(_NAV), __v__, /**/     __v__,   __v__,   __v__,   __v__
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Navigate  ┌────┬────┬────┐ ───┬────┐     ┌────┬────┏━━━━┓────┬────┐
            │ ⌃  │ ⌥  │ ⌘  │ :  │MMM │     │pg↑ │home┃ ▲  ┃end │FUN │
            └────┴────┴────┘ ───┼────┤     ├────┏━━━━┛────┗━━━━┓────┤
            │ 1  │ 2  │ 3  │ 4  │ 5  │     │pg↓ ┃ ◀  │ ▼  │ ▶  ┃ ↵  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┗━━━━┷━━━━┷━━━━┛────┤
  ┆NAV ┆ ┄› │ 6  │ 7  │ 8  │ 9  │ 0  │     │ ⎋  │ ↹  │ ⌘  │ ⌥  │ ⌃  │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘──┬──└────┴────┴────┴────┴────┘
                                        │       │ ▓▓ │ .  │ 
                                        └───────┴────┴────┘ */

  [_NAV] = LAYOUT_planck_2x2u(
    KC_LCTL, KC_LGUI, KC_LALT, KC_COLN, MO(_MMM), _____, _____, KC_PGUP, KC_HOME, KC_UP,   KC_END,  MO(_FUN),
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     _____, _____, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _____, _____, KC_ESC,  KC_TAB,  KC_LALT, KC_LGUI, KC_RCTL,
    __v__,   __v__,   __v__,   __v__,   /**/      __v__, __v__, /**/     __v__,   KC_DOT,  __v__,   __v__
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Function  ┏━━━━┓────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            ┃rset┃rgb │hue⁻│hue⁺│cmbt│     │caps│    │    │    │ ▓▓ │
            ┗━━━━┛────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ f₁ │ f₂ │ f₃ │ f₄ │ f₅ │     │f₁₁ │f₁₂ │f₁₃ │f₁₄ │f₁₅ │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
  ┆FUN ┆ ┄› │ f₆ │ f₇ │ f₈ │ f₉ │f₁₀ │     │f₁₆ │f₁₇ │f₁₈ │f₁₉ │f₂₀ │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘     └────┴────┴────┴────┴────┘
            │mac │win │
            └────┴────┘ */

  [_FUN] = LAYOUT_planck_2x2u(
    RESET,   RGB_TOG, RGB_HUD, RGB_HUI, CMB_TOG, _____, _____, KC_CAPS, _____,  _____,  _____,  __v__,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _____, _____, KC_F11, KC_F12, KC_F13, KC_F14,  KC_F15,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _____, _____, KC_F16, KC_F17, KC_F18, KC_F19,  KC_F20,
    LAG_SWP, LAG_NRM, __v__,   __v__,   /**/     __v__, __v__, /**/    __v__,  __v__,  __v__,   _____
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Mouse +   ┌────┬────┬────┬────┬────┐     ┌────┬────┏━━━━┓────┬────┐
  Macros +  │ m⁰ │ mⁿ │ mⁿ │    │ ▓▓ │     │ w↑ │ S↹ ┃ ▲  ┃^ ↹ │    │
  Media     ├────┼────┼────┼────┼────┤     ├────┏━━━━┛────┗━━━━┓────┤
            │GAM │    │    │    │    │     │ w↓ ┃ ◀  │ ▼  │ ▶  ┃scr⁺│
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┗━━━━┷━━━━┷━━━━┛────┤
  ┆MMM ┆ ┄› │LOC │    │    │    │    │     │vol⁻│vol⁺│play│next│scr⁻│
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘──┬──└────┴────┴────┴────┴────┘
                           │rmb │ lmb   │
                           └────┴───────┘ */
  [_MMM] = LAYOUT_planck_2x2u(
    MC_MUTE,  MC_HAND, MC_SHOT, _____,      _____, _____,      _____,      KC_WH_U, RCTL(LSFT(KC_TAB)), KC_MS_U, RCTL(KC_TAB), KC_MS_BTN2,
    DF(_GAM), _____,   _____,   _____,      _____, _____,      _____,      KC_WH_D, KC_MS_L,            KC_MS_D, KC_MS_R,      KC_BRIU,
    DF(_LOC), _____,   _____,   _____,      _____, _____,      _____,      KC_VOLD, KC_VOLU,            KC_MPLY, KC_MNXT,      KC_BRID,
    __v__,    __v__,   __v__,   KC_MS_BTN2, /**/   KC_MS_BTN1, KC_MS_BTN1, /**/     __v__,              __v__,   __v__,        __v__
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Gaming    ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
  mode      │ ↹  │ q  │ w  │ e  │ r  │     │ t  │ y  │ u  │ i  │ ⎋  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼─── ┌────┐ ───┤
            │ ⇧  │ a  │ s  │ d  │ f  │     │ g  │ h  │ j  │ ▲  │ ↵  │
            ├────┼────┼────┼────┼────┤     ├────┼─── ┌────┼────┼────┐
            │ ^  │ 1  │ 2  │ 3  │ 4  │     │ 5  │ 6  │ ◀  │ ▼  │ ▶  │
  ┌┄┄┄┄┐    └────┴────┴────┼────┴────┴─────┴────┴─── └────┴────┴────┘
  ┆gam ┆ ┄› │ z  │ x  │ c  │ v  │   ␣   │  ⌘    │ b  │ n  │ m  │exit│
  └┄┄┄┄┘    └────┴────┴────┴────┴───────┴───────┴────┴────┴────┴──●─┘
                              press to return to the base layer ──┘ */

  [_GAM] = LAYOUT_planck_2x2u(
      KC_TAB,  KC_Q, KC_W, KC_E, KC_R, _____,  _____,   KC_T, KC_Y, KC_U,    KC_I,    KC_ESC,
      KC_LSFT, KC_A, KC_S, KC_D, KC_F, _____,  _____,   KC_G, KC_H, KC_J,    KC_UP,   KC_ENT,
      KC_LCTL, KC_1, KC_2, KC_3, KC_4, _____,  _____,   KC_5, KC_6, KC_LEFT, KC_DOWN, KC_RGHT,
      KC_Z,    KC_X, KC_C, KC_V, /**/  KC_SPC, KC_LALT, /**/  KC_B, KC_N,    KC_M,    DF(0)
  ), /*
  Blank       ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
              │    │    │    │    │    │     │    │    │    │    │    │
              ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
              │    │    │    │    │    │     │    │    │    │    │    │
              ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
              │    │    │    │    │    │     │    │    │    │    │    │
              └────┴────┴────┴────┴────┴─────┴────┴────┴────┴────┴────┘ */

  [_LOC] = LAYOUT_planck_2x2u(
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, /**/   _____, _____, /**/   _____, _____, _____, DF(0)
  )
}; /*

┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
Chords      ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │ z  │ x  │ c  │ d  │ v  │     │ k  │ h  │ ,  │ .  │    │
            └────┴────┴────┴────┴────┴─────┴────┴────┴────┴────┴────┘
                                             └ ; ┄└ ' ┄└ - ┄┘
                                                  └┄┄┄┄  / ┄┘
Chords      ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
with space  │    │    │    │    │    │     │    │    │    │    │    │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │    │    │    │    │    │     │ ⌃  │    │    │    │    │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │    │    │    │    │    │     │ ⎋  │ ↹  │ ↵  │ ⌫  │    │
            └────┴────┴────┴────┴────┴─────┴────┴────┴────┴────┴────┘
*/

enum combos { CM_0, CM_1, CM_2, CM_3, CM_4, CM_5, CM_6, CM_7, CM_8, CM_9, CM_10, CM_11, CM_12 };

const uint16_t PROGMEM combo_0[] = {KC_H, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_1[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_SPC, KC_H, COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_SPC, KC_K, COMBO_END};
const uint16_t PROGMEM combo_6[] = {KC_SPC, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_7[] = {KC_SPC, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_8[] = {KC_SPC, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CM_0] = COMBO(combo_0, KC_SLSH),
  [CM_1] = COMBO(combo_1, KC_QUOT),
  [CM_2] = COMBO(combo_2, KC_SCLN),
  [CM_3] = COMBO(combo_3, KC_MINS),
  [CM_4] = COMBO(combo_4, KC_TAB),
  [CM_5] = COMBO(combo_5, KC_ESC),
  [CM_6] = COMBO(combo_6, KC_ENT),
  [CM_7] = COMBO(combo_7, C(KC_BSPC)),
  [CM_8] = COMBO(combo_8, KC_LCTL),
};

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MT(MOD_LCTL,KC_QUOT):
      return true;
    default:
      return false;
  }
}

// Macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MC_MUTE:
    if (record->event.pressed) {
      // Zoom: mute or unmute
      SEND_STRING(SS_LSFT(SS_LALT("a")));
    }
    break;
  case MC_HAND:
    if (record->event.pressed) {
      // Zoom: raise hand
      SEND_STRING(SS_LSFT(SS_LALT("y")));
    }
    break;
  case MC_SHOT:
    if (record->event.pressed) {
      // MacOS: take screenshot
      SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT("4"))));
    }
    break;
  }
  return true;
};

void tap_dance_sft_down (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1: register_code(KC_LSFT); break;
		case 2: register_code(KC_LCTL); break;
		case 3: register_code(KC_LSFT); register_code(KC_LCTL); break;
	}
}

void tap_dance_sft_up (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1: unregister_code(KC_LSFT); break;
		case 2: unregister_code(KC_LCTL); break;
		case 3: unregister_code(KC_LSFT); unregister_code(KC_LCTL); break;
	}
}

void tap_dance_cmd_down (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1: register_code(KC_LALT); break;
		case 2: register_code(KC_LGUI); break;
		case 3: register_code(KC_LALT); register_code(KC_LGUI); break;
	}
}

void tap_dance_cmd_up (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1: unregister_code(KC_LALT); break;
		case 2: unregister_code(KC_LGUI); break;
		case 3: unregister_code(KC_LALT); unregister_code(KC_LGUI); break;
	}
}

void tap_dance_sym_down (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1: layer_on(_SYM); break;
		case 2: layer_on(_NAV); break;
	}
}

void tap_dance_sym_up (qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1: layer_off(_SYM); break;
		case 2: layer_off(_NAV); break;
	}
}
// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_sft_down, tap_dance_sft_up),
  [TD_CMD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_cmd_down, tap_dance_cmd_up),
  [TD_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_sym_down, tap_dance_sym_up),
};
