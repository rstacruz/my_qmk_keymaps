#ifdef COMBO_TERM

#define DEF_COMBO_INPUT_KC(A,B) \
  const uint16_t PROGMEM combo_ ## A ## B[] = {KC_ ## A, KC_ ## B, COMBO_END}
#define DEF_COMBO_TARGET_KC(A,B,TARGET) \
  COMBO(combo_ ## A ## B, KC_ ## TARGET)
#define DEF_COMBO_TARGET_xx(A,B,TARGET) \
  COMBO(combo_ ## A ## B, TARGET)

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

combo_t key_combos[COMBO_COUNT] = {
  COMBO_ACTION(combo_NA),             /* . . . n | a . . . */
  DEF_COMBO_TARGET_KC(O, I, F),       /* o i . . | . . . . */
  DEF_COMBO_TARGET_KC(O, E, Z),       /* o . e . | . . . . */
  DEF_COMBO_TARGET_KC(O, N, DOT),     /* o . . n | . . . . */
  DEF_COMBO_TARGET_KC(O, R, V),       /* o . . . | . r . . */
  DEF_COMBO_TARGET_KC(O, S, COMM),    /* o . . . | . . s . */
  DEF_COMBO_TARGET_KC(O, T, BSPC),    /* o . . . | . . . t */
  DEF_COMBO_TARGET_KC(I, E, U),       /* . i e . | . . . . */
  DEF_COMBO_TARGET_KC(I, N, J),       /* . i . n | . . . . */
  DEF_COMBO_TARGET_KC(I, A, B),       /* . i . . | a . . . */
  DEF_COMBO_TARGET_KC(I, S, M),       /* . i . . | . . s . */
  DEF_COMBO_TARGET_KC(I, T, P),       /* . i . . | . . . t */
  DEF_COMBO_TARGET_KC(E, N, C),       /* . . e n | . . . . */
  DEF_COMBO_TARGET_KC(E, A, LSFT),    /* . . e . | a . . . */
  DEF_COMBO_TARGET_KC(E, R, G),       /* . . e . | . r . . */
  DEF_COMBO_TARGET_KC(E, T, L),       /* . . e . | . . . t */
  DEF_COMBO_TARGET_KC(N, R, QUOT),    /* . . . n | . r . . */
  DEF_COMBO_TARGET_KC(N, S, Y),       /* . . . n | . . s . */
  DEF_COMBO_TARGET_KC(A, R, W),       /* . . . . | a r . . */
  DEF_COMBO_TARGET_KC(A, S, Q),       /* . . . . | a . s . */
  DEF_COMBO_TARGET_KC(A, T, SPC),     /* . . . . | a . . t */
  DEF_COMBO_TARGET_KC(R, S, H),       /* . . . . | . r s . */
  DEF_COMBO_TARGET_KC(R, T, K),       /* . . . . | . r . t */
  DEF_COMBO_TARGET_KC(S, T, D),       /* . . . . | . . s t */
};

void keyboard_post_init_user(void) {
  combo_disable();
}
#endif

bool onehand_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OH_ON: // enable
      if (record->event.pressed) {
        layer_on(_OH_BAS);
        combo_enable();
      }
      return false;
      break;
    case OH_OFF: // disable
      if (record->event.pressed) {
        layer_off(_OH_BAS);
        combo_disable();
      }
      return false;
      break;
  }
  return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0:
      if (pressed) {
        set_oneshot_layer(_OH_LEA, ONESHOT_START);
      } else {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
      }
      break;
  }
}
