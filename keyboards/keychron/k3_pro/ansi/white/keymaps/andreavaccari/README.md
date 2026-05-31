# Keychron K3 Pro

## Build Setup

- This keymap targets Keychron branch `wls_2025q1` and is currently verified with Homebrew `qmk` CLI `1.1.8`.
- If a future `qmk` update breaks this branch, choose a newer Keychron branch and update the keymap as needed.
- Local `mise.toml` lives in this keymap directory and provides tasks:
  - `mise run doctor` to confirm QMK is set up correctly
  - `mise run compile` to compile the keymap
  - `mise run flash` to flash the keymap
- Direct `make` from the repo root may fail if the shell does not include the Homebrew keg-only compiler paths. To run root-level targets through this keymap's mise environment, run from this directory:
  - `mise exec -- make -C "$QMK_ROOT" keychron/k3_pro/ansi/white:default`
  - `mise exec -- make -C "$QMK_ROOT" keychron/k3_pro/ansi/white:andreavaccari`
- To validate a Homebrew `qmk` version for a future `wls_2025q1` refresh:
  - Check out the target Keychron branch.
  - Run `qmk --version` and `QMK_HOME=$PWD qmk doctor`.
  - Compile `keychron/k3_pro/ansi/white:default` and `keychron/k3_pro/ansi/white:andreavaccari`.
  - If doctor and both compiles pass, record that `qmk --version` value here.
- The firmware source comes from this checked-out repository. The installed `qmk` CLI supplies Python dependencies, setup checks, and generator commands used by the makefiles.
- Installing only the ARM/AVR compiler formulas is not enough for this branch unless Python dependencies are managed some other way.

## Keychron branches

- Support for Keychron K3 Pro has never added to the official QMK repo, but various branches are available in Keychron's QMK fork.
- `bluetooth_playground` is the original still linked from [product page](https://www.keychron.com/products/keychron-k3-pro-qmk-via-wireless-custom-mechanical-keyboard)
- `wireless_playground` was recommended on [2024-04-11](https://github.com/Keychron/qmk_firmware/issues/251#issuecomment-2050877614)
- `wls_2025q1` was recommended on [2025-03-31](https://github.com/Keychron/qmk_firmware/issues/368#issuecomment-2767824519)

## Git Remotes

- `upstream`: official QMK repository. Useful for reference, but K3 Pro support is not available there.
- `keychron`: Keychron QMK fork. Source of the target branch, currently `wls_2025q1`.
- `origin`: personal fork, `andreavaccari/qmk_firmware`. Push `andreavaccari` keymap branches here.

## Maintenance Notes

- Current work branch: `wls_2025q1`, based on Keychron `wls_2025q1`.
- `origin/wls_2025q1` is expected to contain only personal changes on top of `keychron/wls_2025q1`.
- Normal keymap updates can be committed directly to `wls_2025q1`; use short-lived branches only for risky experiments.
- For speculative feature work such as easier number access, F13-F24 hotkeys, mouse layers, or tap-hold tuning, branch from `wls_2025q1` as `experiment/<topic>`, then merge or cherry-pick back into `wls_2025q1` after hardware testing.
- This machine has global Git config `push.recurseSubmodules=check`; if pushing this repo tries to push QMK submodules, use `git push --no-recurse-submodules origin wls_2025q1`.
- The original local branch `keychron-k3pro` still points at the older Keychron `bluetooth_playground` commit, but the `andreavaccari` keymap was untracked before this cleanup, so there is no git-saved pre-cleanup keymap snapshot.
- Keep `mise.toml` in this keymap directory so the keymap, notes, and tasks stay together. Run `mise` tasks from this directory.
- `CHORDAL_HOLD` depends on the explicit `chordal_hold_layout` in `keymap.c`; update both the keymap and that handedness map if the physical layout changes.
- Backlight tap behavior in `CK_BLD_F5`/`CK_BLU_F6` calls LED Matrix functions directly. Do not replace it with `tap_code16(QK_BACKLIGHT_DOWN/UP)`: those keycodes are processed correctly as real keymap events, but `tap_code16()` does not re-enter QMK's keycode processing pipeline from inside `process_record_user()`.
- Custom F-row `CK_*` keys use `LT(0, ...)` only to get QMK tap-hold state; `process_record_user()` returns before the carrier layer can activate.

## Default Config

```{#dLMB name="Layer Mac Base"}
KC_ESC      KC_BRID     KC_BRIU     KC_MCTL     KC_LPAD     BL_DOWN     BL_UP       KC_MPRV     KC_MPLY     KC_MNXT     KC_MUTE     KC_VOLD     KC_VOLU     KC_SNAP     KC_DEL      BL_STEP
KC_GRV      KC_1        KC_2        KC_3        KC_4        KC_5        KC_6        KC_7        KC_8        KC_9        KC_0        KC_MINS     KC_EQL      KC_BSPC                 KC_PGUP
KC_TAB      KC_Q        KC_W        KC_E        KC_R        KC_T        KC_Y        KC_U        KC_I        KC_O        KC_P        KC_LBRC     KC_RBRC     KC_BSLS                 KC_PGDN
KC_CAPS     KC_A        KC_S        KC_D        KC_F        KC_G        KC_H        KC_J        KC_K        KC_L        KC_SCLN     KC_QUOT                 KC_ENT                  KC_HOME
KC_LSFT                 KC_Z        KC_X        KC_C        KC_V        KC_B        KC_N        KC_M        KC_COMM     KC_DOT      KC_SLSH                 KC_RSFT     KC_UP       KC_END
KC_LCTL     KC_LOPT     KC_LCMD                                         KC_SPC                                          KC_RCMD     MO(LMF)     KC_RCTL     KC_LEFT     KC_DOWN     KC_RGHT
```

```{#dLMF name="Layer Mac Function"}
_______     KC_F1       KC_F2       KC_F3       KC_F4       KC_F5       KC_F6       KC_F7       KC_F8       KC_F9       KC_F10      KC_F11      KC_F12      _______     _______     BL_TOGG
_______     BT_HST1     BT_HST2     BT_HST3     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______
BL_TOGG     BL_STEP     BL_UP       _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______
_______     _______     BL_DOWN     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______                 _______
_______                 _______     _______     _______     _______     BAT_LVL     NK_TOGG     _______     _______     _______     _______                 _______     _______     _______
_______     _______     _______                                         _______                                         _______     _______     _______     _______     _______     _______
```

```{#dLWB name="Layer Windows Base"}
KC_ESC      KC_F1       KC_F2       KC_F3       KC_F4       KC_F5       KC_F6       KC_F7       KC_F8       KC_F9       KC_F10      KC_F11      KC_F12      KC_PSCR     KC_DEL      BL_STEP
KC_GRV      KC_1        KC_2        KC_3        KC_4        KC_5        KC_6        KC_7        KC_8        KC_9        KC_0        KC_MINS     KC_EQL      KC_BSPC                 KC_PGUP
KC_TAB      KC_Q        KC_W        KC_E        KC_R        KC_T        KC_Y        KC_U        KC_I        KC_O        KC_P        KC_LBRC     KC_RBRC     KC_BSLS                 KC_PGDN
KC_CAPS     KC_A        KC_S        KC_D        KC_F        KC_G        KC_H        KC_J        KC_K        KC_L        KC_SCLN     KC_QUOT                 KC_ENT                  KC_HOME
KC_LSFT                 KC_Z        KC_X        KC_C        KC_V        KC_B        KC_N        KC_M        KC_COMM     KC_DOT      KC_SLSH                 KC_RSFT     KC_UP       KC_END
KC_LCTL     KC_LGUI     KC_LALT                                         KC_SPC                                          KC_RALT     MO(LWF)     KC_RCTL     KC_LEFT     KC_DOWN     KC_RGHT
```

```{#dLWF name="Layer Windows Function"}
_______     KC_BRID     KC_BRIU     KC_TASK     KC_FILE     BL_DOWN     BL_UP       KC_MPRV     KC_MPLY     KC_MNXT     KC_MUTE     KC_VOLD     KC_VOLU     _______     _______     BL_TOGG
_______     BT_HST1     BT_HST2     BT_HST3     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______
BL_TOGG     BL_STEP     BL_UP       _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______
_______     _______     BL_DOWN     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______                 _______
_______                 _______     _______     _______     _______     BAT_LVL     NK_TOGG     _______     _______     _______     _______                 _______     _______     _______
_______     _______     _______                                         _______                                         _______     _______     _______     _______     _______     _______
```

## Custom Config

```{#LMB name="Layer Mac Base"}
KC_ESC      CK_BRID_F1  CK_BRIU_F2  CK_BRIDC_F3 CK_BRIUC_F4 CK_BLD_F5   CK_BLU_F6   CK_MPRV_F7  CK_MPLY_F8  CK_MNXT_F9  CK_MUTE_FA  CK_VOLD_FB  CK_VOLU_FC  BL_TOGG     MO(LMF)     KC_DEL
KC_GRV      KC_1        KC_2        KC_3        KC_4        KC_5        KC_6        KC_7        KC_8        KC_9        KC_0        KC_MINS     KC_EQL      KC_BSPC                 KC_HOME
KC_TAB      KC_Q        KC_W        KC_E        KC_R        KC_T        KC_Y        KC_U        KC_I        KC_O        KC_P        KC_LBRC     KC_RBRC     KC_BSLS                 KC_END
KC_BSPC     MT_A_LCTL   MT_S_LOPT   MT_D_LCMD   MT_F_LSFT   KC_G        KC_H        MT_J_RSFT   MT_K_RCMD   MT_L_ROPT   MT_SC_RCTL  KC_QUOT                 KC_ENT                  KC_PGUP
TD_LSFT                 KC_Z        KC_X        KC_C        KC_V        KC_B        KC_N        KC_M        KC_COMM     KC_DOT      KC_SLSH                 LM_RSFT_LMP KC_UP       KC_PGDN
LM_LCTL_LMP LM_LOPT_LMP LM_LCMD_LMP                                     LT_SPC_LMN                                      LM_RCMD_LMP LM_ROPT_LMP LM_RCTL_LMP KC_LEFT     KC_DOWN     KC_RGHT
```

```{#LMF name="Layer Mac Function"}
_______     KC_F1       KC_F2       KC_F3       KC_F4       KC_F5       KC_F6       KC_F7       KC_F8       KC_F9       KC_F10      KC_F11      KC_F12      _______     _______     _______
_______     BT_HST1     BT_HST2     BT_HST3     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______
_______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______
KC_CAPS     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______                 _______
CW_TOGG                 _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______     _______     _______
_______     _______     _______                                         _______                                         _______     _______     _______     _______     _______     _______
```

```{#LWB name="Layer Windows Base"}
KC_ESC      KC_F1       KC_F2       KC_F3       KC_F4       KC_F5       KC_F6       KC_F7       KC_F8       KC_F9       KC_F10      KC_F11      KC_F12      BL_TOGG     MO(LWF)     KC_DEL
KC_GRV      KC_1        KC_2        KC_3        KC_4        KC_5        KC_6        KC_7        KC_8        KC_9        KC_0        KC_MINS     KC_EQL      KC_BSPC                 KC_HOME
KC_TAB      KC_Q        KC_W        KC_E        KC_R        KC_T        KC_Y        KC_U        KC_I        KC_O        KC_P        KC_LBRC     KC_RBRC     KC_BSLS                 KC_END
KC_CAPS     KC_A        KC_S        KC_D        KC_F        KC_G        KC_H        KC_J        KC_K        KC_L        KC_SCLN     KC_QUOT                 KC_ENT                  KC_PGUP
KC_LSFT                 KC_Z        KC_X        KC_C        KC_V        KC_B        KC_N        KC_M        KC_COMM     KC_DOT      KC_SLSH                 KC_RSFT     KC_UP       KC_PGDN
KC_LCTL     KC_LGUI     KC_LALT                                         KC_SPC                                          KC_RALT     KC_RGUI     KC_RCTL     KC_LEFT     KC_DOWN     KC_RGHT
```

```{#LWF name="Layer Windows Function"}
_______     KC_BRID     KC_BRIU     KC_TASK     KC_FILE     BL_DOWN     BL_UP       KC_MPRV     KC_MPLY     KC_MNXT     KC_MUTE     KC_VOLD     KC_VOLU     _______     _______     _______
_______     BT_HST1     BT_HST2     BT_HST3     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______
_______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______
KC_CAPS     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______                 _______
CW_TOGG                 _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______     _______     _______
_______     _______     _______                                         _______                                         _______     _______     _______     _______     _______     _______
```

```{#LMN name="Layer Mac Navigation"}
_______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______
_______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______
_______     _______     _______     _______     _______     _______     KC_HOME     KC_PGDN     KC_PGUP     KC_END      _______     _______     _______     _______                 _______
_______     _______     _______     _______     _______     _______     KC_LEFT     KC_DOWN     KC_UP       KC_RGHT     _______     _______                 _______                 _______
_______                 _______     _______     _______     _______     _______     _______     _______     _______     _______     _______                 _______     _______     _______
_______     _______     _______                                         _______                                         _______     _______     _______     _______     _______     _______
```

```{#LMP name="Layer Mac Pure"}
KC_ESC      KC_F1       KC_F2       KC_F3       KC_F4       KC_F5       KC_F6       KC_F7       KC_F8       KC_F9       KC_F10      KC_F11      KC_F12      XXXXXXX     XXXXXXX     KC_DEL
KC_GRV      KC_1        KC_2        KC_3        KC_4        KC_5        KC_6        KC_7        KC_8        KC_9        KC_0        KC_MINS     KC_EQL      KC_BSPC                 KC_HOME
KC_TAB      KC_Q        KC_W        KC_E        KC_R        KC_T        KC_Y        KC_U        KC_I        KC_O        KC_P        KC_LBRC     KC_RBRC     KC_BSLS                 KC_END
KC_CAPS     KC_A        KC_S        KC_D        KC_F        KC_G        KC_H        KC_J        KC_K        KC_L        KC_SCLN     KC_QUOT                 KC_ENT                  KC_PGUP
KC_LSFT                 KC_Z        KC_X        KC_C        KC_V        KC_B        KC_N        KC_M        KC_COMM     KC_DOT      KC_SLSH                 KC_RSFT     KC_UP       KC_PGDN
KC_LCTL     KC_LOPT     KC_LCMD                                         KC_SPC                                          KC_RCMD     KC_ROPT     KC_RCTL     KC_LEFT     KC_DOWN     KC_RGHT
```

## Notes

- **Layers:**
  - Layer names are `Lpl` where `p` is platform initial, `l` is layer initial.
  - LMB is the most customized layer and the default when physical toggle is on Mac/iOS.
  - LWB is a lightly customized layer and the default when physical toggle is on Win/Android.
  - LMB, LWB move function key to top row and drop `KC_SNAP` (`⇧⌘4`) and `KC_PSCR` (print screen)
  - LMF, LWF drop BAT_LVL and NK_TOGG and add KC_CAPS (caps lock) and CW_TOGG (caps word).
  - LMN is mostly transparent to preserve fall-through behavior and escape hatches.
  - LMP removes customizations to make modifier combos more predictable.

- **Simple keys:**
  - Key names are `k_t_h` where `k` is kind, `t` is tap action, `h` is hold action.
  - Use `LT_X_Y = LT(lyr_Y, KC_X)` to send key X on tap and activate layer Y on hold.
  - Use `MT_X_Y = MT(MOD_Y, KC_X)` to send key X on tap and activate modifier Y on hold.
  - Use `LM_X_Y = LM(lyr_Y, MOD_X)` to activate modifier X and layer Y at the same time.
  - Use `CK_X_Y` (custom keycode) to send key X on tap and key Y on hold via `process_record_user` with unsupported keys like media/function.
  - Use `TD_X_Y` (tap dance) to implement custom tap hold behavior only when it also requires double-tap or triple-tap behavior.

- **Keychron keys:**
  - KC_SNAP = Keychron custom key to emit Shift + Alt + 4
  - BT_HST1 = Keychron custom key to connect to 1st bluetooth channel
  - BT_HST2 = Keychron custom key to connect to 2nd bluetooth channel
  - BT_HST3 = Keychron custom key to connect to 3rd bluetooth channel
  - BAT_LVL = Keychron custom key to trigger battery level animation

- **Custom keys:**
  - CK_BRID_F1 = tap → lowers display brightness; hold → F1.
  - CK_BRIU_F2 = tap → raises display brightness; hold → F2.
  - CK_BRIDC_F3 = tap → lowers external display brightness with `⌃`; hold → F3.
  - CK_BRIUC_F4 = tap → raises external display brightness with `⌃`; hold → F4.
  - CK_BLD_F5   = CK_BL_DOWN_F5   (conventional name too long).
  - CK_BLU_F6   = CK_BL_UP_F6     (conventional name too long).
  - MT_SC_RCTL  = MT_SCLN_RCTL    (conventional name too long).
  - CK_BRIMID = set built-in display brightness roughly mid-level.
  - CK_BRIMIDC = set external display brightness roughly mid-level with `⌃`.

- **Tap dances:**
  - TD_F1 = unused alternate: tap → lowers display brightness once; hold → F1; double-tap → sends 16 brightness-down events.
  - TD_F2 = unused alternate: tap → raises display brightness once; hold → F2; double-tap → sends 16 brightness-up events.
  - TD_F3 = unused alternate: tap → lowers external display brightness once with `⌃`; hold → F3; double-tap → sends 16 external brightness-down events.
  - TD_F4 = unused alternate: tap → raises external display brightness once with `⌃`; hold → F4; double-tap → sends 16 external brightness-up events.
  - TD_LSFT = tap → turns off caps lock/word; hold → LM_LSFT_LMP; double-tap → turns on caps word; triple-tap → turns on caps lock.

- **Key classes:**
  - Function keys on LMB emit media/function on tap and F-key on hold.
    - F1-F4 use custom LT-style keycodes for home-row-mod-like timing.
    - F5-F12 use custom LT-style keycodes handled in `process_record_user`.
  - Modifier keys on LMB use `LM()` to activate LMP to make modifier combos more predictable.

- **Leader key:**
  - Not implemented here because can be more easily implemented at OS level.

- **Tap-holds:**
  - Use `TAPPING_TERM 180` to set base tap-hold threshold in ms. Default is 200.
  - Use `PERMISSIVE_HOLD` to trigger hold when another key is tapped while a dual-role key is held, even before the tapping term expires.
  - Use `CHORDAL_HOLD` so same-hand home-row rolls stay taps and opposite-hand chords can become holds.
  - Define explicit Chordal Hold handedness for K3 Pro ANSI; Space is `*` so the navigation layer works with either hand.
  - Do not use `IGNORE_MOD_TAP_INTERRUPT`; in `wls_2025q1` this behavior is the default and the old define is an error.
  - Avoid `TAPPING_TERM_PER_KEY` unless `TD_LSFT` multi-tap or a specific dual-role key feels unreliable.
  - Avoid `HOLD_ON_OTHER_KEY_PRESS` because it is more likely to create accidental modifiers during fast typing.
  - Remember: double-tap-and-hold on all dual-role keys sends repeated events.
  - Remember: custom function-row `CK_*` keys are implemented as `LT(0, ...)` dual-role keys so they use the same tap-hold timing machinery as the home-row mods.

- **Combos:**
  - `COMBO_TERM 40`: Max interval for combo keys to be recognized. Default is 50.
  - `F + J` → `⎋` (with `COMBO_MUST_TAP_PER_COMBO`)
    - hold `F`, tap `J` → one uppercase `J`
    - hold `J`, tap `F` → one uppercase `F`
    - hold `F`, double-tap-hold `J` → many uppercase `J`
    - hold `J`, double-tap-hold `F` → many uppercase `F`
    - tap both within `COMBO_TERM` → one `⎋`
  - `= + ⌫` → `⌦` (do not make it tap-only, allow to send many events)
  - `F1+F2` → `CK_BRIMID` (do not make it tap-only, allow to send many events)
  - `F3+F4` → `CK_BRIMIDC` (do not make it tap-only, allow to send many events)

- **Other decisions:**
  - Avoid tweaking if it is not needed. Stability and muscle memory matter more than purity.
  - Use `MT(mod, kc)` not aliases like `LCTL_T(kc)`, `LSFT_T(kc)`, etc. to reduce cognitive load.
  - Ignore `FLOW_TAP_TERM` because not available in branch maintained by keychron.
  - Implement mouse control at OS level. It will work for built-in and external keyboards and is needed anyway for grid-based navigation.
  - In older keychron branches: BL_INC is old name of BL_UP, BL_DEC is old name of BL_DOWN

## Refs

- [QMK keycodes table](https://docs.qmk.fm/keycodes)
