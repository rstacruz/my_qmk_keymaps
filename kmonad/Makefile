pwd := $(shell pwd -LP)
target := ${HOME}/.config/kmonad

mi-wide: clean
	ln -nfs "${pwd}/mi-wide.kbd" "${target}/kmonad.kbd"

macbook: clean
	ln -nfs "${pwd}/macbook.kbd" "${target}/kmonad.kbd"

clean:
	mkdir -p "${target}"
