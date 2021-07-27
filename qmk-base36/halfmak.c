#define HALFMAK_ENABLE

#define LAYOUT_halfmak_18( \
  k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, \
  k11, k12, k13, k14, k15, k16, k17, k18) \
LAYOUT_36( \
  k01, k02, k03, k04, k05, /**/ ___,    ___, ___, ___, ___, \
  k06, k07, k08, k09, k10, /**/ ___,    ___, ___, ___, ___, \
  k11, k12, k13, k14, k15, /**/ ___,    ___, ___, ___, ___, \
  /**/ /**/ k16, k17, k18, /**/ HM_OFF, ___, ___  \
)

/* ┌ base ─────┐ ┌ flip ─────┐ ┌ nav ──────┐ ┌ num ──────┐
 * │ o i e n m │ │ q w f v j │ │   ↓ ▲ ↑ ⎋ │ │ ^ ⌥ ⌘   ↑ │
 * │ a r s t ▲ │ │ p b y l ▲ │ │ ↵ ◀ ▼ ▶ ⇥ │ │ 1 2 3 4 5 │
 * │ g d u h ⌫ │ │ ↑ k c x z │ │ ‹         │ │ 6 7 8 9 0 │
 * ├───┬───┬───┤ └───────────┘ └───────────┘ └───────────┘
 * │num│nav│ ␣ │
 * └───┴───┴───┘ */

#define HM_BASE_LAYOUT LAYOUT_halfmak_18( \
  KC_O, KC_I, KC_E, KC_N, KC_M,         \
  KC_A, KC_R, KC_S, KC_T, OSL(HM_FLIP), \
  KC_G, KC_D, KC_U, KC_H, KC_BSPC,      \
  MO(HM_NUM), LT(HM_NAV,KC_BSPC), KC_SPC )

#define HM_FLIP_LAYOUT LAYOUT_halfmak_18( \
  KC_Q,    KC_W, KC_F, KC_V, KC_J,    \
  KC_P,    KC_B, KC_Y, KC_L, os_LSFT, \
  os_LSFT, KC_K, KC_C, KC_X, KC_Z,    \
  _v_,  _v_,  _v_)

#define HM_NAV_LAYOUT LAYOUT_halfmak_18( \
  KC_LCTL, KC_PGUP, KC_UP,   KC_PGDN, KC_ESC, \
  KC_ENT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB, \
  HM_OFF,  ___,     ___,     ___,     ___,    \
  _v_,  _v_,  _v_)

#define HM_NUM_LAYOUT LAYOUT_halfmak_18( \
  os_LCTL, os_LGUI, os_LALT, ___,  os_LSFT, \
  KC_1,    KC_2,    KC_3,    KC_4, KC_5,    \
  KC_6,    KC_7,    KC_8,    KC_9, KC_0,    \
  _v_,  _v_,  _v_)

#define HM_SYM1_LAYOUT /* TODO */
#define HM_SYM2_LAYOUT /* TODO */

bool oneshotmods_process_record_user(uint16_t keycode, keyrecord_t *record);

bool hm_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case HM_ON: // enable
      if (record->event.pressed) {
        layer_on(HM_BASE);
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(191, 255, 50);
      }
      return false;
      break;
    case HM_OFF: // disable
      if (record->event.pressed) {
        layer_off(HM_BASE);
        rgblight_disable_noeeprom();
      }
      return false;
      break;
  }
  return oneshotmods_process_record_user(keycode, record);
}

bool oneshotmods_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case os_LCTL:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_LCTL); register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
      }
      return false;
      break;
    case os_LGUI:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_LGUI); register_code(KC_LGUI);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case os_LALT:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_LALT); register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
      }
      return false;
      break;
    case os_LSFT:
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
