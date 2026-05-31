#pragma once

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_SINGLE_INTERRUPTED,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_INTERRUPTED, // Send 2 single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
    TD_TRIPLE_INTERRUPTED  // Send 3 single taps
} td_state_t;

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t current_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted)
            return TD_SINGLE_INTERRUPTED;
        else if (state->pressed)
            return TD_SINGLE_HOLD;
        else
            return TD_SINGLE_TAP;
    }
    if (state->count == 2) {
        if (state->interrupted)
            return TD_DOUBLE_INTERRUPTED;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted)
            return TD_TRIPLE_INTERRUPTED;
        else if (state->pressed)
            return TD_TRIPLE_HOLD;
        else
            return TD_TRIPLE_TAP;

    }
    return TD_UNKNOWN;
}
