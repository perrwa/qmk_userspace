QMK external userspace repo — custom keymaps maintained separately from qmk_firmware via overlay directory. Build targets in `qmk.json`.

Build: `qmk compile -kb <board> -km <keymap>` or `make <board>:<keymap>`. Compile all: `qmk userspace-compile`. Flash: `qmk flash -kb <board> -km <keymap>`. Requires `qmk config user.overlay_dir="$(realpath .)"`. CI via `build_binaries.yaml` on push.

Keymaps at `keyboards/<board>/keymaps/<name>/`: `keymap.c` (layers, keycodes), `config.h` (hardware config), `rules.mk` (feature flags).

Conventions: layers as named enums with `_` prefix (`_QWERTY`, `_LOWER`). Custom keycodes prefixed `_` (`_LWRSPC`, `_NAVESC`). Dual-function via `LT()`/`LGUI_T()`/`RCTL_T()`. Preserve ASCII-art alignment in LAYOUT macros. RGB settings behind `#ifdef RGB_MATRIX_ENABLE`. C files: 4-space indent, no tabs. `.mk`/`Makefile`: tabs.
