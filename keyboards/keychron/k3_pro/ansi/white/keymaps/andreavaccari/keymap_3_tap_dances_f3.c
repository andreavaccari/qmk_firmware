#include "keymap_3_tap_dances_base.c"

static td_tap_t f3_td_tap = {.is_press_action = true, .state = TD_NONE};

void finished_f3(tap_dance_state_t *state, void *user_data) {
    f3_td_tap.state = current_dance(state);
    switch (f3_td_tap.state) {
        case TD_SINGLE_TAP:
            register_code16(LCTL(KC_BRID));
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_F3);
            break;
        case TD_DOUBLE_TAP:
            break;
        default:
            break;
    }
}

void reset_f3(tap_dance_state_t *state, void *user_data) {
    switch (f3_td_tap.state) {
        case TD_SINGLE_TAP:
            unregister_code16(LCTL(KC_BRID));
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
            for (int i = 0; i < 16; ++i) tap_code16(LCTL(KC_BRID));
            break;
        default:
            break;
    }
    f3_td_tap.state = TD_NONE;
}
