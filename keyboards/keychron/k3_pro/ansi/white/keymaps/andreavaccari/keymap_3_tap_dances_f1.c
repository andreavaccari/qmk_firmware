#include "keymap_3_tap_dances_base.c"

static td_tap_t f1_td_tap = {.is_press_action = true, .state = TD_NONE};

void finished_f1(tap_dance_state_t *state, void *user_data) {
    f1_td_tap.state = current_dance(state);
    switch (f1_td_tap.state) {
        case TD_SINGLE_TAP:
            register_code(KC_BRID);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_F1);
            break;
        case TD_DOUBLE_TAP:
            break;
        default:
            break;
    }
}

void reset_f1(tap_dance_state_t *state, void *user_data) {
    switch (f1_td_tap.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_BRID);
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
            wait_ms(10);
            for (int i = 0; i < 16; ++i) tap_code(KC_BRID);
            break;
        default:
            break;
    }
    f1_td_tap.state = TD_NONE;
}
