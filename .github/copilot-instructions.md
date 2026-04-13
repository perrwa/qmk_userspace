QMK external userspace repo — custom keymaps maintained separately from qmk_firmware via overlay directory. Build targets in `qmk.json`.

## Local environment

**QMK CLI is not installed locally.** Do not run `qmk compile`, `qmk c2json`, `qmk flash`, or any other `qmk` commands. All QMK operations happen in CI inside the `ghcr.io/qmk/qmk_cli` Docker container. Validate changes by pushing to a branch and checking CI results.

## Reference repo

`perrwa/zmk-config` is the sibling keyboard repo. Use it as the architectural reference for workflow patterns, keymap-drawer config, CI structure, and GitHub rulesets. When asked to create or modify workflows/configs, check zmk-config first for established patterns.

## CI workflows

Three workflows, each with a distinct trigger:

- **`build.yml`** — PRs + `workflow_dispatch`. Compiles firmware via `qmk/.github/.github/workflows/qmk_userspace_build.yml@main`. Uses `dorny/paths-filter` to skip builds when only non-firmware files changed. Gate job `build-result` is the required status check.
- **`draw.yml`** — Push to main + PRs (path-filtered to keyboards/keymap_drawer files). Runs inside `ghcr.io/qmk/qmk_cli:1.2.0` container. Pipeline: `qmk c2json` → sed (replace named layers with indices) → `keymap parse` → `keymap draw` → SVG. On main: opens PR via `peter-evans/create-pull-request`. On feature branches: auto-commits via `stefanzweifel/git-auto-commit-action`. Note: the QMK container does not have `pipx` — use `pip install` for Python packages.
- **`release.yml`** — Push to main (paths-ignore keymap-drawer). Builds firmware then creates a draft prerelease with tag `vYY.MM.N`.

## Keymap structure

Keymaps at `keyboards/<board>/keymaps/<name>/`: `keymap.c` (layers, keycodes), `config.h` (hardware config), `rules.mk` (feature flags).

## Keymap-drawer (`keymap_drawer.config.yaml`)

Visualization config for [keymap-drawer](https://github.com/caksoylar/keymap-drawer). Key patterns:

- **Material icons**: Use `$$material:icon_name$$` syntax (e.g., `$$material:keyboard_tab$$`). Browse available icons at https://fonts.google.com/icons. Use snake_case names.
- **`qmk_keycode_map`**: Maps QMK keycodes to display text or material glyphs. Handles simple keycodes like `KC_TAB`, `RM_TOGG`, custom keycodes like `_RGBRST`.
- **`raw_binding_map`**: Overrides for composite keycodes that keymap-drawer's regex parsers can't decompose (e.g., `LGUI_T(KC_ENT)` → tap/hold glyph pair). Format: `{t: 'tap_display', h: 'hold_display'}`.
- **Layer indices in draw.yml**: The sed pipeline in draw.yml replaces `_LAYERNAME` with numeric indices so keymap-drawer's built-in LT/MO/TG parsers work. This is why `raw_binding_map` does NOT need LT/MO/TG entries — the parsers handle them natively after sed.
- **CSS classes**: `rect.held` (peach `#ffeedd`) for hold-layer keys, `rect.toggle` (light green `#ddffdd`) for toggle keys. Per-layer colors via `.layer-NAME .tap`.
- **`layer_legend_map`**: Maps layer names to material icons shown in layer headers.

## Code conventions

Layers as named enums with `_` prefix (`_QWERTY`, `_LOWER`). Custom keycodes prefixed `_` (`_LWRSPC`, `_NAVESC`). Dual-function via `LT()`/`LGUI_T()`/`RCTL_T()`. Preserve ASCII-art alignment in LAYOUT macros. RGB settings behind `#ifdef RGB_MATRIX_ENABLE`. C files: 4-space indent, no tabs. `.mk`/`Makefile`: tabs.

## Working style

Make only the changes requested. When reviewing or suggesting improvements, present findings but wait for explicit approval on scope before applying — don't pin/upgrade/refactor things the user didn't ask about.
