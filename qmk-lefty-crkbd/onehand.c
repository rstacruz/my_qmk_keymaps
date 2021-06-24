#ifdef COMBO_TERM

#define DEF_COMBO_INPUT_KC(A,B) \
  const uint16_t PROGMEM combo_ ## A ## B[] = {KC_ ## A, KC_ ## B, COMBO_END}
#define DEF_COMBO_TARGET_KC(A,B,TARGET) \
  COMBO(combo_ ## A ## B, KC_ ## TARGET)

#define ONEHAND_KEYCODES

DEF_COMBO_INPUT_KC(O, I); /* o o . . | . . . . */
DEF_COMBO_INPUT_KC(I, E); /* . o o . | . . . . */
DEF_COMBO_INPUT_KC(E, N); /* . . o o | . . . . */
DEF_COMBO_INPUT_KC(O, N); /* o . . o | . . . . */
DEF_COMBO_INPUT_KC(O, E); /* o . o . | . . . . */
DEF_COMBO_INPUT_KC(I, N); /* . o . o | . . . . */
DEF_COMBO_INPUT_KC(A, R); /* . . . . | o o . . */
DEF_COMBO_INPUT_KC(R, S); /* . . . . | . o o . */
DEF_COMBO_INPUT_KC(S, T); /* . . . . | . . o o */
DEF_COMBO_INPUT_KC(A, T); /* . . . . | o . . o */
DEF_COMBO_INPUT_KC(A, S); /* . . . . | o . o . */
DEF_COMBO_INPUT_KC(R, T); /* . . . . | . o . o */
DEF_COMBO_INPUT_KC(I, A); /* . o . . | o . . . */
DEF_COMBO_INPUT_KC(E, R); /* . . o . | . o . . */
DEF_COMBO_INPUT_KC(N, S); /* . . . o | . . o . */
DEF_COMBO_INPUT_KC(O, R); /* o . . . | . o . . */
DEF_COMBO_INPUT_KC(I, S); /* . o . . | . . o . */
DEF_COMBO_INPUT_KC(E, T); /* . . o . | . . . o */

combo_t key_combos[COMBO_COUNT] = {
  DEF_COMBO_TARGET_KC(O, I, F),   /* o o . . | . . . . */
  DEF_COMBO_TARGET_KC(I, E, C),   /* . o o . | . . . . */
  DEF_COMBO_TARGET_KC(E, N, U),   /* . . o o | . . . . */
  DEF_COMBO_TARGET_KC(O, N, ENT), /* o . . o | . . . . */
  DEF_COMBO_TARGET_KC(O, E, Z),   /* o . o . | . . . . */
  DEF_COMBO_TARGET_KC(I, N, J),   /* . o . o | . . . . */
  DEF_COMBO_TARGET_KC(A, R, W),   /* . . . . | o o . . */
  DEF_COMBO_TARGET_KC(R, S, H),   /* . . . . | . o o . */
  DEF_COMBO_TARGET_KC(S, T, D),   /* . . . . | . . o o */
  DEF_COMBO_TARGET_KC(A, T, SPC), /* . . . . | o . . o */
  DEF_COMBO_TARGET_KC(A, S, Q),   /* . . . . | o . o . */
  DEF_COMBO_TARGET_KC(R, T, K),   /* . . . . | . o . o */
  DEF_COMBO_TARGET_KC(I, A, B),   /* . o . . | o . . . */
  DEF_COMBO_TARGET_KC(E, R, G),   /* . . o . | . o . . */
  DEF_COMBO_TARGET_KC(N, S, Y),   /* . . . o | . . o . */
  DEF_COMBO_TARGET_KC(O, R, V),   /* o . . . | . o . . */
  DEF_COMBO_TARGET_KC(I, S, M),   /* . o . . | . . o . */
  DEF_COMBO_TARGET_KC(E, T, P),   /* . . o . | . . . o */
};

void keyboard_post_init_user(void) {
  combo_disable();
}
#endif

bool onehand_process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* switch (keycode) { */
  /* case MC_SHOT: // MacOS: take screenshot */
  /*   if (record->event.pressed) { SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT("4")))); } */
  /*   break; */
  /* } */
  return true;
}

