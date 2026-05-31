#pragma once

#include "keymap_3_tap_dances_f1.c"
#include "keymap_3_tap_dances_f2.c"
#include "keymap_3_tap_dances_f3.c"
#include "keymap_3_tap_dances_f4.c"
#include "keymap_3_tap_dances_lsft.c"

enum {
  ACTION_F1,
  ACTION_F2,
  ACTION_F3,
  ACTION_F4,
  ACTION_LSFT,
};

tap_dance_action_t tap_dance_actions[] = {
  [ACTION_F1]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_f1, reset_f1),
  [ACTION_F2]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_f2, reset_f2),
  [ACTION_F3]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_f3, reset_f3),
  [ACTION_F4]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_f4, reset_f4),
  [ACTION_LSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_lsft, reset_lsft),
};

#define TD_F1   TD(ACTION_F1)   // tap → KC_BRID        ; hold → KC_F1 (currently unused but kept for reference)
#define TD_F2   TD(ACTION_F2)   // tap → KC_BRIU        ; hold → KC_F2 (currently unused but kept for reference)
#define TD_F3   TD(ACTION_F3)   // tap → KC_BRID+KC_LCTL; hold → KC_F3 (currently unused but kept for reference)
#define TD_F4   TD(ACTION_F4)   // tap → KC_BRIU+KC_LCTL; hold → KC_F4 (currently unused but kept for reference)
#define TD_LSFT TD(ACTION_LSFT) // tap → caps off       ; hold → LSFT+LMP; double tap → Caps Word; triple tap → Caps Lock
