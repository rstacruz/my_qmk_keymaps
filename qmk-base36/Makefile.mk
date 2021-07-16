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

${qmk_home}/quantum/process_keycode/process_combo.c: ${base_path}/process_combo.c
	@# doesn't seem to be working right now?
	# cp $< $@

mkdir:
	@mkdir -p ${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}

push: \
	mkdir \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/config.h \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/rules.mk \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/onehand_combos.c \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/keymap.c \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/game_layers.h \
	${qmk_home}/quantum/process_keycode/process_combo.c

# Don't delete these intermediate files
.PRECIOUS: %/keymap.c %/onehand_combos.c %/game_layers.h

c: compile
f: flash
r: ref
