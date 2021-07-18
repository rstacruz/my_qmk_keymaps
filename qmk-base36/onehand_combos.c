/*
  Left hand
  base/adjacents:   skip-hops:    knight:         diags:        
  ┌── j ─ c ─ u ──┐ ┌───────────┐ ┌────────────┐ ┌ q ─ x ─ l ──┐
  │ o   i   e   n │ │   ┄┄ ┄┄ w │ │ ' ┄┄┐┌┄┄ f │ │  ╲   ╲   ╲  │
  │ a   r   s   t │ │ v ┄┄ ┄┄ m │ │ . ┄┄┘└┄┄ p │ │ ╱   ╱   ╱   │
  └── k ─ d ─ h ──┘ └───────────┘ └────────────┘ └ z ─ b ─ y ──┘
sides:      long-diag:      verts: (nothing)
  ┌─────────┐ ┌───────────┐ ┌─────────────┐
  │ ┄┄ g ┄┄ │ │ bks ┄┄┄┄┐ │ │ ┆  ┆  ┆  ┆  │
  │ ┄┄spc┄┄ │ │ sft ┄┄┄┄┘ │ │ ┆  ┆  ┆  ┆  │
  └─────────┘ └───────────┘ └─────────────┘
  mod:               nav:             num:
  ┌────────────────┐ ┌──────hm─en───┐ ┌─────────────┐
  │ ⇧   ⌥   ⌘   ⌃  │ │ ‹‹  p↑ ▲  p↓ │ │ ‹‹ 1  2  3  │
  │ esc tab ent ‹‹ │ │     ◀  ▼  ▶  │ │ 0  4  5  6  │
  └───────bks──────┘ └──────────────┘ └───7──8──9───┘
 */

#ifdef COMBO_TERM

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
  // DEF_COMBO_TARGET_KC(O, E, G),    /* o . e . | . . . . */
  DEF_COMBO_TARGET_KC(I, N, W),       /* . i . n | . . . . */
  DEF_COMBO_TARGET_KC(A, S, V),       /* . . . . | a . s . */
  DEF_COMBO_TARGET_KC(R, T, M),       /* . . . . | . r . t */
  /* Knights */
  DEF_COMBO_TARGET_KC(O, S, QUOT),    /* o . . . | . . s . */
  DEF_COMBO_TARGET_KC(I, T, P),       /* . i . . | . . . t */
  DEF_COMBO_TARGET_KC(E, A, DOT),     /* . . e . | a . . . */
  DEF_COMBO_TARGET_KC(N, R, F),       /* . . . n | . r . . */
  /* Four-wides */
  DEF_COMBO_TARGET_KC(O, N, G),       /* o . . n | . . . . */
  DEF_COMBO_TARGET_KC(A, T, SPC),     /* . . . . | a . . t */
  /* Diagonals, upward */
  DEF_COMBO_TARGET_KC(I, A, Z),       /* . i . . | a . . . */
  DEF_COMBO_TARGET_KC(E, R, B),       /* . . e . | . r . . */
  DEF_COMBO_TARGET_KC(N, S, Y),       /* . . . n | . . s . */
  /* Diagonals, downward */
  DEF_COMBO_TARGET_KC(O, R, Q),       /* o . . . | . r . . */
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
  }
  return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0: // Shift
      if (pressed) { set_oneshot_mods(MOD_LSFT); } break;
  }
}