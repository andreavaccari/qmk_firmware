#include "keymap_3_tap_dances_base.c"
#include "keymap_0_layers.h"

static td_tap_t lsft_td_tap = {.is_press_action = true, .state = TD_NONE};

void finished_lsft(tap_dance_state_t *state, void *user_data) {
    lsft_td_tap.state = current_dance(state);
    switch (lsft_td_tap.state) {
        case TD_SINGLE_TAP:
            caps_word_off();
            if (host_keyboard_led_state().caps_lock) {
                tap_code(KC_CAPS);
            }
            break;
        case TD_DOUBLE_TAP:
            caps_word_on();
            break;
        case TD_TRIPLE_TAP:
            tap_code(KC_CAPS);
            break;
        default:
            layer_on(LMP);
            register_code(KC_LSFT);
    }
}

void reset_lsft(tap_dance_state_t *state, void *user_data) {
    switch (lsft_td_tap.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_TRIPLE_TAP:
            break;
        default:
            unregister_code(KC_LSFT);
            layer_off(LMP);
    }
    lsft_td_tap.state = TD_NONE;
}
