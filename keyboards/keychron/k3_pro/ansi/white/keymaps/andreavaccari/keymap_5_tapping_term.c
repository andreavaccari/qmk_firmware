#pragma once

#ifdef TAPPING_TERM_PER_KEY

#include "keymap_3_tap_dances.c"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD_F1:
        case TD_F2:
        case TD_F3:
        case TD_F4:
            return 160;
        case TD_LSFT:
            return 200;
        default:
            return TAPPING_TERM;
    }
}

#endif
