SHELL = /bin/sh -x
# FIXME: learn from the path
KEYBOARD := voyager
KEYMAPS = colemak-dh
USER = shaleh

all: build

.PHONY: build colemak-dh-build colemak-dh-lint colemak-dh

colemak-dh:
        #git submdule update --init --recursive
	ln -sf $(PWD)/$@ qmk_firmware/keyboards/$(KEYBOARD)/keymaps/$(USER)-$@

colemak-dh-lint: colemak-dh
	cd qmk_firmware; qmk lint -km $(USER) -kb $(USER)-colemak-dh --strict

colemak-dh-build: colemak-dh-lint
	(cd qmk_firmware && qmk compile -km $(USER) -kb $(USER)-colemak-dh --strict)

build: colemak-dh-build
