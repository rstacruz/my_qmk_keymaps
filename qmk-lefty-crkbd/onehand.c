#ifdef COMBO_TERM

#define DEF_COMBO_INPUT_KC(A,B) \
  const uint16_t PROGMEM combo_ ## A ## B[] = {KC_ ## A, KC_ ## B, COMBO_END}
#define DEF_COMBO_TARGET_KC(A,B,TARGET) \
  COMBO(combo_ ## A ## B, TARGET)

DEF_COMBO_INPUT_KC(O, I);
DEF_COMBO_INPUT_KC(I, E);
DEF_COMBO_INPUT_KC(E, N);
DEF_COMBO_INPUT_KC(A, R);

combo_t key_combos[COMBO_COUNT] = {
  DEF_COMBO_TARGET_KC(O, I, KC_F),
  DEF_COMBO_TARGET_KC(I, E, KC_C),
  DEF_COMBO_TARGET_KC(E, N, KC_U),
  DEF_COMBO_TARGET_KC(A, R, KC_W),
};

void keyboard_post_init_user(void) {
  combo_disable();
}
#endif
