#pragma once

#include "keymap_0_layers.h"

// Custom keys that only support tap.
enum custom_keycodes {
  CK_BRIMID = NEW_SAFE_RANGE,
  CK_BRIMIDC,
};

// Custom keys that support both tap and hold.
// Keep these as LT(0, ...) keys so QMK marks them as dual-role and gives
// process_record_user() tap-vs-hold state for unsupported tap keycodes.
// The layer argument is only a carrier for QMK's tap-hold state. The custom
// handler returns false before LT() can activate the carrier layer on hold.
#define CK_BRID_F1     LT(0, KC_F1)
#define CK_BRIU_F2     LT(0, KC_F2)
#define CK_BRIDC_F3    LT(0, KC_F3)
#define CK_BRIUC_F4    LT(0, KC_F4)
#define CK_BLD_F5      LT(0, KC_F5)
#define CK_BLU_F6      LT(0, KC_F6)
#define CK_MPRV_F7     LT(0, KC_MPRV)
#define CK_MPLY_F8     LT(0, KC_MPLY)
#define CK_MNXT_F9     LT(0, KC_MNXT)
#define CK_MUTE_FA     LT(0, KC_MUTE)
#define CK_VOLD_FB     LT(0, KC_VOLD)
#define CK_VOLU_FC     LT(0, KC_VOLU)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_BRIMID:
            // On tap: Set built-in display brightness to 50%
            if (record->event.pressed) {
                for (uint8_t i = 0; i < 16; ++i) tap_code16_delay(KC_BRID, 10);
                for (uint8_t i = 0; i < 8; ++i) tap_code16_delay(KC_BRIU, 10);
            }
            // Otherwise: do nothing.
            return false;

        case CK_BRIMIDC:
            // On tap: Set external display brightness to 50%
            if (record->event.pressed) {
                for (uint8_t i = 0; i < 16; ++i) tap_code16_delay(LCTL(KC_BRID), 10);
                for (uint8_t i = 0; i < 8; ++i) tap_code16_delay(LCTL(KC_BRIU), 10);
            }
            // Otherwise: do nothing.
            return false;

        case CK_BRID_F1:
            // On tap: Act like KC_BRID.
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code(KC_BRID);
                } else {
                    unregister_code(KC_BRID);
                }
            }
            // On hold: Send F1.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F1);
            }
            // Otherwise: do nothing.
            return false;

        case CK_BRIU_F2:
            // On tap: Act like KC_BRIU.
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code(KC_BRIU);
                } else {
                    unregister_code(KC_BRIU);
                }
            }
            // On hold: Send F2.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F2);
            }
            // Otherwise: do nothing.
            return false;

        case CK_BRIDC_F3:
            // On tap: Act like KC_BRID+KC_LCTL.
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code(KC_LCTL);
                    wait_ms(10);
                    register_code(KC_BRID);
                } else {
                    unregister_code(KC_BRID);
                    unregister_code(KC_LCTL);
                }
            }
            // On hold: Send F3.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F3);
            }
            // Otherwise: do nothing.
            return false;

        case CK_BRIUC_F4:
            // On tap: Act like KC_BRIU+KC_LCTL.
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code(KC_LCTL);
                    wait_ms(10);
                    register_code(KC_BRIU);
                } else {
                    unregister_code(KC_BRIU);
                    unregister_code(KC_LCTL);
                }
            }
            // On hold: Send F4.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F4);
            }
            // Otherwise: do nothing.
            return false;

        case CK_BLD_F5:
            // On tap: Decrease keyboard backlight.
            if (record->tap.count > 0 && record->event.pressed) {
                // K3 Pro white uses LED Matrix; QK_BACKLIGHT_DOWN is handled by process_led_matrix.c in wls_2025q1.
                // Direct call is intentional: tap_code16(QK_BACKLIGHT_DOWN) does not re-enter keycode processing.
                // https://github.com/Keychron/qmk_firmware/blob/wls_2025q1/quantum/process_keycode/process_led_matrix.c
                led_matrix_decrease_val();
            }
            // On hold: Send F5.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F5);
            }
            // Otherwise: do nothing.
            return false;

        case CK_BLU_F6:
            // On tap: Increase keyboard backlight.
            if (record->tap.count > 0 && record->event.pressed) {
                // K3 Pro white uses LED Matrix; QK_BACKLIGHT_UP is handled by process_led_matrix.c in wls_2025q1.
                // Direct call is intentional: tap_code16(QK_BACKLIGHT_UP) does not re-enter keycode processing.
                // https://github.com/Keychron/qmk_firmware/blob/wls_2025q1/quantum/process_keycode/process_led_matrix.c
                led_matrix_increase_val();
            }
            // On hold: Send F6.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F6);
            }
            // Otherwise: do nothing.
            return false;

        case CK_MPRV_F7:
            // On hold: Send F7.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F7);
                return false;
            }
            // Otherwise: default behavior (media prev).
            return true;

        case CK_MPLY_F8:
            // On hold: Send F8.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F8);
                return false;
            }
            // Otherwise: default behavior (media play).
            return true;

        case CK_MNXT_F9:
            // On hold: Send F9.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F9);
                return false;
            }
            // Otherwise: default behavior (media next).
            return true;

        case CK_MUTE_FA:
            // On hold: Send F10.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F10);
                return false;
            }
            // Otherwise: default behavior (volume mute).
            return true;

        case CK_VOLD_FB:
            // On hold: Send F11.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F11);
                return false;
            }
            // Otherwise: default behavior (volume dec).
            return true;

        case CK_VOLU_FC:
            // On hold: Send F12.
            if (record->tap.count == 0 && record->event.pressed) {
                tap_code(KC_F12);
                return false;
            }
            // Otherwise: default behavior (volume inc).
            return true;
    }

    // For all other keys, use default behavior.
    return true;
};
