#include QMK_KEYBOARD_H

// ┎──────────────────────────────────────────────────────────────────────
// ┃ Keycode aliases ∴
// ┖──┄

#define _v_     KC_TRNS
#define ___     KC_NO
#define x__LCMD KC_LALT            /* cmd(mac) or alt(win) */
#define x__LOPT KC_LGUI            /* opt(mac) or gui(win) */
#define x__ENT  LCTL_T(KC_ENT)     /* ctrl(hold) or enter(tap) */
#define x__Q    LCTL_T(KC_Q)       /* ctrl(hold) or q(tap) */
#define x__CBSP C(KC_BSPC)         /* Delete word */
#define x__LMB  KC_MS_BTN1         /* Left mouse button */
#define x__RMB  KC_MS_BTN2         /* Right mouse button */
#define x__MMB  KC_MS_BTN3         /* Mid mouse button */
#define x__CTAB RCTL(KC_TAB)       /* Next tab */
#define x__STAB RCTL(LSFT(KC_TAB)) /* Previous tab */
#define H(KEY)  S(G(KEY))          /* kinda-hyper */

/* Macros and stuff */
enum custom_keycodes {
  MC_MUTE = SAFE_RANGE,
  MC_HAND,
  MC_SHOT,
  x__COMU,
  x__DOTQ,
  GAM_ON,
  GAM_OFF,
  HM_ON, HM_OFF,
  os_LCTL, os_LALT, os_LGUI, os_LSFT
};

// ┎──────────────────────────────────────────────────────────────────────
// ┖─┒ Layers ∴
//   ┖──┄

enum layers {
  _BASE = 0, _ALT, _SYM, _NAV, _FUN, _PAD, _GAM, _GMX, _LOC,
  HM_BASE, HM_FLIP, HM_NAV, HM_NUM, HM_SYM1, HM_SYM2
};

#include "halfmak.c"
#include "game_layers.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* ┎─────────────────────────────────────────────────────────────┄
     ┃ Colemak DH ∴
     ┖───── ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
            │ q ⌃│ w  │ f  │ p  │ b  │     │ j  │ l  │ u  │ y  │ ⌫  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ a  │ r  │ s  │ t  │ g  │     │ m  │ n  │ e  │ i  │ o  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ z  │ x  │ c  │ d  │ v  │     │ k  │ h  │ ,_ │ .? │ ↵ ⌃│
            ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
                      │ ⌘  │SYM │ ⇧    │ │   ␣  │NAV │ ⌥  │
                      ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [0] = LAYOUT_36(
    x__Q, KC_W, KC_F,    KC_P,     KC_B,    /**/ KC_J,   KC_L,     KC_U,    KC_Y,    KC_BSPC,
    KC_A, KC_R, KC_S,    KC_T,     KC_G,    /**/ KC_M,   KC_N,     KC_E,    KC_I,    KC_O,
    KC_Z, KC_X, KC_C,    KC_D,     KC_V,    /**/ KC_K,   KC_H,     x__COMU, x__DOTQ, x__ENT,
    /**/  /**/  x__LCMD, MO(_SYM), KC_LSFT, /**/ KC_SPC, MO(_NAV), x__LOPT  /**/     /**/
  ),

  /* ┎─────────────────────────────────────────────────────────────┄
     ┃ Qwerty ∴
     ┖───── ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │ q ⌃│ w  │ e  │ r  │ t  │     │ y  │ u  │ i  │ o  │ p  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ a  │ s  │ d  │ f  │ g  │     │ h  │ j  │ k  │ l  │ ⌫  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ z  │ x  │ c  │ v  │ b  │     │ n  │ m  │ ,  │ .  │ ↵ ⌃│
            └────┴────┴────┴────┴────┴─┐ ┌─┴────┴────┴────┴────┴────┘
                      │ ⌘  │SYM │ ⇧    │ │   ␣  │NAV │ ⌥  │
                      └────┴────┴──────┘ └──────┴────┴────┘ */

  [_ALT] = LAYOUT_36(
    x__Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, KC_J, KC_K,    KC_L,   KC_BSPC,
    KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, x__ENT,
    /**/  /**/  _v_,  _v_,  _v_,  /**/ _v_,  _v_,  _v_      /**/    /**/
  ),

  /* ┎─────────────────────────────────────────────────────────────┄
     ┃ Symbols ∴
     ┖───── ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │ '  │ "  │ ^  │ ?  │ `  │     │ [  │ <  │ =  │ >  │ ]  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ !  │ @  │ #  │ $  │ %  │     │ {  │ (  │ :  │ )  │ }  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
  ┆SYM ┆ ┄› │ \  │ ~  │ |  │ &  │ ;  │     │ /  │ *  │ -  │ +  │ _  │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┴─┐ ┌─┴────┴────┴────┴────┴────┘
                      │    │ ▓▓ │ 1h   │ │      │FUN │    │
                      └────┴────┴──────┘ └──────┴────┴────┘ */

  [_SYM] = LAYOUT_36(
    KC_QUOT, KC_DQUO, KC_CIRC, KC_QUES, KC_GRV,   /**/ KC_LBRC, KC_LT,    KC_EQL,  KC_GT,   KC_RBRC,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  /**/ KC_LCBR, KC_LPRN,  KC_COLN, KC_RPRN, KC_RCBR,
    KC_BSLS, KC_TILD, KC_PIPE, KC_AMPR, KC_SCLN,  /**/ KC_SLSH, KC_ASTR,  KC_MINS, KC_PLUS, KC_UNDS,
    /**/     /**/     _v_,     _v_,     HM_ON,    /**/ _v_,     MO(_FUN), _v_      /**/     /**/
  ),

  /* ┎─────────────────────────────────────────────────────────────┄
     ┃ Navigate ∴
     ┖───── ┌────┬────┬────┬────┬────┐     ┏━━━━┯━━━━┯━━━━┯━━━━┓┄───┐
            │ ⌃  │ ⌥  │ ⇧↹ │ ↹  │    │     ┃pg↑ │home│ ▲  │end ┃ ^⌫ │
            ├────┼────┼────┼────┼────┤     ┠────┼────┼────┼────┨┄───┤
            │ 1  │ 2  │ 3  │ 4  │ 5  │     ┃pg↓ │ ◀  │ ▼  │ ▶  ┃ ↵  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ┗━━━━┷━━━━┷━━━━┷━━━━┛┄───┤
  ┆NAV ┆ ┄› │ 6  │ 7  │ 8  │ 9  │ 0  │     │ ⎋  │ ‹‹ │ ›› │ .  │ ⌦  │
  └┄┄┄┄┘    └────┴────┴────┴────┴────┴─┐ ┌─┴────┴────┴────┴────┴────┘
                      │    │PAD │      │ │      │ ▓▓ │    │
                      └────┴────┴──────┘ └──────┴────┴────┘ */

  [_NAV] = LAYOUT_36(
    KC_LCTL, KC_LGUI, S(KC_TAB), KC_TAB,   _v_,  /**/ KC_PGUP, KC_HOME, KC_UP,   KC_END,  x__CBSP,
    KC_1,    KC_2,    KC_3,      KC_4,     KC_5, /**/ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
    KC_6,    KC_7,    KC_8,      KC_9,     KC_0, /**/ KC_ESC,  x__STAB, x__CTAB, KC_DOT,  KC_DEL,
    /**/     /**/     _v_,       MO(_PAD), _v_,  /**/ _v_,     _v_,     _v_      /**/     /**/
  ),

  /* ┎─────────────────────────────────────────────────────────────┄
     ┃ Function ∴
     ┖───── ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │f11 │f12 │    │ m  │    │     │ 1  │ 2  │ 3  │ ⌘  │ ⌫  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ f1 │ f2 │ f3 │ f4 │ f5 │     │ 4  │ 5  │ 6  │ ⌥  │ ^  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
  ┆FUN ┆›   │ f6 │ f7 │ f8 │ f9 │f10 │     │ 7  │ 8  │ 9  │    │rset│
  └┄┄┄┄┘    └────┴────┴────┴────┴────┴─┐ ┌─┴────┴────┴────┴────┴────┘
                      │    │    │      │ │   0  │ ▓▓ │ .  │
                      └────┴────┴──────┘ └──────┴────┴────┘ */

  [_FUN] = LAYOUT_36(
    KC_F11, KC_F12, ___,   MC_SHOT, ___,    /**/ KC_1, KC_2, KC_3,  x__LCMD, KC_BSPC,
    KC_F1,  KC_F2,  KC_F3, KC_F4,   KC_F5,  /**/ KC_4, KC_5, KC_6,  x__LOPT, KC_LCTL,
    KC_F6,  KC_F7,  KC_F8, KC_F9,   KC_F10, /**/ KC_7, KC_8, KC_9,  ___,     RESET,
    /**/    /**/    _v_,   _v_,     _v_,    /**/ KC_0, _v_,  KC_DOT /**/     /**/
  ),

  /* ┎─────────────────────────────────────────────────────────────┄
     ┃ Mouse ∴
     ┖───── ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │QWER│    │    │    │ w↑ │     │    │    │ ▲  │ M  │ b+ │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │GAM │    │    │ L  │ w↓ │     │    │ ◀  │ ▼  │ ▶  │ b- │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
  ┆PAD ┆›   │rgb │    │    │    │ R  │     │ v- │ v+ │play│next│rset│
  └┄┄┄┄┘    └────┴────┴────┴────┴────┴─┐ ┌─┴────┴────┴────┴────┴────┘
                      │    │ ▓▓ │      │ │      │    │    │
                      └────┴────┴──────┘ └──────┴────┴────┘ */

  [_PAD] = LAYOUT_36(
    TG(_ALT), ___, ___, ___,    KC_WH_U, /**/ KC_WH_U, ___,     KC_MS_U, x__MMB,  KC_BRIU,
    GAM_ON,   ___, ___, x__LMB, KC_WH_D, /**/ KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID,
    RGB_TOG,  ___, ___, ___,    x__RMB,  /**/ KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, RESET,
    /**/      /**/ _v_, _v_,    _v_,     /**/ _v_,     _v_,     _v_      /**/     /**/
  ),

  /* ┎─────────────────────────────────────────────────────────────┄
     ┃ Onehand, game ∴
     ┖───── */

  #ifdef HALFMAK_ENABLE
  [HM_BASE] = HM_BASE_LAYOUT,
  [HM_FLIP] = HM_FLIP_LAYOUT,
  [HM_NAV] = HM_NAV_LAYOUT,
  [HM_NUM] = HM_NUM_LAYOUT,
  [HM_SYM1] = HM_SYM1_LAYOUT,
  [HM_SYM2] = HM_SYM2_LAYOUT,
  #endif

  [_GAM] = GAM_LAYER,
  [_GMX] = GMX_LAYER,

  /* ┎─────────────────────────────────────────────────────────────┄
     ┃ Blank ∴
     ┖───── ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
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

// ┎──────────────────────────────────────────────────────────────────────
// ┖─┒ Support stuff ∴
//   ┖──┄

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case x__Q:
      return true;
    default:
      return false;
  }
}

#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

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
  case x__DOTQ: // dot
    if (record->event.pressed) {
      if (get_mods() & MODS_SHIFT_MASK) {
        add_key(KC_SLSH); send_keyboard_report();
      } else {
        add_key(KC_DOT); send_keyboard_report();
      }
    } else {
      if (get_mods() & MODS_SHIFT_MASK) {
        del_key(KC_SLSH); send_keyboard_report();
      } else {
        del_key(KC_DOT); send_keyboard_report();
      }
    }
    return false;
  case x__COMU: // comma
    if (record->event.pressed) {
      if (get_mods() & MODS_SHIFT_MASK) {
        add_key(KC_MINS); send_keyboard_report();
      } else {
        add_key(KC_COMM); send_keyboard_report();
      }
    } else {
      if (get_mods() & MODS_SHIFT_MASK) {
        del_key(KC_MINS); send_keyboard_report();
      } else {
        del_key(KC_COMM); send_keyboard_report();
      }
    }
    return false;
  case GAM_ON: // enable game
    if (record->event.pressed) {
      layer_on(_GAM);
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(11, 176, 64);
    }
    return false;
    break;
  case GAM_OFF: // disable game
    if (record->event.pressed) {
      layer_off(_GAM);
      rgblight_disable_noeeprom();
    }
    return false;
    break;
  }

  #ifdef HALFMAK_ENABLE
    return hm_process_record_user(keycode, record);
  #else
    return true;
  #endif
};

// vim:fdm=marker:fmr=∴,┎
// ┎
