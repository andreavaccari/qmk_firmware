#pragma once

#include "keymap_1_simple_keycodes.h"
#include "keymap_2_custom_keycodes.c"

enum combos {
  F_J__ESC,
  EQL_BSPC__DEL,
  F1_F2__BRIMID,
  F3_F4__BRIMIDC,
  // Keep last
  COMBO_LENGTH,
};

const uint16_t PROGMEM combo_f_j[]      = {MT_F_LSFT, MT_J_RSFT, COMBO_END};
const uint16_t PROGMEM combo_eql_bspc[] = {KC_EQL   , KC_BSPC  , COMBO_END};
const uint16_t PROGMEM combo_f1_f2[]    = {CK_BRID_F1, CK_BRIU_F2 , COMBO_END};
const uint16_t PROGMEM combo_f3_f4[]    = {CK_BRIDC_F3, CK_BRIUC_F4, COMBO_END};

combo_t key_combos[] = {
  [F_J__ESC]       = COMBO(combo_f_j      , KC_ESC),
  [EQL_BSPC__DEL]  = COMBO(combo_eql_bspc , KC_DEL),
  [F1_F2__BRIMID]  = COMBO(combo_f1_f2    , CK_BRIMID),
  [F3_F4__BRIMIDC] = COMBO(combo_f3_f4    , CK_BRIMIDC),
};

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case F_J__ESC:
            // F and J are home-row mods. Require a real tap combo so rolling
            // Shift chords still produce shifted F/J instead of Esc.
            return true;
        default:
            return false;
    }
}
