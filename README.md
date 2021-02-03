# My keymap

My personal keymaps for the [QMK firmware] for mechanical keyboards.

[qmk firmware]: https://qmk.fm/

![Preview of the keymap](./preview.png)

## Rationale

- 30% layout with 5 columns per side
- No home row mods
- Minimise the use of tap-hold keys
- All symbols in one layer

[home row mods]: https://precondition.github.io/home-row-mods

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
