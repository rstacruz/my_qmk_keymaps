# Get qmk path using the qmk cli
# qmk_home := ${HOME}/qmk_firmware
qmk_home := $(shell qmk config user.qmk_home | cut -d= -f2)

keymap_name   ?= rsta
keyboard_path ?= crkbd
keyboard_id   ?= crkbd
base_path ?= ../qmk-base36

# Set `use_docker=1` to use Docker for building
ifeq (${use_docker},1)
	make := ./util/docker_build.sh
else
	make := make
endif

help:
	@echo "Try 'make c' (compile) or 'make f' (flash)"

ref:
	@grep -E '[│─┄]' keymap.c | less

compile: push
	cd ${qmk_home} && ${make} ${keyboard_id}:${keymap_name}

flash: push
	cd ${qmk_home} && ${make} ${keyboard_id}:${keymap_name}:flash

split-right: push
	cd ${qmk_home} && ${make} ${keyboard_id}:${keymap_name}:dfu-split-right

split-left: push
	cd ${qmk_home} && ${make} ${keyboard_id}:${keymap_name}:dfu-split-left

${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/rules.mk: ./rules.mk
	cp $< $@

${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/%: ${base_path}/%
	cp $< $@

mkdir:
	@mkdir -p ${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}

push: \
	mkdir \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/config.h \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/rules.mk \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/keymap.c \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/game_layers.h \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/halfmak.c

# Don't delete these intermediate files
.PRECIOUS: %/keymap.c %/game_layers.h %/halfmak.c

c: compile
f: flash
r: ref
