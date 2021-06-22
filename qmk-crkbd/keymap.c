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

#ifdef ARTSEY_ENABLED
#define ART_TOG TG(_AR_BAS)
#else
#define ART_TOG KC_TRNS
#endif

/* Layers */
enum layers {
  _BASE = 0, _ALT, _SYM, _NAV, _ANV, _FUN, _PAD, _GAM, _GMX, _LOC
#ifdef ARTSEY_ENABLED
  , _AR_BAS, _AR_NAV, _AR_NUM
#endif
};

/* Macros */
enum custom_keycodes {
  MC_MUTE = SAFE_RANGE,
  MC_HAND,
  MC_SHOT
#ifdef ARTSEY_ENABLED
  , ART_A, ART_R, ART_T, ART_S, ART_E, ART_Y, ART_I, ART_O
#endif
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Colemak   ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
  mod-DH    │ q ⌃│ w  │ f  │ p  │ b  │     │ j  │ l  │ u  │ y  │ ⌫  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ a  │ r  │ s  │ t  │ g  │     │ m  │ n  │ e  │ i  │ o  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ z  │ x  │ c  │ d  │ v  │     │ k  │ h  │ ,  │ .  │ ↵ ⌃│
            └────┴────┼────┴────┴────┴──┬──┴────┴────┴────┼────┴────┘
                      │ ⌘  │SYM │   ⇧   │   ␣   │NAV │ ⌥  │
                      └────┴────┴───────┴───────┴────┴────┘ */

  [0] = LAYOUT_36(
    x__Q, KC_W, KC_F,    KC_P,   KC_B,    /**/ KC_J,   KC_L,   KC_U,    KC_Y,   KC_BSPC,
    KC_A, KC_R, KC_S,    KC_T,   KC_G,    /**/ KC_M,   KC_N,   KC_E,    KC_I,   KC_O,
    KC_Z, KC_X, KC_C,    KC_D,   KC_V,    /**/ KC_K,   KC_H,   KC_COMM, KC_DOT, x__ENT,
    /**/  /**/  x__LCMD, x__SYM, x__LSFT, /**/ KC_SPC, x__NAV, x__LOPT  /**/    /**/
  ),
  /*
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
  ),
  /*
  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Symbols   ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │ '  │ "  │ ^  │ ?  │ `  │ quo │ [  │ <  │ =  │ >  │ ]  │ brace
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ !  │ @  │ #  │ $  │ %  │ 123 │ {  │ (  │ :  │ )  │ }  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
  ┆SYM ┆ ┄› │ \  │ ~  │ |  │ &  │ ;  │ etc │ /  │ *  │ -  │ +  │ _  │ math
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘──┬──└────┴────┴────┴────┴────┘
                      │    │ ▓▓ │ ANV   │       │FUN │    │
                      └────┴────┴───────┴───────┴────┴────┘ */

  [_SYM] = LAYOUT_36(
    KC_QUOT, KC_DQUO, KC_CIRC, KC_QUES, KC_GRV,   /**/ KC_LBRC, KC_LT,    KC_EQL,  KC_GT,   KC_RBRC,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  /**/ KC_LCBR, KC_LPRN,  KC_COLN, KC_RPRN, KC_RCBR,
    KC_BSLS, KC_TILD, KC_PIPE, KC_AMPR, KC_SCLN,  /**/ KC_PSLS, KC_PAST,  KC_PMNS, KC_PPLS, KC_UNDS,
    /**/     /**/     _v_,     _v_,     MO(_ANV), /**/ _v_,     MO(_FUN), _v_      /**/     /**/
  ),
  /*
  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Navigate  ┌────┬────┐┄───┬────┬────┐     ┌────┬───┄┏━━━━┓┄───┬────┐
            │ ⌃  │ ⌥  │    │ ↹  │ART │     │pg↑ │home┃ ▲  ┃end │ ^⌫ │
            └────┴────┘┄───┼────┼────┤     ├───┄┏━━━━┛────┗━━━━┓┄───┤
            │ 1  │ 2  │ 3  │ 4  │ 5  │     │pg↓ ┃ ◀  │ ▼  │ ▶  ┃ ↵  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├───┄┗━━━━┷━━━━┷━━━━┛┄───┤
  ┆NAV ┆ ┄› │ 6  │ 7  │ 8  │ 9  │ 0  │     │ ⎋  │ ‹‹ │ ›› │ .  │ ⌦  │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘──┬──└───┄└────┴────┴────┘┄───┘
                      │    │PAD │       │       │ ▓▓ │    │
                      └────┴────┴───────┴───────┴────┴────┘ */

  [_NAV] = LAYOUT_36(
    KC_LCTL, KC_LGUI, KC_TAB, KC_TAB,   ART_TOG, /**/ KC_PGUP, KC_HOME, KC_UP,   KC_END,  x__CBSP,
    KC_1,    KC_2,    KC_3,   KC_4,     KC_5,       /**/ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
    KC_6,    KC_7,    KC_8,   KC_9,     KC_0,       /**/ KC_ESC,  x__STAB, x__CTAB, KC_DOT,  KC_DEL,
    /**/     /**/     _v_,    MO(_PAD), _v_,        /**/ _v_,     _v_,     _v_ /**/     /**/
  ),
  /*
  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Altnav    ┌────┬───┄┏━━━━┓┄───┬────┐     ┌────┬───┄┏━━━━┓┄───┬────┐
            │exit│home┃ ▲  ┃end │pg↑ │     │pg↑ │home┃ ▲  ┃end │ ^⌫ │
            ├───┄┏━━━━┛────┗━━━━┓┄───┤     ├───┄┏━━━━┛────┗━━━━┓┄───┤
            │    ┃ ◀  │ ▼  │ ▶  ┃pg↓ │     │pg↓ ┃ ◀  │ ▼  │ ▶  ┃ ↵  │
  ┌┄┄┄┄┐    ├───┄┗━━━━┷━━━━┷━━━━┛┄───┤     ├───┄┗━━━━┷━━━━┷━━━━┛┄───┤
  ┆ANV ┆ ┄› │    │    │    │ ‹‹ │ ›› │     │ ⎋  │ ‹‹ │ ›› │ .  │ ⌦  │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┘──┬──└───┄└────┴────┴────┘┄───┘
                      │    │    │ ▓▓    │       │    │    │
                      └────┴────┴───────┴───────┴────┴────┘ */

  [_ANV] = LAYOUT_36(
    ___, KC_HOME, KC_UP,   KC_END,  KC_PGUP,    /**/ KC_PGUP, KC_HOME, KC_UP,   KC_END,  x__CBSP,
    ___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,    /**/ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
    ___, ___,     ___,     x__STAB, x__CTAB,    /**/ KC_ESC,  x__STAB, x__CTAB, KC_DOT,  KC_DEL,
    /**/ /**/     ___,     ___,     KC_MS_BTN1, /**/ _v_,     _v_,     _v_      /**/     /**/
  ),

#ifdef ARTSEY_ENABLED
  [_AR_BAS] = LAYOUT_36(
    ART_S, ART_T, ART_R, ART_A,       MO(_AR_NUM),         /**/ ___, ___, ___,        ___, ___,
    ART_O, ART_I, ART_Y, ART_E,       ___,                 /**/ ___, ___, ___,        ___, ___,
    ___,   ___,   ___,   ___,         ___,                 /**/ ___, ___, ___,        ___, ___,
    /**/   /**/   ___,   MO(_AR_NAV), MT(MOD_LSFT,KC_SPC), /**/ ___, ___, TG(_AR_BAS) /**/ /**/
  ),
  [_AR_NAV] = LAYOUT_36(
    ___, KC_HOME, KC_UP,   KC_END,  KC_PGUP, /**/ ___, ___, ___, ___, ___,
    ___, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, /**/ ___, ___, ___, ___, ___,
    ___, ___,     ___,     x__STAB, x__CTAB, /**/ ___, ___, ___, ___, ___,
    /**/ /**/     ___,     ___,     ___,     /**/ ___, ___, ___  /**/ /**/
  ),
  [_AR_NUM] = LAYOUT_36(
    KC_1, KC_2, KC_3, KC_4, ___, /**/ ___, ___, ___, ___, ___,
    KC_5, KC_6, KC_7, KC_8, ___, /**/ ___, ___, ___, ___, ___,
    KC_9, KC_0, ___,  ___,  ___, /**/ ___, ___, ___, ___, ___,
    /**/  /**/  ___,  ___,  ___, /**/ ___, ___, ___  /**/ /**/
  ),
#endif
  /*
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

  [_FUN]     = LAYOUT_36(
    KC_F9,   KC_F10, KC_F11, KC_F12, KC_MS_BTN2, /**/ KC_WH_U, x__STAB,  KC_MS_U, x__CTAB, KC_BRIU,
    KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_MS_BTN1, /**/ KC_WH_D, KC_MS_L,  KC_MS_D, KC_MS_R, KC_BRID,
    KC_F5,   KC_F6,  KC_F7,  KC_F8,  KC_MS_BTN3, /**/ KC_VOLD, KC_VOLU,  KC_MPLY, KC_MNXT, RESET,
    /**/     /**/    _v_,    _v_,    _v_,        /**/ _v_,     _v_,      _v_      /**/     /**/
  ),         /*

  ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Numpad    ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┐┄───┬────┐
            │    │    │    │    │    │     │ 1  │ 2  │ 3  │ ⌘  │ ⌫  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┤┄───┼────┤
            │rgbT│ h+ │ s+ │ v+ │    │     │ 4  │ 5  │ 6  │ ⌥  │ ^  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┤┄───┼────┤
  ┆PAD ┆›   │rgbM│ h- │ s- │ v- │    │     │ 7  │ 8  │ 9  │    │ mS │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┴─────┴────┴────┴────┘┄───┴────┘
                      │    │ ▓▓ │       │    0  │spc │ .  │
                      └────┴────┴───────┴───────┴────┴────┘ */

  [_PAD]     = LAYOUT_36(
    ___,     ___,     ___,     ___,     ___, /**/ KC_1, KC_2,   KC_3,  x__LCMD, KC_BSPC,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, ___, /**/ KC_4, KC_5,   KC_6,  x__LOPT, KC_LCTL,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, ___, /**/ KC_7, KC_8,   KC_9,  ___,     MC_SHOT,
    /**/     /**/     _v_,     _v_,     _v_, /**/ KC_0, KC_SPC, KC_DOT /**/     /**/
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
};
/* ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄ */

#ifdef ARTSEY_ENABLED
#ifdef COMBO_TERM
enum combos { CM_J, CM_N, CM_F, CM_C };

const uint16_t PROGMEM combo_J[] = {ART_T, ART_S, COMBO_END};
const uint16_t PROGMEM combo_N[] = {ART_I, ART_O, COMBO_END};
const uint16_t PROGMEM combo_F[] = {ART_A, ART_R, COMBO_END};
const uint16_t PROGMEM combo_C[] = {ART_E, ART_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CM_J] = COMBO(combo_J, KC_J),
  [CM_N] = COMBO(combo_N, KC_N),
  [CM_F] = COMBO(combo_F, KC_F),
  [CM_C] = COMBO(combo_C, KC_C),
};
#endif
#endif

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case x__Q:
      return true;
    default:
      return false;
  }
}

#define ART_PRESS_KEY(KEY) \
  if (record->event.pressed) { add_key(KEY); send_keyboard_report(); } \
  else { del_key(KEY); send_keyboard_report(); }

// Macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MC_MUTE: // Zoom: mute or unmute
    if (record->event.pressed) { SEND_STRING(SS_LSFT(SS_LALT("a"))); }
    break;
  case MC_HAND: // Zoom: raise hand
    if (record->event.pressed) { SEND_STRING(SS_LSFT(SS_LALT("y"))); }
    break;
  case MC_SHOT: // MacOS: take screenshot
    if (record->event.pressed) { SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT("4")))); }
    break;
#ifdef ARTSEY_ENABLED
  case ART_A: ART_PRESS_KEY(KC_A) break;
  case ART_R: ART_PRESS_KEY(KC_R) break;
  case ART_T: ART_PRESS_KEY(KC_T) break;
  case ART_S: ART_PRESS_KEY(KC_S) break;
  case ART_E: ART_PRESS_KEY(KC_E) break;
  case ART_Y: ART_PRESS_KEY(KC_Y) break;
  case ART_I: ART_PRESS_KEY(KC_I) break;
  case ART_O: ART_PRESS_KEY(KC_O) break;
#endif
  }
  return true;
};
