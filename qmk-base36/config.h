/*
 * https://beta.docs.qmk.fm/developing-qmk/qmk-reference/config_options#the-config-h-file
 * https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold
 */

#pragma once
#define FORCE_NKRO
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD /* allow tap then hold (eg, a a+r) */
#define TAPPING_TOGGLE 2
#define ONESHOT_TIMEOUT 500

// For hold-tap mods
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_TERM 125

/* Mouse keys */
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          16
#define MOUSEKEY_WHEEL_DELAY       0
#define MOUSEKEY_MAX_SPEED         6
#define MOUSEKEY_TIME_TO_MAX       32
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 8

/* Audio */
#ifdef AUDIO_ENABLE
  #define X_HI T__NOTE(_D5), T__NOTE(_E5), T__NOTE(_GF5), T__NOTE(_B5)
  #define X_BYE T__NOTE(_B5), TD_NOTE(_A0), T__NOTE(_GF5), TD_NOTE(_A0), T__NOTE(_E5), TD_NOTE(_A0), T__NOTE(_D5), TD_NOTE(_A0), T__NOTE(_C5)
  #define STARTUP_SONG SONG(X_HI)
  #define GOODBYE_SONG SONG(X_BYE)
#endif

/* Layout */
#ifdef KEYBOARD_planck
#define HM_HSV_COLOR 191, 255, 255
#define LAYOUT_36( \
  a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, \
  b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, \
  c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, \
  d1, d2, d3, d4, d5, d6 \
) \
  LAYOUT_planck_2x2u( \
    a1,  a2,  a3, a4, a5,  ___, ___, a6,  a7, a8, a9,  a10, \
    b1,  b2,  b3, b4, b5,  ___, ___, b6,  b7, b8, b9,  b10, \
    c1,  c2,  c3, c4, c5,  ___, ___, c6,  c7, c8, c9,  c10, \
    ___, ___, d1, d2, /**/ d3,  d4,  /**/ d5, d6, ___, ___  \
  )
#define LAYOUT_46( \
  a1, a2, a3, a4, a5, aA,  aB,  a6, a7, a8, a9, a10, \
  b1, b2, b3, b4, b5, bA,  bB,  b6, b7, b8, b9, b10, \
  c1, c2, c3, c4, c5, cA,  cB,  c6, c7, c8, c9, c10, \
  dA, dB, d1, d2, d3, /**/ /**/ d4, d5, d6, dC, dD \
) \
  LAYOUT_planck_grid( \
    a1, a2, a3, a4, a5, aA,  aA,  a6, a7, a8, a9, a10, \
    b1, b2, b3, b4, b5, bA,  bA,  b6, b7, b8, b9, b10, \
    c1, c2, c3, c4, c5, cA,  cB,  c6, c7, c8, c9, c10, \
    dA, dB, d1, d2, d3, d3,  d4,  d4, d5, d6, dC, dD \
  )
#endif

#ifdef KEYBOARD_crkbd
/* #define DEBOOUNCE 9 */
#define LAYOUT_36( \
  a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, \
  b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, \
  c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, \
  d1, d2, d3, d4, d5, d6 \
) \
  LAYOUT_split_3x6_3( \
    ___, a1,  a2,  a3, a4, a5, a6, a7, a8, a9,  a10, ___, \
    ___, b1,  b2,  b3, b4, b5, b6, b7, b8, b9,  b10, ___, \
    ___, c1,  c2,  c3, c4, c5, c6, c7, c8, c9,  c10, ___, \
    d1, d2, d3, d4, d5, d6 \
  )
#define LAYOUT_46( \
  a1, a2, a3, a4, a5, aA,  aB,  a6, a7, a8, a9, a10, \
  b1, b2, b3, b4, b5, bA,  bB,  b6, b7, b8, b9, b10, \
  c1, c2, c3, c4, c5, cA,  cB,  c6, c7, c8, c9, c10, \
  dA, dB, d1, d2, d3, /**/ /**/ d4, d5, d6, dC, dD \
) \
  LAYOUT_split_3x6_3( \
    ___, a1,  a2,  a3, a4, a5, a6, a7, a8, a9,  a10, ___, \
    ___, b1,  b2,  b3, b4, b5, b6, b7, b8, b9,  b10, ___, \
    ___, c1,  c2,  c3, c4, c5, c6, c7, c8, c9,  c10, ___, \
    d1, d2, d3, d4, d5, d6 \
  )
#define EE_HANDS
#endif

/* Combo settings */
#define COMBO_TERM 25
#define COMBO_COUNT 8

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
