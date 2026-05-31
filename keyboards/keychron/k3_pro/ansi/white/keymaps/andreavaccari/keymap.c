#include QMK_KEYBOARD_H

#include "keymap_0_layers.h"
#include "keymap_1_simple_keycodes.h"
#include "keymap_3_tap_dances.c"
#include "keymap_2_custom_keycodes.c"
#include "keymap_4_combos.c"
#include "keymap_5_tapping_term.c"

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_ansi_84(
    'L'         , 'L'         , 'L'         , 'L'         , 'L'         , 'L'         , 'L'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         ,
    'L'         , 'L'         , 'L'         , 'L'         , 'L'         , 'L'         , 'L'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'                       , 'R'         ,
    'L'         , 'L'         , 'L'         , 'L'         , 'L'         , 'L'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'                       , 'R'         ,
    'L'         , 'L'         , 'L'         , 'L'         , 'L'         , 'L'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'                       , 'R'                       , 'R'         ,
    'L'                       , 'L'         , 'L'         , 'L'         , 'L'         , '*'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'                       , 'R'         , 'R'         , 'R'         ,
    'L'         , 'L'         , 'L'                                                   , '*'                                                   , 'R'         , 'R'         , 'R'         , 'R'         , 'R'         , 'R'
);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LMB] = LAYOUT_ansi_84( // Layer Mac Base
    KC_ESC      , CK_BRID_F1  , CK_BRIU_F2  , CK_BRIDC_F3 , CK_BRIUC_F4 , CK_BLD_F5   , CK_BLU_F6   , CK_MPRV_F7  , CK_MPLY_F8  , CK_MNXT_F9  , CK_MUTE_FA  , CK_VOLD_FB  , CK_VOLU_FC  , BL_TOGG     , MO(LMF)     , KC_DEL      ,
    KC_GRV      , KC_1        , KC_2        , KC_3        , KC_4        , KC_5        , KC_6        , KC_7        , KC_8        , KC_9        , KC_0        , KC_MINS     , KC_EQL      , KC_BSPC                   , KC_HOME     ,
    KC_TAB      , KC_Q        , KC_W        , KC_E        , KC_R        , KC_T        , KC_Y        , KC_U        , KC_I        , KC_O        , KC_P        , KC_LBRC     , KC_RBRC     , KC_BSLS                   , KC_END      ,
    KC_BSPC     , MT_A_LCTL   , MT_S_LOPT   , MT_D_LCMD   , MT_F_LSFT   , KC_G        , KC_H        , MT_J_RSFT   , MT_K_RCMD   , MT_L_ROPT   , MT_SC_RCTL  , KC_QUOT                   , KC_ENT                    , KC_PGUP     ,
    TD_LSFT                   , KC_Z        , KC_X        , KC_C        , KC_V        , KC_B        , KC_N        , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH                   , LM_RSFT_LMP , KC_UP       , KC_PGDN     ,
    LM_LCTL_LMP , LM_LOPT_LMP , LM_LCMD_LMP                                           , LT_SPC_LMN                                            , LM_RCMD_LMP , LM_ROPT_LMP , LM_RCTL_LMP , KC_LEFT     , KC_DOWN     , KC_RGHT     ),

[LMF] = LAYOUT_ansi_84( // Layer Mac Function
    _______     , KC_F1       , KC_F2       , KC_F3       , KC_F4       , KC_F5       , KC_F6       , KC_F7       , KC_F8       , KC_F9       , KC_F10      , KC_F11      , KC_F12      , _______     , _______     , _______     ,
    _______     , BT_HST1     , BT_HST2     , BT_HST3     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______                   , _______     ,
    _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______                   , _______     ,
    KC_CAPS     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______                   , _______                   , _______     ,
    CW_TOGG                   , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______                   , _______     , _______     , _______     ,
    _______     , _______     , _______                                               , _______                                               , _______     , _______     , _______     , _______     , _______     , _______     ),

[LWB] = LAYOUT_ansi_84( // Layer Windows Base
    KC_ESC      , KC_F1       , KC_F2       , KC_F3       , KC_F4       , KC_F5       , KC_F6       , KC_F7       , KC_F8       , KC_F9       , KC_F10      , KC_F11      , KC_F12      , BL_TOGG     ,  MO(LWF)    , KC_DEL      ,
    KC_GRV      , KC_1        , KC_2        , KC_3        , KC_4        , KC_5        , KC_6        , KC_7        , KC_8        , KC_9        , KC_0        , KC_MINS     , KC_EQL      , KC_BSPC                   , KC_HOME     ,
    KC_TAB      , KC_Q        , KC_W        , KC_E        , KC_R        , KC_T        , KC_Y        , KC_U        , KC_I        , KC_O        , KC_P        , KC_LBRC     , KC_RBRC     , KC_BSLS                   , KC_END      ,
    KC_CAPS     , KC_A        , KC_S        , KC_D        , KC_F        , KC_G        , KC_H        , KC_J        , KC_K        , KC_L        , KC_SCLN     , KC_QUOT                   , KC_ENT                    , KC_PGUP     ,
    KC_LSFT                   , KC_Z        , KC_X        , KC_C        , KC_V        , KC_B        , KC_N        , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH                   , KC_RSFT     , KC_UP       , KC_PGDN     ,
    KC_LCTL     , KC_LGUI     , KC_LALT                                               , KC_SPC                                                , KC_RALT     , KC_RGUI     , KC_RCTL     , KC_LEFT     , KC_DOWN     , KC_RGHT     ),

[LWF] = LAYOUT_ansi_84( // Layer Windows Function
    _______     , KC_BRID     , KC_BRIU     , KC_TASK     , KC_FILE     , BL_DOWN     , BL_UP       , KC_MPRV     , KC_MPLY     , KC_MNXT     , KC_MUTE     , KC_VOLD     , KC_VOLU     , _______     , _______     , _______     ,
    _______     , BT_HST1     , BT_HST2     , BT_HST3     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______                   , _______     ,
    _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______                   , _______     ,
    KC_CAPS     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______                   , _______                   , _______     ,
    CW_TOGG                   , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______                   , _______     , _______     , _______     ,
    _______     , _______     , _______                                               , _______                                               , _______     , _______     , _______     , _______     , _______     , _______     ),

[LMN] = LAYOUT_ansi_84( // Layer Mac Navigation
    _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     ,
    _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______                   , _______     ,
    _______     , _______     , _______     , _______     , _______     , _______     , KC_HOME     , KC_PGDN     , KC_PGUP     , KC_END      , _______     , _______     , _______     , _______                   , _______     ,
    _______     , _______     , _______     , _______     , _______     , _______     , KC_LEFT     , KC_DOWN     , KC_UP       , KC_RGHT     , _______     , _______                   , _______                   , _______     ,
    _______                   , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______     , _______                   , _______     , _______     , _______     ,
    _______     , _______     , _______                                               , _______                                               , _______     , _______     , _______     , _______     , _______     , _______     ),

[LMP] = LAYOUT_ansi_84( // Layer Mac Pure
    KC_ESC      , KC_F1       , KC_F2       , KC_F3       , KC_F4       , KC_F5       , KC_F6       , KC_F7       , KC_F8       , KC_F9       , KC_F10      , KC_F11      , KC_F12      , XXXXXXX     ,  XXXXXXX    , KC_DEL      ,
    KC_GRV      , KC_1        , KC_2        , KC_3        , KC_4        , KC_5        , KC_6        , KC_7        , KC_8        , KC_9        , KC_0        , KC_MINS     , KC_EQL      , KC_BSPC                   , KC_HOME     ,
    KC_TAB      , KC_Q        , KC_W        , KC_E        , KC_R        , KC_T        , KC_Y        , KC_U        , KC_I        , KC_O        , KC_P        , KC_LBRC     , KC_RBRC     , KC_BSLS                   , KC_END      ,
    KC_CAPS     , KC_A        , KC_S        , KC_D        , KC_F        , KC_G        , KC_H        , KC_J        , KC_K        , KC_L        , KC_SCLN     , KC_QUOT                   , KC_ENT                    , KC_PGUP     ,
    KC_LSFT                   , KC_Z        , KC_X        , KC_C        , KC_V        , KC_B        , KC_N        , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH                   , KC_RSFT     , KC_UP       , KC_PGDN     ,
    KC_LCTL     , KC_LOPT     , KC_LCMD                                               , KC_SPC                                                , KC_RCMD     , KC_ROPT     , KC_RCTL     , KC_LEFT     , KC_DOWN     , KC_RGHT     ),
};
