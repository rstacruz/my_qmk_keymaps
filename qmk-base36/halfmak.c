#define FROGPAD_ENABLE

#ifndef FF_HSV_COLOR
#define FF_HSV_COLOR 191, 255, 50
#endif

/* frogpad-like layout
┌ base ──────────┐ ┌ flip ────── ▲ ─┐
│ f↔ d  n  i  g  │ │    j  k  m  q  │
│ s▲ t  h  e  o  │ │ ▲  y  p  l ⌫   │
│ c∴ w  r  a  u  │ │ ^  x  b  v  z  │
└────┬───┬───┬───┤ └────┬───┬───┬───┤
     │ctl│₁₂₃│ ␣↑│      │ ⌘ │ ⌥ │ ↑ │
     └───┴───┴───┘      └───┴───┴───┘
┌ nav ─────── ↔ ─┐ ┌ 123 ─────── ₁ ─┐
│ ↔  p↑ ▲  p↓ ⎋  │ │                │
│    ◀  ▼  ▶  ↵  │ │ 1  2  3  4  5  │
│    ⌥  ⌘  ⌃  ↹  │ │ 6  7  8  9  0  │
└────────────────┘ └────────────────┘
┌ punc ────── ∴ ─┐ ┌ brac ────── ∵ ─┐
│    :  "  '  /  │ │    `  {  }  ~  │
│    -  ,  .  =  │ │ |  <  (  )  >  │
│ ∴  +  !  ?  _  │ │    \  [  ]  ;  │
└────────────────┘ └────────────────┘ */

#define LAYOUT_frogpad_18( \
  k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, \
  k11, k12, k13, k14, k15, k16, k17, k18) \
LAYOUT_36( \
  k01, k02, k03, k04, k05, /**/ ___,    ___, ___, ___, ___, \
  k06, k07, k08, k09, k10, /**/ ___,    ___, ___, ___, ___, \
  k11, k12, k13, k14, k15, /**/ ___,    ___, ___, ___, ___, \
  /**/ /**/ k16, k17, k18, /**/ FF_OFF, ___, ___  \
)

#define FF_BSPC LT(FF_SYM1,KC_BSPC)
#define FF_SPC MT(MOD_LSFT,KC_SPC)

#define FF_BASE_LAYOUT LAYOUT_frogpad_18( \
  LT(FF_NAV,KC_F),  KC_D,       KC_N,  KC_I, KC_G, \
  LT(FF_FLIP,KC_S), KC_T,       KC_H,  KC_E, KC_O, \
  LT(FF_SYM1,KC_C), KC_W,       KC_R,  KC_A, KC_U, \
  KC_LCTL,          MO(FF_NUM), FF_SPC )

#define FF_FLIP_LAYOUT LAYOUT_frogpad_18( \
  ___,     KC_J, KC_K,    KC_M,    KC_Q,    \
  ___,     KC_Y, KC_P,    KC_L,    KC_BSPC, \
  KC_LCTL, KC_X, KC_B,    KC_V,    KC_Z,    \
  /**/     /**/  KC_LALT, KC_LGUI, _v_      )

#define FF_NAV_LAYOUT LAYOUT_frogpad_18( \
  ___, KC_PGUP, KC_UP,   KC_PGDN, KC_ESC, \
  ___, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, \
  ___, ___,     ___,     ___,     KC_TAB, \
  /**/ /**/     _v_,     _v_,     _v_     )

#define FF_NUM_LAYOUT LAYOUT_frogpad_18( \
  FF_OFF, ___,  ___,  ___,  ___,  \
  KC_1,   KC_2, KC_3, KC_4, KC_5, \
  KC_6,   KC_7, KC_8, KC_9, KC_0, \
  /**/    /**/  _v_,  _v_,  _v_   )

#define FF_SYM1_LAYOUT LAYOUT_frogpad_18( \
  ___, KC_COLN, KC_DQUO, KC_QUOT, KC_SLSH,    \
  ___, KC_MINS, KC_COMM, KC_DOT,  KC_EQL,     \
  ___, KC_PLUS, KC_EXLM, KC_QUES, KC_UNDS,    \
  /**/ /**/     _v_,     _v_,     MO(FF_SYM2) )

#define FF_SYM2_LAYOUT LAYOUT_frogpad_18( \
  ___,     KC_GRV,  KC_LCBR, KC_RCBR, KC_TILD, \
  KC_PIPE, KC_LT,   KC_LPRN, KC_RPRN, KC_GT,   \
  ___,     KC_BSLS, KC_LBRC, KC_RBRC, KC_SCLN, \
  /**/     /**/     _v_,     _v_,     _v_      )

bool hm_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FF_ON: // enable
      if (record->event.pressed) {
        layer_on(FF_BASE);
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(FF_HSV_COLOR);
      }
      return false;
      break;
    case FF_OFF: // disable
      if (record->event.pressed) {
        layer_off(FF_BASE);
        rgblight_disable_noeeprom();
      }
      return false;
      break;
  }
  return true;
}
