/*
 * LEFT HAND         triplet:      knight:         diags:         sides:
 * ┌── f ─ c ─ u ──┐ ┌───────────┐ ┌────────────┐ ┌ q ─ x ─ l ──┐ ┌─────────┐
 * │ o   i   e   n │ │ g ┄┄ ┄┄ m │ │ k ┄┄┐┌┄┄ ' │ │  ╲   ╲   ╲  │ │ ┄┄mod┄┄ │
 * │ a   r   s   t │ │ v ┄┄ ┄┄ y │ │ . ┄┄┘└┄┄ p │ │ ╱   ╱   ╱   │ │ ┄┄spc┄┄ │
 * └── w ─ d ─ h ──┘ └───────────┘ └────────────┘ └ b ─ z ─ j ──┘ └─────────┘
 * mod:               nav:             num:
 * ┌────────────────┐ ┌──────hm─en───┐ ┌─────────────┐
 * │ ⇧   ⌥   ⌘   ⌃  │ │ ‹‹  p↑ ▲  p↓ │ │ ‹‹ 1  2  3  │
 * │ esc tab ent ‹‹ │ │     ◀  ▼  ▶  │ │ 0  4  5  6  │
 * └───────bks──────┘ └──────────────┘ └───7──8──9───┘
 *
 * RIGHT HAND        triplet:      knight:         diags:         sides:
 * ┌── u ─ c ─ f ──┐ ┌───────────┐ ┌────────────┐ ┌─ l ─ x ─ q ─┐ ┌─────────┐
 * │ n   e   i   o │ │ m ┄┄ ┄┄ g │ │ . ┄┄┐┌┄┄ k │ │   ╱   ╱   ╱ │ │ ┄┄mod┄┄ │
 * │ t   s   r   a │ │ y ┄┄ ┄┄ v │ │ p ┄┄┘└┄┄ ' │ │  ╲   ╲   ╲  │ │ ┄┄spc┄┄ │
 * └── h ─ d ─ w ──┘ └───────────┘ └────────────┘ └─ j ─ z ─ b ─┘ └─────────┘
 */

#ifdef COMBO_TERM

#define DEF_COMBO_INPUT_KC(A,B) \
  const uint16_t PROGMEM combo_ ## A ## _ ## B[] = {KC_ ## A, KC_ ## B, COMBO_END}
#define DEF_COMBO_TARGET_KC(A,B,TARGET) \
  COMBO(combo_ ## A ## _ ## B, KC_ ## TARGET)
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
DEF_COMBO_INPUT_KC(ENT, TAB);
DEF_COMBO_INPUT_KC(PGUP, UP);
DEF_COMBO_INPUT_KC(UP, PGDN);

const uint16_t PROGMEM combo_A_R_S[] = {KC_A, KC_R, KC_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  /* Actions */
  COMBO_ACTION(combo_N_A),            /* . . . n | a . . . - shift */
  COMBO_ACTION(combo_O_N),            /* o . . n | . . . . - mod */
  COMBO_ACTION(combo_N_T),            /* . . . n | . . . t - nav */
  COMBO_ACTION(combo_O_A),            /* o . . . | a . . . - num */
  /* Specials */
  COMBO(combo_A_R_S, KC_SPC),
  /* Adjacents */
  DEF_COMBO_TARGET_KC(O, I, F),       /* o i . . | . . . . */
  DEF_COMBO_TARGET_KC(I, E, C),       /* . i e . | . . . . */
  DEF_COMBO_TARGET_KC(E, N, U),       /* . . e n | . . . . */
  DEF_COMBO_TARGET_KC(A, R, W),       /* . . . . | a r . . */
  DEF_COMBO_TARGET_KC(R, S, D),       /* . . . . | . r s . */
  DEF_COMBO_TARGET_KC(S, T, H),       /* . . . . | . . s t */
  /* Triplets */
  DEF_COMBO_TARGET_KC(O, E, G),       /* o . e . | . . . . */
  DEF_COMBO_TARGET_KC(I, N, M),       /* . i . n | . . . . */
  DEF_COMBO_TARGET_KC(A, S, V),       /* . . . . | a . s . */
  DEF_COMBO_TARGET_KC(R, T, Y),       /* . . . . | . r . t */
  /* Knights */
  DEF_COMBO_TARGET_KC(O, S, K),       /* o . . . | . . s . */
  DEF_COMBO_TARGET_KC(I, T, P),       /* . i . . | . . . t */
  DEF_COMBO_TARGET_KC(E, A, DOT),     /* . . e . | a . . . */
  DEF_COMBO_TARGET_KC(N, R, QUOT),    /* . . . n | . r . . */
  /* Four-wides */
  DEF_COMBO_TARGET_KC(A, T, SPC),     /* . . . . | a . . t */
  /* Diagonals, upward */
  DEF_COMBO_TARGET_KC(I, A, B),       /* . i . . | a . . . */
  DEF_COMBO_TARGET_KC(E, R, Z),       /* . . e . | . r . . */
  DEF_COMBO_TARGET_KC(N, S, J),       /* . . . n | . . s . */
  /* Diagonals, downward */
  DEF_COMBO_TARGET_KC(O, R, Q),       /* o . . . | . r . . */
  DEF_COMBO_TARGET_KC(I, S, X),       /* . i . . | . . s . */
  DEF_COMBO_TARGET_KC(E, T, L),       /* . . e . | . . . t */
  /* Wide diagonals */
  DEF_COMBO_TARGET_KC(O, T, BSPC),    /* o . . . | . . . t */
  /* Navs */
  DEF_COMBO_TARGET_KC(ENT, TAB, ESC),
  DEF_COMBO_TARGET_KC(PGUP, UP, HOME),
  DEF_COMBO_TARGET_KC(UP, PGDN, END),
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
    case 1: // Mod
      if (pressed) { layer_on(_OH_MOD); } break;
    case 2: // Nav
      if (pressed) { layer_on(_OH_NAV); } break;
    case 3: // Num
      if (pressed) { layer_on(_OH_NUM); } break;
  }
}
