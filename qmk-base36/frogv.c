/*
     ┌────────────────────┐     ● ┌────────────────────┐
base │ s↔  c   n   i   g  │  flip │ q   w   m   j   k  │
     │ ●   t   h   e   o  │       │ ▓▓  p   l   x   ⇧  │
     │ f∴  d   r   a   u  │       │     b   v   y   z  │
     └────────────────────┤       └────────────────────┤
         │ ⌃  │₁₂₃ │  ␣   │           │ ⌥  │ ⌘  │  ⇧   │  ⌃  ctrl (1-tap)
         └────┴────┴──────┘           └────┴────┴──────┘     cmd/alt (2)
  ↔  ┌────────────────────┐   ₁₂₃ ┌────────────────────┐
nav  │ ▓▓  p↑  ▲   p↓  ⌫  │   num │ MK      ⌘   ⇧  exit│
     │     ◀   ▼   ▶   ↵  │       │ 1   2   3   4   5  │
     │     hm  en  ↹   ⎋  │       │ 6   7   8   9   0  │
     └────────────────────┤       └────────────────────┤
         │ ⌃  │ MK │  ⇧   │           │ ⌥  │ ▓▓ │  ⌃   │
         └────┴────┴──────┘           └────┴────┴──────┘
  ∴  ┌────────────────────┐       ┌────────────────────┐
sym  │     !   [   ]   \  │    mk │ ▓▓  w↑  ▲   w↓     │
     │     `   =   -   /  │       │     ◀   ▼   ▶      │
     │ ▓▓  ;   ,   .   '  │       │         R   L      │
     └────────────────────┤       └────────────────────┤
         │    │    │  ⇧   │           │    │ ▓▓ │      │
         └────┴────┴──────┘           └────┴────┴──────┘
*/

#define FROGV_ENABLE

#ifndef FV_HSV_COLOR
#define FV_HSV_COLOR 191, 255, 50
#endif

#ifdef AUDIO_ENABLE
#define FROGV_ON TD_NOTE(_A5), SD_NOTE(_A0), TD_NOTE(_E6)
#define FROGV_OFF TD_NOTE(_E6), SD_NOTE(_A0), TD_NOTE(_A5)
float frogv_on_song[][2] = SONG(FROGV_ON);
float frogv_off_song[][2] = SONG(FROGV_OFF);
#endif

#ifdef LAYOUT_36
#define LAYOUT_FROGV_18( \
  k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, \
  k11, k12, k13, k14, k15, k16, k17, k18) \
LAYOUT_36( \
  k01, k02, k03, k04, k05, /**/ ___,    ___, ___, ___, ___, \
  k06, k07, k08, k09, k10, /**/ ___,    ___, ___, ___, ___, \
  k11, k12, k13, k14, k15, /**/ ___,    ___, ___, ___, ___, \
  /**/ /**/ k16, k17, k18, /**/ FV_OFF, ___, ___  \
)
#else
#error "A LAYOUT_FROGV_18 macro needs to be defined"
#endif

#ifdef TAP_DANCE_ENABLE
#define FV_CTRL TD(TD_CTRL)
#else
#define FV_CTRL KC_LCTL
#endif

#define FV_BASE_LAYOUT LAYOUT_FROGV_18( \
  LT(FV_NAV,KC_S), KC_C, KC_N,    KC_I,       KC_G,  \
  OSL(FV_FLIP),    KC_T, KC_H,    KC_E,       KC_O,  \
  LT(FV_SYM,KC_F), KC_D, KC_R,    KC_A,       KC_U,  \
  /**/             /**/  FV_CTRL, MO(FV_NUM), KC_SPC )

#define FV_FLIP_LAYOUT LAYOUT_FROGV_18( \
  KC_Q, KC_W, KC_M,    KC_J,    KC_K,    \
  ___,  KC_P, KC_L,    KC_X,    FV_OSSF, \
  ___,  KC_B, KC_V,    KC_Y,    KC_Z,    \
  /**/  /**/  FV_CTRL, FV_LGUI, FV_LSFT  )

#define FV_NAV_LAYOUT LAYOUT_FROGV_18( \
  ___, KC_PGUP, KC_UP,   KC_PGDN,    KC_BSPC, \
  ___, KC_LEFT, KC_DOWN, KC_RGHT,    KC_ENT,  \
  ___, KC_HOME, KC_END,  KC_TAB,     KC_ESC,  \
  /**/ /**/     _v_,     MO(FV_MOU), KC_LSFT  )

#define FV_NUM_LAYOUT LAYOUT_FROGV_18( \
  MO(FV_MOU), ___,  KC_LGUI, KC_LSFT, FV_OFF, \
  KC_1,       KC_2, KC_3,    KC_4,    KC_5,   \
  KC_6,       KC_7, KC_8,    KC_9,    KC_0,   \
  /**/        /**/  KC_LALT, _v_,     FV_CTRL )

#define FV_SYM_LAYOUT LAYOUT_FROGV_18( \
  ___, KC_EXLM, KC_LBRC, KC_RBRC, KC_BSLS, \
  ___, KC_GRV,  KC_EQL,  KC_MINS, KC_SLSH, \
  ___, KC_SCLN, KC_COMM, KC_DOT,  KC_QUOT, \
  /**/ /**/     _v_,     _v_,     KC_LSFT  )

#define FV_MOU_LAYOUT LAYOUT_FROGV_18( \
  ___, KC_WH_U, KC_MS_U,    KC_WH_D,    ___,        \
  ___, KC_MS_L, KC_MS_D,    KC_MS_R,    ___,        \
  ___, ___,     KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3, \
  /**/ /**/     _v_,        _v_,        _v_         )

bool fm_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Substitute mod keys that can be used in one-shot layers
    case FV_LSFT:
      if (record->event.pressed) { register_code(KC_LSFT); }
      else { unregister_code(KC_LSFT); } return false;
    case FV_LCTL:
      if (record->event.pressed) { register_code(KC_LCTL); }
      else { unregister_code(KC_LCTL); } return false;
    case FV_LGUI:
      if (record->event.pressed) { register_code(KC_LGUI); }
      else { unregister_code(KC_LGUI); } return false;
    case FV_LALT:
      if (record->event.pressed) { register_code(KC_LALT); }
      else { unregister_code(KC_LALT); } return false;
    case FV_OSSF:
      if (record->event.pressed) { set_oneshot_mods(MOD_LSFT); }
      return false;

    // Enable or disable the onehand mode
    case FV_ON:
      if (record->event.pressed) {
        layer_on(FV_BASE);
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable_noeeprom();
          rgblight_sethsv_noeeprom(FV_HSV_COLOR);
        #endif
        #ifdef AUDIO_ENABLE
          PLAY_SONG(frogv_on_song);
        #endif
      }
      return false;
      break;
    case FV_OFF:
      if (record->event.pressed) {
        layer_off(FV_BASE);
        #ifdef RGBLIGHT_ENABLE
          rgblight_disable_noeeprom();
        #endif
        #ifdef AUDIO_ENABLE
          PLAY_SONG(frogv_off_song);
        #endif
      }
      return false;
      break;
  }
  return true;
}

#ifdef TAP_DANCE_ENABLE
// Tap-dance keys
enum {
  TD_CTRL = 0
};

// Definitions
void dance_ctrl_done(qk_tap_dance_state_t *state, void *user_data);
void dance_ctrl_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_space_done(qk_tap_dance_state_t *state, void *user_data);
void dance_space_reset(qk_tap_dance_state_t *state, void *user_data);

// Define tap dances
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_ctrl_done, dance_ctrl_reset, 225)
};

void dance_ctrl_done(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) { register_code(KC_LCTL); }
  else if (state->count == 2) { register_code(KC_LALT); }
  else if (state->count == 3) { register_code(KC_LALT); register_code(KC_LCTL); }
}

void dance_ctrl_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) { unregister_code(KC_LCTL); }
  else if (state->count == 2) { unregister_code(KC_LALT); }
  else if (state->count == 3) { unregister_code(KC_LALT); unregister_code(KC_LCTL); }
}
#endif
