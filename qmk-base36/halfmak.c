#define LAYOUT_halfmak_18( \
  k01, k02, k03, k04, k05, k06, k07, k08, k09, \
  k11, k12, k13, k14, k15, k16, k17, k18) \
LAYOUT_36( \
  k01, k02, k03, k04, k05, /**/ ___, ___, ___, ___, ___, \
  k06, k07, k08, k09, k10, /**/ ___, ___, ___, ___, ___, \
  k11, k12, k13, k14, k15, /**/ ___, ___, ___, ___, ___, \
  /**/ /**/ k16, k17, k18, /**/ ___, ___, ___  \
)

#define HM_BASE_LAYOUT LAYOUT_halfmak_18( \
  KC_O,    KC_I, KC_E, KC_N, OSM(MOD_LSFT), \
  KC_A,    KC_R, KC_S, KC_T, KC_U,          \
  KC_BSPC, KC_M, KC_G, KC_D, KC_H,          \
  ___, OSL(HM_FLIP), KC_SPC)

#define HM_FLIP_LAYOUT LAYOUT_halfmak_18( \
  KC_Z, KC_P, KC_F, KC_W, KC_Q, \
  ___,  KC_B, KC_L, KC_Y, KC_J, \
  ___,  KC_X, KC_C, KC_K, KC_V, \
  _v_,  _v_,  _v_)

#define HM_NAV LAYOUT_halfmak_18( \
  os_LCTL, KC_PGUP, KC_UP,   KC_PGDN, ___, \
  os_LALT, KC_LEFT, KC_DOWN, KC_RGHT, ___, \
  os_LGUI, KC_ESC,  KC_ENT,  KC_TAB,  ___, \
  _v_,  _v_,  _v_)

#define HM_NUM /* TODO */
#define HM_SYM1 /* TODO */
#define HM_SYM2 /* TODO */

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
