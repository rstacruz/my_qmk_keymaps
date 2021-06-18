#include QMK_KEYBOARD_H

#define _v_  KC_TRNS
#define ___  KC_NO

/* Modifier keys */
#define x__LCMD KC_LALT
#define x__LSFT KC_LSFT
#define x__LOPT KC_LGUI
#define x__OTAB MT(MOD_LGUI,KC_TAB) /* opt/gui | tab */
#define x__CESC MT(MOD_LALT,KC_ESC) /* cmd/alt | esc */
#define x__SYM  MO(_SYM)
#define x__NAV  MO(_NAV)
#define x__ENT  LCTL_T(KC_ENT)  /* ctrl | enter */
#define x__Q    LCTL_T(KC_Q)    /* ctrl | q */
#define x__CBSP C(KC_BSPC) /* Delete word */

/* Tab variations */
#define x__CTAB RCTL(KC_TAB)
#define x__STAB RCTL(LSFT(KC_TAB))

#define H(KEY) S(G(KEY))

/* Layers */
enum layers { _BASE = 0, _ALT, _SYM, _NAV, _FUN, _PAD, _GAM, _GMX, _LOC };

/* Macros */
enum custom_keycodes {
  MC_MUTE = SAFE_RANGE,
  MC_HAND,
  MC_SHOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Colemak   ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
  mod-DH    │ q ⌃│ w  │ f  │ p  │ b  │     │ j  │ l  │ u  │ y  │ ⌫  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ a  │ r  │ s  │ t  │ g  │     │ m  │ n  │ e  │ i  │ o  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ z  │ x  │ c  │ d  │ v  │     │ k  │ h  │ ,  │ .  │ ↵ ⌃│
            └────┴────┼────┴────┴────┴──┬──┴────┴────┴────┼────┴────┘
                      │ ⌘  │SYM │   ⇧   │   ␣   │NAV │ ⌥  │
                      └────┴────┴───────┴───────┴────┴────┘ 
*/

  [0] = LAYOUT_36(
    x__Q, KC_W, KC_F,    KC_P,   KC_B,    /**/ KC_J,   KC_L,   KC_U,    KC_Y,   KC_BSPC,
    KC_A, KC_R, KC_S,    KC_T,   KC_G,    /**/ KC_M,   KC_N,   KC_E,    KC_I,   KC_O,
    KC_Z, KC_X, KC_C,    KC_D,   KC_V,    /**/ KC_K,   KC_H,   KC_COMM, KC_DOT, x__ENT,
    /**/  /**/  x__LCMD, x__SYM, x__LSFT, /**/ KC_SPC, x__NAV, x__LOPT  /**/    /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Alternate ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
  layer     │ q ⌃│ w  │ e  │ r  │ t  │     │ y  │ u  │ i  │ o  │ p  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ a  │ s  │ d  │ f  │ g  │     │ h  │ j  │ k  │ l  │ ⌫  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ z  │ x  │ c  │ v  │ b  │     │ n  │ m  │ ,  │ .  │ ↵ ⌃│
            └────┴────┼────┴────┴────┴──┬──┴────┴────┴────┼────┴────┘
                      │ ⌘  │SYM │   ⇧   │   ␣   │NAV │ ⌥  │
                      └────┴────┴───────┴───────┴────┴────┘ */

  [_ALT] = LAYOUT_36(
    x__Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, KC_J, KC_K,    KC_L,   KC_BSPC,
    KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, x__ENT,
    /**/  /**/  _v_,  _v_,  _v_,  /**/ _v_,  _v_,  _v_      /**/    /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Symbols   ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │ '  │ "  │ ^  │ ?  │ `  │ quo │ [  │ <  │ =  │ >  │ ]  │ brace
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ !  │ @  │ #  │ $  │ %  │ 123 │ {  │ (  │ :  │ )  │ }  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
  ┆SYM ┆ ┄› │ \  │ ~  │ |  │ &  │ ;  │ etc │ /  │ *  │ -  │ +  │ _  │ math
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘──┬──└────┴────┴────┴────┴────┘
                      │    │ ▓▓ │ NAV   │       │FUN │    │
                      └────┴────┴───────┴───────┴────┴────┘ */

  [_SYM] = LAYOUT_36(
    KC_QUOT, KC_DQUO, KC_CIRC, KC_QUES, KC_GRV,   /**/ KC_LBRC, KC_LT,    KC_EQL,  KC_GT,   KC_RBRC,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  /**/ KC_LCBR, KC_LPRN,  KC_COLN, KC_RPRN, KC_RCBR,
    KC_BSLS, KC_TILD, KC_PIPE, KC_AMPR, KC_SCLN,  /**/ KC_PSLS, KC_PAST,  KC_PMNS, KC_PPLS, KC_UNDS,
    /**/     /**/     _v_,     _v_,     MO(_NAV), /**/ _v_,     MO(_FUN), _v_      /**/     /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Navigate  ┌────┬────┐┄───┬────┬────┐     ┌────┬───┄┏━━━━┓┄───┬────┐
            │ ⌃  │ ⌥  │    │ ↹  │    │     │pg↑ │home┃ ▲  ┃end │ ^⌫ │
            └────┴────┘┄───┼────┼────┤     ├───┄┏━━━━┛────┗━━━━┓┄───┤
            │ 1  │ 2  │ 3  │ 4  │ 5  │     │pg↓ ┃ ◀  │ ▼  │ ▶  ┃ ↵  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├───┄┗━━━━┷━━━━┷━━━━┛┄───┤
  ┆NAV ┆ ┄› │ 6  │ 7  │ 8  │ 9  │ 0  │     │ ⎋  │ ⇧↹ │ .  │ ⇥  │ ⌦  │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘──┬──└───┄└────┴────┴────┘┄───┘
                      │    │PAD │       │       │ ▓▓ │    │
                      └────┴────┴───────┴───────┴────┴────┘ */

  [_NAV] = LAYOUT_36(
    KC_LCTL, KC_LGUI, KC_TAB, KC_TAB,   KC_MS_BTN1, /**/ KC_PGUP, KC_HOME, KC_UP,   KC_END,  x__CBSP,
    KC_1,    KC_2,    KC_3,   KC_4,     KC_5,       /**/ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
    KC_6,    KC_7,    KC_8,   KC_9,     KC_0,       /**/ KC_ESC,  x__STAB, KC_DOT,  x__CTAB, KC_DEL,
    /**/     /**/     _v_,    MO(_PAD), _v_,        /**/ _v_,     _v_,     _v_      /**/     /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Function  ┌────┬────┬────┬───┄┏━━━━┓     ┌────┬───┄┏━━━━┓┄───┬────┐
            │ f9 │f10 │f11 │f12 ┃rmb ┃     │ w↑ │ ⇧↹ ┃ ▲  ┃ ⇥  │scr+│
            ├────┼────┼────┼───┄┣━━━━┫     ├───┄┏━━━━┛────┗━━━━┓┄───┤
            │ f1 │ f2 │ f3 │ f4 ┃lmb ┃     │ w↓ ┃ ◀  │ ▼  │ ▶  ┃scr-│
  ┌┄┄┄┄┐    ├────┼────┼────┼───┄┣━━━━┫     ├───┄┗━━━━┷━━━━┷━━━━┛┄───┤
  ┆FUN ┆ ┄› │ f5 │ f6 │ f7 │ f8 ┃mmb ┃     │vol-│vol+│play│next│rset│
  └┄┄┄┄┘    └────┴────┴────┴───┄┗━━━━┛──┬──└────┴────┴────┴────┴────┘
                      │    │ ░░ │       │       │ ▓▓ │    │
                      └────┴────┴───────┴───────┴────┴────┘ */

  [_FUN] = LAYOUT_36(
    KC_F9, KC_F10, KC_F11, KC_F12, KC_MS_BTN2, /**/ KC_WH_U, x__STAB,  KC_MS_U, x__CTAB, KC_BRIU,
    KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_MS_BTN1, /**/ KC_WH_D, KC_MS_L,  KC_MS_D, KC_MS_R, KC_BRID,
    KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_MS_BTN3, /**/ KC_VOLD, KC_VOLU,  KC_MPLY, KC_MNXT, RESET,
    /**/   /**/    _v_,    _v_,    _v_,        /**/ _v_,     _v_,      _v_      /**/     /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Numpad    ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┐┄───┬────┐
            │    │    │ f  │    │ b  │     │ 1  │ 2  │ 3  │ ⌘  │ ⌫  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┤┄───┼────┤
            │ a  │    │ e  │    │    │     │ 4  │ 5  │ 6  │ ⌥  │ ^  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┤┄───┼────┤
  ┆PAD ┆›   │ mS │    │ c  │ d  │    │     │ 7  │ 8  │ 9  │    │    │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┴─────┴────┴────┴────┘┄───┴────┘
                      │    │ ▓▓ │       │    0  │spc │ .  │
                      └────┴────┴───────┴───────┴────┴────┘ */

  [_PAD] = LAYOUT_36(
    ___,     ___, KC_F, ___,  KC_B, /**/ KC_1, KC_2,   KC_3,  x__LCMD, KC_BSPC,
    KC_A,    ___, KC_E, ___,  ___,  /**/ KC_4, KC_5,   KC_6,  x__LOPT, KC_LCTL,
    MC_SHOT, ___, KC_C, KC_D, ___,  /**/ KC_7, KC_8,   KC_9,  ___,     ___,
    /**/     /**/ _v_,  _v_,  _v_,  /**/ KC_0, KC_SPC, KC_DOT /**/     /**/
  ), /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Gaming    ┌───┄┌────┬────┬────┬────┐     ┌────┬────┐┄───┬────┬────┐
  mode      │ ↹  │ q  │ w  │ e  │ r  │     │ 1  │ 4  │ t  │ y  │ ⎋  │
            ├───┄├────┼────┼────┼────┤     ├────┼────┤┄──┄┌────┐┄───┤
            │ ⇧  │ a  │ s  │ d  │ f  │     │ 2  │ 5  │ g  │ ▲  │ ↵  │
  ┌┄┄┄┄┐    ├───┄├────┼────┼────┼────┤     ├────┼────┼────┼────┼────┐
  ┆gam ┆ ┄› │ ⌃  │ z  │ x  │ c  │ v  │     │ 3  │ 6  │ ◀  │ ▼  │ ▶  │
  └┄┄┄┄┘    └───┄└────┴────┴────┴────┴──┬──┴────┴────┴────┴────┴────┘
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

  [_LOC] = LAYOUT_36(
    ___, ___, ___, ___, ___, ___, ___, ___,  ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___,  ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___,  ___, ___,
    /**/ /**/ ___, ___, ___, ___, ___, DF(0) /**/ /**/
  )
}; /*

┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
                                                  ┌┄┄┄┄┄┄ ⎋ ┄┐
Chords                                      ┌┄⎋ ┄┐┌┄↵  ┐┌┄'  ┐
            ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │    │    │    │    │    │     │ k  │ h  │ ,  │ .  │    │
            └────┴────┴────┴────┴────┴─────┴────┴────┴────┴────┴────┘
*/

enum combos { CM_0, CM_1, CM_2, CM_3, CM_4, CM_5, CM_6, CM_7, CM_8, CM_9, CM_10, CM_11, CM_12 };

const uint16_t PROGMEM combo_0[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_1[] = {KC_H, KC_K, COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_H, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CM_0] = COMBO(combo_0, KC_ENT),
  [CM_1] = COMBO(combo_1, KC_ESC),
  [CM_2] = COMBO(combo_2, KC_QUOT),
  [CM_3] = COMBO(combo_3, x__CBSP),
};

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case x__Q:
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
