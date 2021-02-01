pwd := $(shell pwd -LP)
target := ${HOME}/.config/kmonad

install-mi: clean
	ln -nfs "${pwd}/mi.kbd" "${target}/"

install-macbook: clean
	ln -nfs "${pwd}/macbook.kbd" "${target}/"

clean:
	rm -rf "${target}"
	mkdir "${target}"
