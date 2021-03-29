pwd := $(shell pwd -LP)
target := ${HOME}/.config/kmonad

ansi: clean
	ln -nfs "${pwd}/ansi.kbd" "${target}/"

ansi-wide: clean
	ln -nfs "${pwd}/ansi-wide.kbd" "${target}/"

macbook: clean
	ln -nfs "${pwd}/macbook.kbd" "${target}/"

clean:
	rm -rf "${target}"
	mkdir "${target}"
