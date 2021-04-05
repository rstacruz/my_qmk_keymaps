#include QMK_KEYBOARD_H

#define _v_  KC_TRNS
#define ___  KC_NO

/* Modifier keys */
#define xx_LCMD KC_LALT
#define xx_LSFT KC_LSFT
#define xx_LOPT KC_LGUI
#define xx_SYM  MO(_SYM)
#define xx_NAV  MO(_NAV)
#define xx_ENT  LCTL_T(KC_ENT)
#define xx_Q    LCTL_T(KC_Q)

/* Tab variations */
#define xx_CTAB RCTL(KC_TAB)
#define xx_STAB RCTL(LSFT(KC_TAB))

/* Layout */
#define LAYOUT_36( \
  a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, \
  b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, \
  c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, \
  d1, d2, d3, d4, d5, d6 \
) \
  LAYOUT_planck_2x2u( \
    a1,  a2,  a3, a4, a5,  ___, ___, a6,  a7, a8, a9,  a10, \
    b1,  b2,  b3, b4, b5,  ___, ___, b6,  b7, b8, b9,  b10, \
    c1,  c2,  c3, c4, c5,  ___, ___, c6,  c7, c8, c9,  c10, \
    ___, ___, d1, d2, /**/ d3,  d4,  /**/ d5, d6, ___, ___  \
  )

/* Layers */
enum layers { _BASE = 0, _DHR, _SYM, _NAV, _FUN, _PAD, _GAM, _GMX, _LOC };

/* Macros */
enum custom_keycodes {
  MC_MUTE = SAFE_RANGE,
  MC_HAND,
  MC_SHOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Colemak   ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
  mod-DH    │ q ⌃│ w  │ f  │ p  │ b  │     │ j  │ l  │ u  │ y  │NAV⌫│
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ a  │ r  │ s  │ t  │ g  │     │ m  │ n  │ e  │ i  │ o  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ z  │ x  │ c  │ d  │ v  │     │ k  │ h  │ ,  │ .  │ ↵ ⌃│
            └────┴────┼────┴────┴────┴──┬──┴────┴────┴────┼────┴────┘
                      │ ⌘  │SYM │   ⇧   │   ␣   │NAV │ ⌥  │
                      └────┴────┴───────┴───────┴────┴────┘ */

  [0] = LAYOUT_36(
    xx_Q, KC_W, KC_F,    KC_P,   KC_B,    /**/ KC_J,   KC_L,   KC_U,    KC_Y,   LT(_NAV,KC_BSPC), 
    KC_A, KC_R, KC_S,    KC_T,   KC_G,    /**/ KC_M,   KC_N,   KC_E,    KC_I,   KC_O,
    KC_Z, KC_X, KC_C,    KC_D,   KC_V,    /**/ KC_K,   KC_H,   KC_COMM, KC_DOT, xx_ENT,
    /**/  /**/  xx_LCMD, xx_SYM, xx_LSFT, /**/ KC_SPC, xx_NAV, xx_LOPT  /**/    /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Alternate layer*/

  [_DHR] = LAYOUT_36(
  // _v_, _v_,  _v_, _v_, _v_, /**/ KC_BSPC, _v_, _v_, _v_, LT(_NAV,KC_J),
    _v_, _v_,  _v_, _v_, _v_, /**/ _v_,     _v_, _v_, _v_, _v_,
    _v_, _v_,  _v_, _v_, _v_, /**/ _v_,     _v_, _v_, _v_, _v_,
    _v_, KC_K, _v_, _v_, _v_, /**/ xx_ENT,  _v_, _v_, _v_, KC_X,
    /**/ /**/  _v_, _v_, _v_, /**/ _v_,     _v_, _v_  /**/ /**/
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

  [_SYM] = LAYOUT_36(
    KC_QUOT, KC_DQUO, KC_CIRC, KC_QUES, KC_GRV,   /**/ KC_LBRC, KC_LT,   KC_EQL,  KC_GT,   KC_RBRC,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  /**/ KC_LCBR, KC_LPRN, KC_COLN, KC_RPRN, KC_RCBR,
    KC_SCLN, KC_TILD, KC_PIPE, KC_AMPR, KC_BSLS,  /**/ KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_UNDS,
    /**/     /**/     _v_,   _v_,   MO(_NAV), /**/ _v_,   _v_,   _v_    /**/     /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Navigate  ┌────┬────┐────┬────┬────┐     ┌────┬────┏━━━━┓─── ┌────┐
            │ ⌃  │ ⌥  │ .  │    │    │     │pg↑ │home┃ ▲  ┃end │FUN │
            └────┴────┘────┼────┼────┤     ├────┏━━━━┛────┗━━━━┓────┘
            │ 1  │ 2  │ 3  │ 4  │ 5  │     │pg↓ ┃ ◀  │ ▼  │ ▶  ┃ ↵  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ┌────┗━━━━┷━━━━┷━━━━┛────┤
  ┆NAV ┆ ┄› │ 6  │ 7  │ 8  │ 9  │ 0  │     │ ⎋  │ ca │ ↹  │ cb │ ⌦  │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘──┬──└────┘────┴────┴────┴────┘
                                        │   ↵   │PAD │    │
                                        └───────┴────┴────┘ */

  [_NAV] = LAYOUT_36(
    KC_LCTL, KC_LGUI, KC_DOT, ___,  ___,  /**/ KC_PGUP, KC_HOME,  KC_UP,   KC_END,     TT(_FUN),
    KC_1,    KC_2,    KC_3,   KC_4, KC_5, /**/ KC_PGDN, KC_LEFT,  KC_DOWN, KC_RGHT,    KC_ENT,
    KC_6,    KC_7,    KC_8,   KC_9, KC_0, /**/ KC_ESC,  C(KC_A),  KC_TAB,  C(KC_BSPC), KC_DEL,
    /**/     /**/     _v_,    _v_,  _v_,  /**/ KC_ENT,  MO(_PAD), _v_      /**/        /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Function  ┏━━━━┓────┬────┬────┬────┐     ┌────┬────┏━━━━┓────┬────┐
            ┃rset┃f₁₁ │f₁₂ │rmb │lmb │     │ w↑ │ S↹ ┃ ▲  ┃^ ↹ │ ▓▓ │
            ┗━━━━┛────┼────┼────┼────┤     ├────┏━━━━┛────┗━━━━┓────┤
            │ f₁ │ f₂ │ f₃ │ f₄ │ f₅ │     │ w↓ ┃ ◀  │ ▼  │ ▶  ┃scr⁺│
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┗━━━━┷━━━━┷━━━━┛────┤
  ┆FUN ┆ ┄› │ f₆ │ f₇ │ f₈ │ f₉ │f₁₀ │     │vol⁻│vol⁺│play│next│scr⁻│
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘──┬──└────┴────┴────┴────┴────┘
                           │    │       │  lmb  │    │    │
                           └────┴───────┴───────┴────┴────┘ */

  [_FUN] = LAYOUT_36(
    RESET, KC_F11, KC_F12, KC_MS_BTN2, KC_MS_BTN1, /**/ KC_WH_U,    xx_STAB, KC_MS_U, xx_CTAB, TG(_FUN),
    KC_F1, KC_F2,  KC_F3,  KC_F4,      KC_F5,      /**/ KC_WH_D,    KC_MS_L, KC_MS_D, KC_MS_R, KC_BRIU,
    KC_F6, KC_F7,  KC_F8,  KC_F9,      KC_F10,     /**/ KC_VOLD,    KC_VOLU, KC_MPLY, KC_MNXT, KC_BRID,
    /**/   /**/    _v_,    _v_,        _v_,        /**/ KC_MS_BTN1, _v_,     _v_      /**/     /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Macros    ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │DHR │    │    │    │    │     │ m  │ m  │    │    │    │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │GAM │    │    │    │    │     │ m  │f₁₃ │f₁₄ │f₁₅ │f₁₆ │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
  ┆PAD ┆ ┄› │LOC │cmbt│caps│home│    │     │    │f₁₇ │f₁₈ │f₁₉ │f₂₀ │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘──┬──└────┴────┴────┴────┴────┘
                           │    │       │       │ ▓▓ │    │
                           └────┴───────┴───────┴────┴────┘ */

  [_PAD] = LAYOUT_36(
    TG(_DHR), ___,     ___,     ___,         ___, /**/ MC_MUTE, MC_HAND, ___,    ___,    ___,
    DF(_GAM), ___,     ___,     ___,         ___, /**/ MC_SHOT, KC_F13,  KC_F14, KC_F15, KC_F16,
    DF(_LOC), CMB_TOG, KC_CAPS, KC_WWW_HOME, ___, /**/ ___,     KC_F17,  KC_F18, KC_F19, KC_F20,
    /**/      /**/     _v_,     _v_,         _v_, /**/ _v_,     _v_,     _v_     /**/    /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Gaming    ┌─── ┌────┬────┬────┬────┐     ┌────┬────┐ ───┬────┬────┐
  mode      │ ↹  │ q  │ w  │ e  │ r  │     │ 1  │ 4  │ t  │ y  │ ⎋  │
            ├─── ├────┼────┼────┼────┤     ├────┼────┤ ── ┌────┐ ───┤
            │ ⇧  │ a  │ s  │ d  │ f  │     │ 2  │ 5  │ g  │ ▲  │ ↵  │
  ┌┄┄┄┄┐    ├─── ├────┼────┼────┼────┤     ├────┼────┤ ───┼────┼────┐
  ┆gam ┆ ┄› │ ⌃  │ z  │ x  │ c  │ v  │     │ 3  │ 6  │ ◀  │ ▼  │ ▶  │
  └┄┄┄┄┘    └─── └────┴────┴────┴────┴──┬──┴────┴────┘ ───┴────┴────┘
                      │ GX │ b  │   ␣   │  ⌃    │ GX │exit│
                      └────┴────┴───────┴───────┴────┴──●─┘
                             return to the base layer ──┘
  Game+     ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │    │    │    │    │    │     │ t  │ y  │ u  │ i  │ o  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │    │ 1  │ 2  │ 3  │ 4  │     │ g  │ h  │ j  │ k  │ l  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │    │ 5  │ 6  │ 7  │ 8  │     │ n  │ m  │ ,  │ .  │ p  │
            └────┴────┴────┴────┴────┴─────┴────┴────┴────┴────┴────┘ */

  [_GAM] = LAYOUT_36(
    KC_TAB,  KC_Q, KC_W,      KC_E, KC_R,   /**/ KC_1,    KC_4,      KC_T,    KC_Y,    KC_ESC,
    KC_LSFT, KC_A, KC_S,      KC_D, KC_F,   /**/ KC_2,    KC_5,      KC_J,    KC_UP,   KC_ENT,
    KC_LCTL, KC_Z, KC_X,      KC_C, KC_V,   /**/ KC_3,    KC_6,      KC_LEFT, KC_DOWN, KC_RGHT,
    /**/     /**/  OSL(_GMX), KC_B, KC_SPC, /**/ KC_LCTL, OSL(_GMX), DF(0)    /**/     /**/
  ),

  [_GMX] = LAYOUT_36(
    _v_, _v_,  _v_,  _v_,  _v_,  /**/ KC_T, KC_Y, KC_U,    KC_I,   KC_O,
    _v_, KC_1, KC_2, KC_3, KC_4, /**/ KC_G, KC_H, KC_J,    KC_K,   KC_L,
    _v_, KC_5, KC_6, KC_7, KC_8, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_P,
    /**/ /**/  _v_,  _v_,  _v_,  /**/ _v_,  _v_,  _v_      /**/    /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Blank     ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │    │    │    │    │    │     │    │    │    │    │    │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │    │    │    │    │    │     │    │    │    │    │    │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │    │    │    │    │    │     │    │    │    │    │    │
            └────┴────┴────┴────┴────┴─────┴────┴────┴────┴────┴────┘ */

  [_LOC] = LAYOUT_planck_2x2u(
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,   ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,   ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,   ___, ___,
    ___, ___, ___, ___, /**/ ___, ___, /**/ ___, DF(0), ___, ___
  )
}; /*

┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
Chords      ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │    │    │    │    │    │     │ k  │ h  │ ,  │ .  │    │
            └────┴────┴────┴────┴────┴─────┴────┴────┴────┴────┴────┘
                                             └ ↵  ┄└ ' ┄└ - ┄┘
                                                   └┄┄┄ c-a ┄┘
Chords      ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
with space  │    │    │    │    │    │     │ ⎋  │    │    │ ⌫  │    │
            └────┴────┴────┴────┴────┴─────┴────┴────┴────┴────┴────┘
*/

enum combos { CM_0, CM_1, CM_2, CM_3, CM_4, CM_5, CM_6, CM_7, CM_8, CM_9, CM_10, CM_11, CM_12 };

const uint16_t PROGMEM combo_0[] = {KC_H, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_1[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_SPC, KC_K, COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_SPC, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CM_0] = COMBO(combo_0, C(KC_A)), // x
  [CM_1] = COMBO(combo_1, KC_QUOT), // x
  [CM_2] = COMBO(combo_2, KC_ENT),
  [CM_3] = COMBO(combo_3, KC_MINS), // x
  [CM_4] = COMBO(combo_4, KC_ESC),
  [CM_5] = COMBO(combo_5, C(KC_BSPC)),
};

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case xx_Q:
      return true;
    default:
      return false;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case xx_Q:
      return TAPPING_TERM_LONG;
    default:
      return TAPPING_TERM;
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
