# Get qmk path using the qmk cli
# qmk_home := ${HOME}/qmk_firmware
qmk_home := $(shell qmk config user.qmk_home | cut -d= -f2)

keymap_name   := rsta
keyboard_path := crkbd
keyboard_id   := crkbd

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

${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/%: ./%
	cp $< $@

mkdir:
	@mkdir -p ${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}

push: \
	mkdir \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/config.h \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/rules.mk \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/keymap.c

# Don't delete these intermediate files
.PRECIOUS: %/keymap.c

c: compile
f: flash
r: ref
