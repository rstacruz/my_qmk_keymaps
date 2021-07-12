  /* ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄
  Gaming    ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
  mode      │ q  │ w  │ e  │ r  │ ↹  │     │    │    │ ▲  │    │ ⎋  │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ a  │ s  │ d  │ f  │ ⇧  │     │    │ ◀  │ ▼  │ ▶  │ ↵  │
  ┌┄┄┄┄┐    ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
  ┆gam ┆ ┄› │ z  │ x  │ c  │ v  │ ⌃  │     │    │    │    │    │exit│
  └┄┄┄┄┘    └────┴────┴────┴────┴───┄┴──┬──┴────┴────┴────┴────┴────┘
                      │alt │ ↑  │   ␣   │       │    │    │
                      └────┴────┴───────┴───────┴────┴────┘
  Game+     ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
            │ 1  │ 2  │ 3  │ 4  │ `  │     │    │    │    │    │    │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │ 5  │ 6  │ 7  │ g  │ h  │     │    │    │    │    │    │
            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
            │    │ y  │ p  │ b  │    │     │    │    │    │    │    │
            └────┴────┴────┴────┴────┴─────┴────┴────┴────┴────┴────┘ */

#define GAM_LAYER LAYOUT_36( \
  KC_Q, KC_W, KC_E,    KC_R,      KC_TAB,  /**/ ___, ___,     KC_UP,   ___,     KC_ESC, \
  KC_A, KC_S, KC_D,    KC_F,      KC_LSFT, /**/ ___, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, \
  KC_Z, KC_X, KC_C,    KC_V,      KC_LCTL, /**/ ___, ___,     ___,     ___,     DF(0),  \
  /**/  /**/  KC_LALT, OSL(_GMX), KC_SPC,  /**/ ___, ___,     DF(0)    /**/     /**/    \
)

#define GMX_LAYER LAYOUT_36( \
  KC_1, KC_2, KC_3, KC_4, KC_GRV, /**/ ___, ___, ___, ___, ___, \
  KC_5, KC_6, KC_7, KC_G, KC_H,   /**/ ___, ___, ___, ___, ___, \
  _v_,  KC_Y, KC_P, KC_B, _v_,    /**/ ___, ___, ___, ___, ___, \
  /**/  /**/  _v_,  _v_,  _v_,    /**/ _v_, _v_, _v_  /**/ /**/ \
)
