# QMK Userspace

Custom keymaps maintained separately from the [main QMK repository](https://github.com/qmk/qmk_firmware) using the [QMK Userspace](https://github.com/qmk/qmk_userspace) template. Firmware is built automatically with GitHub Actions on push.

## Keyboards

| Keyboard | Keymap |
| --- | --- |
| [Corne (crkbd rev1)](https://github.com/foostan/crkbd) | `perrwa` |
| [Boardsource Lulu (AVR)](https://boardsource.xyz/store/61d0b772319a1f3cc53ba2fb) | `perrwa` |
| [TKC Portico](https://thekey.company/products/portico-keyboard) | `lilycat` |

## Building with GitHub Actions

1. In the GitHub Actions tab, enable workflows
1. Push your changes to your forked GitHub repository
1. Wait for the actions run to complete
1. If you pushed to `main`, grab the latest firmware from the [Releases](../../releases) tab
1. If you pushed to any other branch, download the build artifacts from that workflow run instead

## Building locally

1. Run the normal `qmk setup` procedure if you haven't already done so — see [QMK Docs](https://docs.qmk.fm/#/newbs) for details.
1. Clone this repository
1. Set the userspace overlay: `qmk config user.overlay_dir="$(realpath .)"` (run from the repo root)
1. Compile a single target: `qmk compile -kb <keyboard> -km <keymap>`
1. Or build everything at once: `qmk userspace-compile`

## Managing build targets

Add or remove keymaps from `qmk.json`:

```sh
qmk userspace-add -kb <keyboard> -km <keymap>
qmk userspace-remove -kb <keyboard> -km <keymap>
qmk userspace-list
```

## Customizing the GitHub Actions build

To point the build at a different QMK repository or branch, edit `.github/workflows/build.yml` and `.github/workflows/release.yml`:

```yaml
    with:
      qmk_repo: qmk/qmk_firmware
      qmk_ref: master
```

Alternatively, add `qmk_firmware` as a git submodule and Actions will use the pinned revision automatically.
