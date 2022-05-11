#include QMK_KEYBOARD_H

// Keycode aliases {{{

#define _v_     KC_TRNS
#define ___     KC_NO
#define x__ENT  LCTL_T(KC_ENT)     /* ctrl(hold) or enter(tap) */
#define x__Q    LCTL_T(KC_Q)       /* ctrl(hold) or q(tap) */
#define x__Z    LGUI_T(KC_Z)       /* gui(hold) or q(tap) */
#define x__CBSP C(KC_BSPC)         /* Delete word */
#define x__LMB  KC_MS_BTN1         /* Left mouse button */
#define x__RMB  KC_MS_BTN2         /* Right mouse button */
#define x__MMB  KC_MS_BTN3         /* Mid mouse button */
#define x__TABP LCTL(KC_PGUP)      /* Next tab */
#define x__TABN LCTL(KC_PGDN)      /* Previous tab */

/* Macros and stuff */
enum custom_keycodes {
  MC_MUTE = SAFE_RANGE,
  MC_HAND,
  MC_SHOT,
  GAM_ON,
  GAM_OFF,
  FV_ON, FV_OFF,
  FV_LSFT, FV_LCTL, FV_LGUI, FV_LALT, FV_OSSF
};

// }}}
// ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
// Layers {{{

enum layers {
  _BASE = 0, _QWE, _SYM, _NAV, _HEX, _FUN, _ADJ, _GAM, _GMX, _GMY, _LOC, _ULO,
  FV_BASE, FV_FLIP, FV_NAV, FV_NUM, FV_SYM, FV_MOU
};

#include "frogv.c"
#include "game_layers.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* }}}
     ────────────────────────────────────────────────────────┄
     Colemak DH ── {{{
     ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
     │ q ^│ w  │ f  │ p  │ b  │     │ j  │ l  │ u  │ y  │bks │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │ a  │ r  │ s  │ t  │ g  │     │ m  │ n  │ e  │ i  │ o  │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │ z *│ x  │ c  │ d  │ v  │     │ k  │ h  │ ,- │ ._ │ent^│
     ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
               │cmd │SYM │ sft  │ │ spc  │NAV │opt │
               ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [0] = LAYOUT_36(
    x__Q, KC_W, KC_F,    KC_P,     KC_B,    /**/ KC_J,   KC_L,     KC_U,    KC_Y,    KC_BSPC,
    KC_A, KC_R, KC_S,    KC_T,     KC_G,    /**/ KC_M,   KC_N,     KC_E,    KC_I,    KC_O,
    x__Z, KC_X, KC_C,    KC_D,     KC_V,    /**/ KC_K,   KC_H,     KC_COMM, KC_DOT,  x__ENT,
    /**/  /**/  KC_LGUI, MO(_SYM), KC_LSFT, /**/ KC_SPC, MO(_NAV), KC_LALT  /**/     /**/
  ),

  /* }}}
     ────────────────────────────────────────────────────────┄
     _QWE / Qwerty ── {{{
     ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
     │ q ^│ w  │ e  │ r  │ t  │     │ y  │ u  │ i  │ o  │ p  │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │ a  │ s  │ d  │ f  │ g  │     │ h  │ j  │ k  │ l  │bks │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │ z  │ x  │ c  │ v  │ b  │     │ n  │ m  │ ,  │ .  │ent^│
     ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
               │cmd │SYM │ sft  │ │ spc  │NAV │opt │
               ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_QWE] = LAYOUT_36(
    x__Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, KC_J, KC_K,    KC_L,   KC_BSPC,
    KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, x__ENT,
    /**/  /**/  _v_,  _v_,  _v_,  /**/ _v_,  _v_,  _v_      /**/    /**/
  ),

  /* }}}
     ────────────────────────────────────────────────────────┄
     _SYM / Symbols ── {{{
     ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
     │ '  │ "  │ ^  │ ?  │ `  │     │ [  │ <  │ =  │ >  │ ]  │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │ !  │ @  │ #  │ $  │ %  │     │ {  │ (  │ :  │ )  │ }  │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │ \  │ ~  │ |  │ &  │ ;  │     │ /  │ *  │ -  │ +  │ _  │
     ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
               │    │ ▓▓ │ ADJ  │ │      │HEX │    │
               ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_SYM] = LAYOUT_36(
    KC_QUOT, KC_DQUO, KC_CIRC, KC_QUES, KC_GRV,   /**/ KC_LBRC, KC_LT,    KC_EQL,  KC_GT,   KC_RBRC,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  /**/ KC_LCBR, KC_LPRN,  KC_COLN, KC_RPRN, KC_RCBR,
    KC_BSLS, KC_TILD, KC_PIPE, KC_AMPR, KC_SCLN,  /**/ KC_SLSH, KC_ASTR,  KC_MINS, KC_PLUS, KC_UNDS,
    /**/     /**/     _v_,     _v_,     MO(_ADJ), /**/ _v_,     MO(_HEX), _v_      /**/     /**/
  ),

  /* }}}
     ────────────────────────────────────────────────────────┄
     _NAV / Navigate ── {{{
     ╭────┬────┬────┬────┬────╮     ╭────╭────┬────┬────╮┄───╮
     │ctl │cmd │ ⇧↹ │ ↹  │opt │     │ ,  │home│ ▲  │end │HEX │
     ├────┼────┼────┼────┼────┤     ├────├────┼────┼────┤┄───┤
     │ 1  │ 2  │ 3  │ 4  │ 5  │     │ .  │ ◀  │ ▼  │ ▶  │ent │
     ├────┼────┼────┼────┼────┤     ├────╰────┴────┴────╯┄───┤
     │ 6  │ 7  │ 8  │ 9  │ 0  │     │    │ p↑ │ p↓ │esc │del^│
     ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
               │cmd │FUN │ sft  │ │      │ ▓▓ │    │
               ╰────┴────┴──────╯ ╰──────┴────┴────╯ */
  [_NAV] = LAYOUT_36(
    KC_RCTL, KC_RGUI, S(KC_TAB), KC_TAB,   KC_RALT, /**/ KC_COMM,  KC_HOME, KC_UP,   KC_END,  MO(_HEX),
    KC_1,    KC_2,    KC_3,      KC_4,     KC_5,    /**/ KC_DOT,   KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
    KC_6,    KC_7,    KC_8,      KC_9,     KC_0,    /**/ KC_ESC,   KC_PGUP, KC_PGDN, KC_ESC,  LCTL_T(KC_DEL),
    /**/     /**/     _v_,       MO(_FUN), _v_,     /**/ MO(_HEX), KC_ENT,  _v_      /**/     /**/
  ),

  /* }}}
     ────────────────────────────────────────────────────────┄
     _HEX / Hex input ── {{{
     ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
     │    │    │    │    │ #  │     │ +  │ A  │ B  │ C  │bks │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │ 1  │ 2  │ 3  │ 4  │ 5  │     │ .  │ D  │ E  │ F  │ent │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │ 6  │ 7  │ 8  │ 9  │ 0  │     │ /  │ *  │ -  │ +  │ :  │
     ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
               │    │    │ spc  │ │ spc  │ ▓▓ │    │
               ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_HEX] = LAYOUT_36(
  ___,  KC_COMM, KC_DOT,  KC_COLN, KC_HASH, /**/ KC_COMM, KC_A,    KC_B,    KC_C,    KC_BSPC,
  KC_1, KC_2,    KC_3,    KC_4,    KC_5,    /**/ KC_DOT,  KC_D,    KC_E,    KC_F,    KC_ENT,
  KC_6, KC_7,    KC_8,    KC_9,    KC_0,    /**/ KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_COLN,
  /**/  /**/     KC_COMM, KC_DOT,  KC_SPC,  /**/ KC_SPC,  ___,     ___      /**/     /**/
  ),

  /* }}}
     ────────────────────────────────────────────────────────┄
     _FUN / Function ── {{{
     ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
     │f11 │f12 │ R  │prnt│ L  │     │ w↑ │    │ ▲  │    │ b+ │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │ f1 │ f2 │ f3 │ f4 │ f5 │     │ w↓ │ ◀  │ ▼  │ ▶  │ b- │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │ f6 │ f7 │ f8 │ f9 │f10 │     │ v- │ v+ │play│next│rset│
     ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
               │    │ ▓▓ │      │ │ L    │ R░ │ M  │
               ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_FUN] = LAYOUT_36(
    KC_F11, KC_F12, KC_F13, KC_PSCR, KC_F15, /**/ KC_WH_U, KC_F13,  KC_MS_U, KC_F14,  KC_BRIU,
    KC_F1,  KC_F2,  KC_F3,  KC_F4,   KC_F5,  /**/ KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID,
    KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10, /**/ KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, RESET,
    /**/    /**/    _v_,    _v_,     _v_,    /**/ x__LMB,  x__RMB,  x__MMB   /**/     /**/
  ),

  /* }}}
     ────────────────────────────────────────────────────────┄
     _ADJ / Adjust ── {{{
     ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
     │Lock│   norm  │    │    │     │ p↑ │ ⇤  │ ▲  │ ⇥  │    │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │GAME│   swap  │    │    │     │ p↓ │ ◀  │ ▼  │ ▶  │ctl │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │QWE │CMB │    │    │RGB │     │    │    │    │    │rset│
     ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
               │    │ 1H │   ▓▓ │ │ 1H   │    │    │
               ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_ADJ] = LAYOUT_36(
    DF(_LOC), LAG_NRM, CG_NORM, ___,   ___,     /**/ KC_PGUP, KC_HOME, KC_UP,   KC_END,  ___,
    GAM_ON,   LAG_SWP, CG_SWAP, ___,   ___,     /**/ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCTL,
    TG(_QWE), CMB_TOG, ___,     ___,   RGB_TOG, /**/ ___,     ___,     ___,     ___,     RESET,
    /**/      /**/     _v_,     FV_ON, _v_,     /**/ FV_ON,   _v_,     _v_      /**/     /**/
  ),

  /* }}}
     ────────────────────────────────────────────────────────┄
     _GAM / Game + FrogV {{{
  */

  #ifdef FROGV_ENABLE
  [FV_BASE] = FV_BASE_LAYOUT,
  [FV_FLIP] = FV_FLIP_LAYOUT,
  [FV_NAV]  = FV_NAV_LAYOUT,
  [FV_NUM]  = FV_NUM_LAYOUT,
  [FV_SYM]  = FV_SYM_LAYOUT,
  [FV_MOU]  = FV_MOU_LAYOUT,
  #endif

  [_GAM] = GAM_LAYER,
  [_GMX] = GMX_LAYER,
  [_GMY] = GMY_LAYER,

  /* }}}
     ────────────────────────────────────────────────────────┄
     Blank ── {{{
     ╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬────┬────╮
     │    │    │    │    │    │     │    │    │    │    │    │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │    │    │    │    │    │     │    │    │    │    │    │
     ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
     │    │    │    │    │    │     │    │    │    │    │    │
     ╰────┴────┴────┴────┴────┴─╮ ╭─┴────┴────┴────┴────┴────╯
               │    │    │      │ │      │    │    │
               ╰────┴────┴──────╯ ╰──────┴────┴────╯ */

  [_LOC] = LAYOUT_36(
    ___, ___, ___, ___, ___,      ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___,      ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___,      ___, ___, ___, ___, ___,
    /**/ /**/ ___, ___, MO(_ULO), ___, ___, ___  /**/ /**/
  ),
  [_ULO] = LAYOUT_36(
    DF(0), ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___,   ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___,   ___, ___, ___, ___, ___, ___, ___, ___, ___,
    /**/   /**/ ___, ___, ___, ___, ___, ___  /**/ /**/
  )
};
/* ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄ */

// }}}
/* ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄ */
// Support stuff {{{

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
    if (record->event.pressed) { SEND_STRING(SS_LSFT(SS_LGUI("a"))); }
    break;
  case MC_HAND: // Zoom: raise hand
    if (record->event.pressed) { SEND_STRING(SS_LSFT(SS_LGUI("y"))); }
    break;
  case MC_SHOT: // MacOS: take screenshot
    if (record->event.pressed) { SEND_STRING(SS_LSFT(SS_LCTL(SS_LGUI("4")))); }
    break;
  case GAM_ON: // enable game
    if (record->event.pressed) {
      layer_on(_GAM);
      #ifdef RGBLIGHT_ENABLE
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(11, 176, 64);
      #endif
    }
    return false;
    break;
  case GAM_OFF: // disable game
    if (record->event.pressed) {
      layer_off(_GAM);
      #ifdef RGBLIGHT_ENABLE
        rgblight_disable_noeeprom();
      #endif
    }
    return false;
    break;
  }

  #ifdef FROGV_ENABLE
    return fm_process_record_user(keycode, record);
  #else
    return true;
  #endif
};

// }}}
// Combos {{{

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_h_comm[] = {KC_H, KC_COMM, COMBO_END}; //     [ .XX.. ] => '
const uint16_t PROGMEM combo_comm_dot[] = {KC_COMM, KC_DOT, COMBO_END}; // [ ..XX. ] => alt-tab
const uint16_t PROGMEM combo_h_dot[] = {KC_H, KC_DOT, COMBO_END}; //       [ .X.X. ] => esc


combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_h_comm, KC_QUOT),
  COMBO(combo_comm_dot, A(KC_TAB)),
  COMBO(combo_h_dot, KC_ESC),
};
#endif

// }}}
// Key overrides {{{
const key_override_t override_comma = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_MINS);
const key_override_t override_dot = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_UNDS);

const key_override_t **key_overrides = (const key_override_t *[]){
  &override_comma,
  &override_dot,
  NULL
};

// vim:fdm=marker:fmr={{{,}}}
// }}}
