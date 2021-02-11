#include QMK_KEYBOARD_H
#define _____  KC_TRNS
#define __x__  KC_NO

#define _SYM 1
#define _NAV 2
#define _PAD 3
#define _FUN 4
#define _GAM 5

#define xx_Z   MT(MOD_LSFT,KC_Z)     // z + shift
#define xx_CBSP C(KC_BSPC)           // delete word
/* #define xx_LCMD LALT_T(KC_ES) */
#define xx_LOPT LGUI_T(KC_TAB)
#define xx_SPC KC_LSFT
#define xx_LCMD TD(TD_0)

/* Macros */
enum custom_keycodes {
  MC_MUTE = SAFE_RANGE,
  MC_HAND,
  MC_SHOT,
};

/* Tap dance definitions */
enum {
  TD_0 = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Colemak   ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
  mod-DH    │ q  │ w  │ f  │ p  │ b  │     │ j  │ l  │ u  │ y  │ ⌫  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ a  │ r  │ s  │ t  │ g  │     │ m  │ n  │ e  │ i  │ o  │ 
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ z  │ x  │ c  │ d  │ v  │     │ k  │ h  │ ,  │ .  │ ↵ ⌃│
            └────┴────┼────┼────┴────┴─────┴────┴────┼────┼────┴────┘
            │ ⌃  │ ⌥  │ ⌘  │SYM │   ⇧   │   ␣   │NAV │ ⌥ ↹│ mⁿ │ mⁿ │
  ┄         └────┴─── └────┴────┴───────┴───────┴────┴────┘ ───┴────┘ */

  [0] = LAYOUT_planck_2x2u(
    KC_Q,    KC_W,    KC_F,    KC_P,      KC_B, __x__,  __x__,  KC_J, KC_L,     KC_U,    KC_Y,    KC_BSPC,
    KC_A,    KC_R,    KC_S,    KC_T,      KC_G, __x__,  __x__,  KC_M, KC_N,     KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,      KC_V, __x__,  __x__,  KC_K, KC_H,     KC_COMM, KC_DOT,  LCTL_T(KC_ENT),
    KC_LCTL, xx_LOPT, xx_LCMD, OSL(_SYM), /**/  xx_SPC, KC_SPC, /**/  MO(_NAV), xx_LOPT, MC_MUTE, MC_HAND
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Symbols   ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │ '  │ "  │ ^  │ ?  │ `  │ quo │ [  │ <  │ =  │ >  │ ]  │ brace
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ !  │ @  │ #  │ $  │ %  │ 123 │ {  │ (  │ :  │ )  │ }  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
  ┆SYM ┆ ┄› │ \  │ ~  │ |  │ &  │ ;  │ etc │ /  │ *  │ -  │ +  │ _  │ math
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘     └────┴────┴────┴────┴────┘ */

  [_SYM] = LAYOUT_planck_2x2u(
    KC_QUOT, KC_DQUO, KC_CIRC, KC_QUES, KC_GRV,  __x__, __x__, KC_LBRC, KC_LT,   KC_EQL,  KC_GT,   KC_RBRC,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, __x__, __x__, KC_LCBR, KC_LPRN, KC_COLN, KC_RPRN, KC_RCBR,
    KC_SCLN, KC_TILD, KC_PIPE, KC_AMPR, KC_BSLS, __x__, __x__, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_UNDS,
    _____,   _____,   _____,   _____,   /**/     _____, _____, /**/     _____,   _____,   _____,   _____
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Navigate  ┌────┬────┬────┐ ───┬────┐     ┌────┬────┏━━━━┓────┬────┐
            │ ⌃  │ ⌥  │ ⌘  │ ↹  │ ⎋  │     │pg↑ │home┃ ▲  ┃end │FUN │
            └────┴────┴────┘ ───┼────┤     ├────┏━━━━┛────┗━━━━┓────┘
            │ 1  │ 2  │ 3  │ 4  │ 5  │     │pg↓ ┃ ◀  │ ▼  │ ▶  ┃ ↵  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┗━━━━┷━━━━┷━━━━┛────┐
  ┆NAV ┆ ┄› │ 6  │ 7  │ 8  │ 9  │ 0  │     │ ⎋  │ ↹  │    │    │PAD │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘     └────┴────┴────┴────┴────┘ */

  [_NAV] = LAYOUT_planck_2x2u(
    KC_LCTL, KC_LGUI, KC_LALT, KC_TAB, KC_ESC, __x__, __x__, KC_PGUP, KC_HOME, KC_UP,   KC_END,  MO(_FUN),
    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   __x__, __x__, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   __x__, __x__, KC_ESC,  KC_TAB,  __x__,   __x__,   MO(_PAD),
    _____,   _____,   _____,   _____,   /**/     _____, _____, /**/     _____,   _____,   _____,   _____
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Numpad +  ┌────┏━━━━┯━━━━┯━━━━┓────┐     ┌────┬────┬────┬────┬────┐
  Macropad  │ :  ┃ 1  │ 2  │ 3  ┃ /  │     │ ✓  │ ✓  │ .  │    │    │
            ├────┃────┼────┼────┃────┤     ├────┼────┼────┼────┼────┤
            │ -  ┃ 4  │ 5  │ 6  ┃ +  │     │ m¹ │    │    │    │    │
  ┌┄┄┄┄┐    ├────┃────┼────┼────┃────┤     ├────┼────┼────┼────┼────┤
  ┆PAD ┆ ┄› │ *  ┃ 7  │ 8  │ 9  ┃ 0  │     │bck │hom │caps│cmbt│ ▓▓ │
  └┄┄┄┄┘    └────┗━━━━┷━━━━┷━━━━┛────┘     └────┴────┴────┴────┴────┘ */

  [_PAD] = LAYOUT_planck_2x2u(
    KC_COLN, KC_1,  KC_2,  KC_3,  KC_PSLS, __x__, __x__, LAG_SWP,     LAG_NRM,     KC_DOT,  __x__,   __x__,
    KC_PMNS, KC_4,  KC_5,  KC_6,  KC_PPLS, __x__, __x__, MC_SHOT,     __x__,       __x__,   __x__,   __x__,
    KC_0,    KC_7,  KC_8,  KC_9,  KC_PAST, __x__, __x__, KC_WWW_BACK, KC_WWW_HOME, KC_CAPS, CMB_TOG, __x__,
    _____,   _____, _____, _____, /**/     _____, _____, /**/         _____,       _____,   _____,   DF(_GAM)
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Function  ┏━━━━┓────┬────┌────┬────┐     ┌────┬────┏━━━━┓────┬────┐
  Mouse     ┃rset┃ f₁₁│f₁₂ │    │rgb │     │ w↑ │    ┃ ▲  ┃    │ ▓▓ │
            ┗━━━━┛ ───┼─── └────┴────┘     ├────┏━━━━┛────┗━━━━┓────┤
            │ f₁ │ f₂ │ f₃ │ f₄ │ f₅ │     │ w↓ ┃ ◀  │ ▼  │ ▶  ┃scr⁺│
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┗━━━━┷━━━━┷━━━━┛────┤
  ┆FUN ┆ ┄› │ f₆ │ f₇ │ f₈ │ f₉ │f₁₀ │     │play│vol⁻│vol⁺│next│scr⁻│
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘  ┌──└────┴────┴────┴────┴────┘
                                        │   rmb │lmb │
                                        └───────┴────┘ */
  [_FUN] = LAYOUT_planck_2x2u(
    RESET, KC_F11, KC_F12, _____, RGB_TOG, __x__, __x__,      KC_WH_U, _____,      KC_MS_U, _____,   _____,
    KC_F1, KC_F2,  KC_F3,  KC_F4, KC_F5,   __x__, __x__,      KC_WH_D, KC_MS_L,    KC_MS_D, KC_MS_R, KC_BRIU,
    KC_F6, KC_F7,  KC_F8,  KC_F9, KC_F10,  __x__, __x__,      KC_MPLY, KC_VOLD,    KC_VOLU, KC_MNXT, KC_BRID,
    _____, _____,  _____,  _____, /**/     _____, KC_MS_BTN2, /**/     KC_MS_BTN1, _____,   _____,   _____
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Gaming    ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
  mode      │ ↹  │ q  │ w  │ e  │ r  │     │ t  │ y  │ u  │ ▲  │ ⎋  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ ⇧  │ a  │ s  │ d  │ f  │     │ g  │ h  │ ◀  │ ▼  │ ▶  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ ^  │ 1  │ 2  │ 3  │ 4  │     │ 5  │ 6  │    │    │ ↵  │
  ┌┄┄┄┄┐    └────┴────┴────┼────┴────┴─────┴────┴────┼────┴────┴────┘
  ┆gam ┆ ┄› │ z  │ x  │ c  │ v  │   ␣   │  ⌘    │ b  │ n  │ m  │exit│
  └┄┄┄┄┘    └────┴────┴─── └────┴───────┴───────┴────┘ ───┴────┴──●─┘
                              press to return to the base layer ──┘ */

  [_GAM] = LAYOUT_planck_2x2u(
      KC_TAB,  KC_Q, KC_W, KC_E, KC_R, __x__,  __x__,   KC_T, KC_Y, KC_U,    KC_UP,   KC_ESC,
      KC_LSFT, KC_A, KC_S, KC_D, KC_F, __x__,  __x__,   KC_G, KC_H, KC_LEFT, KC_DOWN, KC_RGHT,
      KC_LCTL, KC_1, KC_2, KC_3, KC_4, __x__,  __x__,   KC_5, KC_6, __x__,   __x__,   KC_ENT,
      KC_Z,    KC_X, KC_C, KC_V, /**/  KC_SPC, KC_LALT, /**/  KC_B, KC_N,    KC_M,    DF(0)
  ),

  /* Reserved */
  [6] = LAYOUT_planck_2x2u(
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____
  )
}; /*

┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
Chords      ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
with space  │    │    │    │    │    │     │    │    │    │    │    │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │    │    │    │    │    │     │ ↵  │    │    │    │    │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │    │    │    │    │    │     │ ⎋  │    │    │    │    │
            └────┴────┴────┴────┴────┴─────┴────┴────┴────┴────┴────┘
Chords      ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │    │    │    │    │    │     │ m  │    │    │    │    │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ z  │ x  │ c  │ d  │ v  │     │ k  │ h  │ ,  │ .  │    │
            └────┴────┴────┴────┴────┴─────┴┆───┴┆───┴┆───┴┆───┴────┘
                                            └  / ┴  ' ┴  ; ┘
                                            ┆    ┆         ┆
                                            ┆    └┄┄┄┄┄ ⌫  ┘
                                            └┄┄┄┄┄ -  ┘
*/

enum combos { CM_0, CM_1, CM_2, CM_3, CM_4, CM_5, CM_6 };

const uint16_t PROGMEM combo_0[] = {KC_H, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_1[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_K, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_SPC, KC_K, COMBO_END};
const uint16_t PROGMEM combo_6[] = {KC_SPC, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CM_0] = COMBO(combo_0, C(KC_BSPC)),
  [CM_1] = COMBO(combo_1, KC_QUOT),
  [CM_2] = COMBO(combo_2, KC_SLSH),
  [CM_3] = COMBO(combo_3, KC_SCLN),
  [CM_4] = COMBO(combo_4, KC_MINS),
  [CM_5] = COMBO(combo_5, KC_ESC),
  [CM_6] = COMBO(combo_6, KC_ENT),
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

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_0] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LCTL),
};
