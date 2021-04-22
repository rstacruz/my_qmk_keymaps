/*
 * https://beta.docs.qmk.fm/developing-qmk/qmk-reference/config_options#the-config-h-file
 * https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold
 */

#pragma once
#define FORCE_NKRO
#define PERMISSIVE_HOLD
#define TAPPING_TOGGLE 2
#define ONESHOT_TIMEOUT 750
#define DYNAMIC_KEYMAP_LAYER_COUNT 7 // For via

// For hold-tap mods
// #define TAPPING_TERM 200
// #define IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

/* #define TAPPING_TERM 190 */
#define TAPPING_TERM 150
#define TAPPING_TERM_LONG 135
#define TAPPING_TERM_PER_KEY

// Extra settings
#define RETRO_TAPPING
// #define TAPPING_FORCE_HOLD

/*
 *  keys
 * https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_mouse_keys
 */

/* #define MOUSEKEY_DELAY 50 */
/* #define MOUSEKEY_INTERVAL 40 */
/* #define MOUSEKEY_TIME_TO_MAX 7 */
/* #define MOUSEKEY_MAX_SPEED 20 */
/* #define MOUSEKEY_WHEEL_DELAY 0 */

// Miryoku settings
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_WHEEL_DELAY    0
#define MOUSEKEY_MAX_SPEED      6
#define MOUSEKEY_TIME_TO_MAX    32

/*
 * Combo
 */

#define COMBO_COUNT 3
#define COMBO_TERM 25

#ifdef AUDIO_ENABLE
  #define X_1UP E__NOTE(_E6), E__NOTE(_G6), E__NOTE(_E7), E__NOTE(_C7), E__NOTE(_D7), E__NOTE(_G7)
  #define STARTUP_SONG SONG(X_1UP)
#endif
