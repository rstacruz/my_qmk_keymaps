
/*
Put this in config.h:

    #define COMBO_TERM 40
    #define COMBO_COUNT 32

In rules.mk:

    COMBO_ENABLE = true

Add custom keycodes in keymap.c:

    enum custom_keycodes {
      ... = SAFE_RANGE,
      OH_ON, OH_OFF, OH_LCTL, OH_LALT, OH_LGUI, OH_LSFT,
    };
    enum layers {
      ...
      _OH_BAS, _OH_NAV, _OH_MOD, _OH_NUM
    };

    #include "onehand_combos.c"

...then bind `OH_ON` to a key
*/

#ifdef COMBO_TERM

#ifndef LAYOUT_onehand_15
#define LAYOUT_onehand_15(k1, k2, k3, k4, k5, k6, k7, k8, k9, ka, kb, kc, kd, ke, kf) \
 LAYOUT_36( \
    k1,  k2,  k3,  k4,  k5,     /**/ ___,    ___, ___, ___, ___, \
    k6,  k7,  k8,  k9,  ka,     /**/ ___,    ___, ___, ___, ___, \
    kb,  kc,  kd,  ke,  kf,     /**/ ___,    ___, ___, ___, ___, \
    /**/ /**/ ___, ___, OH_OFF, /**/ OH_OFF, ___, ___  \
  )
#endif

#define ONEHAND_ENABLED

/* Onehand: base */
#define OH_BAS_LAYOUT LAYOUT_onehand_15( \
  KC_O, KC_I, KC_E,   KC_N, LT(_OH_NAV,KC_BSPC), \
  KC_A, KC_R, KC_S,   KC_T, MO(_OH_MOD),         \
  ___,  ___,  KC_SPC, ___,  MO(_OH_NUM)          \
)

/* Onehand: mod */
#define OH_MOD_LAYOUT LAYOUT_onehand_15( \
  OH_LCTL, OH_LGUI, OH_LALT, ___,    ___, \
  OH_LSFT, KC_ESC,  KC_ENT,  KC_TAB, ___, \
  _v_,     _v_,     _v_,     _v_,    _v_ \
)

/* Onehand: Nav */
#define OH_NAV_LAYOUT LAYOUT_onehand_15( \
  TG(_OH_NAV), KC_PGUP, KC_UP,   KC_PGDN, _v_, \
  ___,         KC_LEFT, KC_DOWN, KC_RGHT, _v_, \
  _v_,         _v_,     _v_,     _v_,     _v_ \
)

/* Onehand: number */
#define OH_NUM_LAYOUT LAYOUT_onehand_15( \
  ___,  KC_7, KC_8, KC_9, ___, \
  ___,  KC_4, KC_5, KC_6, ___, \
  KC_0, KC_1, KC_2, KC_3, ___ \
)

#define DEF_COMBO_INPUT_KC(A,B) \
  const uint16_t PROGMEM combo_ ## A ## _ ## B[] = {KC_ ## A, KC_ ## B, COMBO_END}
#define DEF_COMBO_INPUT_3KC(A,B,C) \
  const uint16_t PROGMEM combo_ ## A ## _ ## B ## _ ## C[] = {KC_ ## A, KC_ ## B, KC_ ## C, COMBO_END}
#define DEF_COMBO_TARGET_KC(A,B,TARGET) \
  COMBO(combo_ ## A ## _ ## B, KC_ ## TARGET)
#define DEF_COMBO_TARGET_3KC(A,B,C,TARGET) \
  COMBO(combo_ ## A ## _ ## B ## _ ## C, KC_ ## TARGET)
#define DEF_COMBO_TARGET_xx(A,B,TARGET) \
  COMBO(combo_ ## A ## _ ## B, TARGET)

DEF_COMBO_INPUT_KC(O, I); /* o i . . | . . . . */
DEF_COMBO_INPUT_KC(O, E); /* o . e . | . . . . */
DEF_COMBO_INPUT_KC(O, N); /* o . . n | . . . . */
DEF_COMBO_INPUT_KC(O, A); /* o . . . | a . . . (!) */
DEF_COMBO_INPUT_KC(O, R); /* o . . . | . r . . */
DEF_COMBO_INPUT_KC(O, S); /* o . . . | . . s . */
DEF_COMBO_INPUT_KC(O, T); /* o . . . | . . . t */
DEF_COMBO_INPUT_KC(I, E); /* . i e . | . . . . */
DEF_COMBO_INPUT_KC(I, N); /* . i . n | . . . . */
DEF_COMBO_INPUT_KC(I, A); /* . i . . | a . . . */
DEF_COMBO_INPUT_KC(I, R); /* . i . . | . r . . (!) */
DEF_COMBO_INPUT_KC(I, S); /* . i . . | . . s . */
DEF_COMBO_INPUT_KC(I, T); /* . i . . | . . . t */
DEF_COMBO_INPUT_KC(E, N); /* . . e n | . . . . */
DEF_COMBO_INPUT_KC(E, A); /* . . e . | a . . . */
DEF_COMBO_INPUT_KC(E, R); /* . . e . | . r . . */
DEF_COMBO_INPUT_KC(E, S); /* . . e . | . . s . (!) */
DEF_COMBO_INPUT_KC(E, T); /* . . e . | . . . t */
DEF_COMBO_INPUT_KC(N, A); /* . . . n | a . . . */
DEF_COMBO_INPUT_KC(N, R); /* . . . n | . r . . */
DEF_COMBO_INPUT_KC(N, S); /* . . . n | . . s . */
DEF_COMBO_INPUT_KC(N, T); /* . . . n | . . . t (!) */
DEF_COMBO_INPUT_KC(A, R); /* . . . . | a r . . */
DEF_COMBO_INPUT_KC(A, S); /* . . . . | a . s . */
DEF_COMBO_INPUT_KC(A, T); /* . . . . | a . . t */
DEF_COMBO_INPUT_KC(R, S); /* . . . . | . r s . */
DEF_COMBO_INPUT_KC(R, T); /* . . . . | . r . t */
DEF_COMBO_INPUT_KC(S, T); /* . . . . | . . s t */
DEF_COMBO_INPUT_3KC(O, I, E); /* o i e . | . . . . */
DEF_COMBO_INPUT_3KC(I, E, N); /* . i e n | . . . . */
DEF_COMBO_INPUT_3KC(A, R, S); /* . . . . | a r s . */
DEF_COMBO_INPUT_3KC(R, S, T); /* . . . . | . r s t */
DEF_COMBO_INPUT_KC(ENT, TAB);
DEF_COMBO_INPUT_KC(PGUP, UP);
DEF_COMBO_INPUT_KC(UP, PGDN);
DEF_COMBO_INPUT_KC(7, 8);

combo_t key_combos[COMBO_COUNT] = {
  /* Actions */
  COMBO_ACTION(combo_N_A),            /* . . . n | a . . . - shift */
  /* Triplets */
  DEF_COMBO_TARGET_3KC(O, I, E, W),    /* o i e . | . . . . - (*) */
  DEF_COMBO_TARGET_3KC(I, E, N, BSPC), /* . i e n | . . . . - (*) */
  DEF_COMBO_TARGET_3KC(A, R, S, B),    /* . . . . | a r s . - (*) */
  DEF_COMBO_TARGET_3KC(R, S, T, SPC),  /* . . . . | . r s t - (*) */
  /* Adjacents */
  DEF_COMBO_TARGET_KC(O, I, J),       /* o i . . | . . . . */
  DEF_COMBO_TARGET_KC(I, E, C),       /* . i e . | . . . . */
  DEF_COMBO_TARGET_KC(E, N, U),       /* . . e n | . . . . */
  DEF_COMBO_TARGET_KC(A, R, K),       /* . . . . | a r . . */
  DEF_COMBO_TARGET_KC(R, S, D),       /* . . . . | . r s . */
  DEF_COMBO_TARGET_KC(S, T, H),       /* . . . . | . . s t */
  /* Skip-hops */
  DEF_COMBO_TARGET_KC(O, E, Z),       /* o . e . | . . . . */
  DEF_COMBO_TARGET_KC(I, N, W),       /* . i . n | . . . . */
  DEF_COMBO_TARGET_KC(A, S, V),       /* . . . . | a . s . */
  DEF_COMBO_TARGET_KC(R, T, M),       /* . . . . | . r . t */
  /* Knights */
  DEF_COMBO_TARGET_KC(O, S, Q),       /* o . . . | . . s . */
  DEF_COMBO_TARGET_KC(I, T, P),       /* . i . . | . . . t */
  DEF_COMBO_TARGET_KC(E, A, G),       /* . . e . | a . . . */
  DEF_COMBO_TARGET_KC(N, R, F),       /* . . . n | . r . . */
  /* Four-wides */
  DEF_COMBO_TARGET_KC(O, N, DOT),     /* o . . n | . . . . */
  DEF_COMBO_TARGET_KC(A, T, SPC),     /* . . . . | a . . t */
  /* Diagonals, upward */
  DEF_COMBO_TARGET_KC(I, A, QUOT),    /* . i . . | a . . . */
  DEF_COMBO_TARGET_KC(E, R, B),       /* . . e . | . r . . */
  DEF_COMBO_TARGET_KC(N, S, Y),       /* . . . n | . . s . */
  /* Diagonals, downward */
  DEF_COMBO_TARGET_KC(O, R, COMM),    /* o . . . | . r . . */
  DEF_COMBO_TARGET_KC(I, S, X),       /* . i . . | . . s . */
  DEF_COMBO_TARGET_KC(E, T, L),       /* . . e . | . . . t */
  /* Wide diagonals */
  // DEF_COMBO_TARGET_KC(N, A, NO),   /* . . . n | a . . . */
  DEF_COMBO_TARGET_KC(O, T, BSPC),    /* o . . . | . . . t -- ?? */
  /* Navs */
  DEF_COMBO_TARGET_KC(ENT, TAB, ESC),
  DEF_COMBO_TARGET_KC(PGUP, UP, HOME),
  DEF_COMBO_TARGET_KC(UP, PGDN, END),
  DEF_COMBO_TARGET_xx(7, 8, TG(_OH_NUM)),
};

void keyboard_post_init_user(void) {
  // Disable combos on startup
  combo_disable();
}
#endif

bool onehand_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OH_ON: // enable
      if (record->event.pressed) {
        layer_on(_OH_BAS);
        combo_enable();
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(HSV_PURPLE);
      }
      return false;
      break;
    case OH_OFF: // disable
      if (record->event.pressed) {
        layer_off(_OH_BAS);
        layer_off(_OH_MOD);
        layer_off(_OH_NAV);
        layer_off(_OH_NUM);
        combo_disable();
        rgblight_disable_noeeprom();
      }
      return false;
      break;
    case OH_LCTL:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_LCTL); register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
      }
      return false;
      break;
    case OH_LGUI:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_LGUI); register_code(KC_LGUI);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case OH_LALT:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_LALT); register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
      }
      return false;
      break;
    case OH_LSFT:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_LSFT); register_code(KC_LSFT);
      } else {
        unregister_code(KC_LSFT);
      }
      return false;
      break;
  }
  return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0: // Shift
      if (pressed) { set_oneshot_mods(MOD_LSFT); } break;
  }
}
