# My keymap

## Compiling and flashing

Get QMK CLI installed and set up ([instructions here](https://beta.docs.qmk.fm/cli/cli)). Then:

```sh
cd rsta
make f    # Flashes the keyboard, `make c` for compiling only
```

## Planck on VIA

[VIA] support for the Planck is a WIP on the QMK repo at time of writing (Jan 2021). VIA support for my keymap is provided using a JSON definition that can be loaded on VIA's Design tab.

[via]: https://caniusevia.com/

- via definition: https://raw.githubusercontent.com/mixedfeelings/keyboards/planck-rev6.1/src/olkb/planck/rev6/olkb-planck-rev6.json
- pr: https://github.com/qmk/qmk_firmware/pull/9144
