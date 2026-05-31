#include "keymap_3_tap_dances_base.c"

static td_tap_t f4_td_tap = {.is_press_action = true, .state = TD_NONE};

void finished_f4(tap_dance_state_t *state, void *user_data) {
    f4_td_tap.state = current_dance(state);
    switch (f4_td_tap.state) {
        case TD_SINGLE_TAP:
            register_code16(LCTL(KC_BRIU));
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_F4);
            break;
        case TD_DOUBLE_TAP:
            break;
        default:
            break;
    }
}

void reset_f4(tap_dance_state_t *state, void *user_data) {
    switch (f4_td_tap.state) {
        case TD_SINGLE_TAP:
            unregister_code16(LCTL(KC_BRIU));
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
            for (int i = 0; i < 16; ++i) tap_code16(LCTL(KC_BRIU));
            break;
        default:
            break;
    }
    f4_td_tap.state = TD_NONE;
}
