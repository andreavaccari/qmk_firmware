#pragma once

// Tap: Space. Hold: Mac Navigation.
#define LT_SPC_LMN     LT(LMN, KC_SPC)

// Standard modifier keys activate the Mac Pure layer while held.
#define LM_LCTL_LMP    LM(LMP, MOD_LCTL)
#define LM_LOPT_LMP    LM(LMP, MOD_LALT)
#define LM_LSFT_LMP    LM(LMP, MOD_LSFT)
#define LM_LCMD_LMP    LM(LMP, MOD_LGUI)
#define LM_RCTL_LMP    LM(LMP, MOD_RCTL)
#define LM_ROPT_LMP    LM(LMP, MOD_RALT)
#define LM_RSFT_LMP    LM(LMP, MOD_RSFT)
#define LM_RCMD_LMP    LM(LMP, MOD_RGUI)

// Home-row mods. MT() takes MOD_* masks, not KC_* keycodes.
#define MT_A_LCTL      MT(MOD_LCTL, KC_A)      // Equiv. LCTL_T(KC_A)
#define MT_S_LOPT      MT(MOD_LALT, KC_S)      // Equiv. LALT_T(KC_S)
#define MT_D_LCMD      MT(MOD_LGUI, KC_D)      // Equiv. LGUI_T(KC_D)
#define MT_F_LSFT      MT(MOD_LSFT, KC_F)      // Equiv. LSFT_T(KC_F)
#define MT_J_RSFT      MT(MOD_RSFT, KC_J)      // Equiv. RSFT_T(KC_J)
#define MT_K_RCMD      MT(MOD_RGUI, KC_K)      // Equiv. RGUI_T(KC_K)
#define MT_L_ROPT      MT(MOD_RALT, KC_L)      // Equiv. RALT_T(KC_L)
#define MT_SC_RCTL     MT(MOD_RCTL, KC_SCLN)   // Equiv. RCTL_T(KC_SCLN)
