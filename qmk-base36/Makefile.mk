# Get qmk path using the qmk cli
# qmk_home := $(shell \
# 	x=$$(qmk config user.qmk_home | cut -d= -f2); \
# 	if [[ "$$x" == "None" ]]; then x=""; fi; \
# 	if [[ "$$x" == "" ]]; then x="${HOME}/qmk_firmware"; fi; \
# 	echo $$x \
# )

qmk_home := ~/.cache/qmk_firmware

keymap_name   ?= rsta
keyboard_path ?= crkbd
keyboard_id   ?= crkbd/rev1
base_path ?= ../qmk-base36
make ?= make
extension ?= hex
firmware_file ?= $(subst /,_,${keyboard_id})_${keymap_name}.${extension}

help:
	@echo
	@echo Makefile targets
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' ${base_path}/Makefile.mk | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m  %-12s\033[0m %s\n", $$1, $$2}'
	@echo

${qmk_home}:
	git clone --recursive --depth 1 https://github.com/qmk/qmk_firmware.git ${qmk_home}

docker: ${qmk_home} push ## Compile using Docker [alias: d]
	cd ${qmk_home} && ./util/docker_build.sh ${keyboard_id}:${keymap_name}
	cp ${qmk_home}/.build/${firmware_file} .
	@ls -la ${firmware_file}

ref:
	@grep -E '[│─]' ${base_path}/keymap.c | less

build: push ## Compile using qmk-cli on Linux [alias: b]
	cd ${qmk_home} && ${make} ${keyboard_id}:${keymap_name}

flash: push ## Flash via qmk-cli on Linux [alias: f]
	cd ${qmk_home} && ${make} ${keyboard_id}:${keymap_name}:flash

split-right: push
	cd ${qmk_home} && ${make} ${keyboard_id}:${keymap_name}:dfu-split-right

split-left: push
	cd ${qmk_home} && ${make} ${keyboard_id}:${keymap_name}:dfu-split-left

${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/rules.mk: ./rules.mk
	cp $< $@

${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/%: ${base_path}/%
	cp $< $@

mkdir: ${qmk_home}
	@mkdir -p ${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}

push: ${qmk_home} mkdir \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/config.h \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/rules.mk \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/keymap.c \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/game_layers.h \
	${qmk_home}/keyboards/${keyboard_path}/keymaps/${keymap_name}/frogv.c

# Don't delete these intermediate files
.PRECIOUS: %/keymap.c %/game_layers.h %/frogv.c

b: build
d: docker
f: flash
r: ref
