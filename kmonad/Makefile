pwd := $(shell pwd -LP)
target := ${HOME}/.config/kmonad

mi-wide: clean
	ln -nfs "${pwd}/mi-wide.kbd" "${target}/"

macbook: clean
	ln -nfs "${pwd}/macbook.kbd" "${target}/"

clean:
	rm -rf "${target}"
	mkdir "${target}"
