# --------------------
# CFallSave Builder v3
# --------------------
#
# /!\ MACOS ONLY /!\

.PHONY: help build rebuild clean full-clean default

default: build

help:
	@cat ../make/docs/help.txt

clean:
	$(MAKE) -f cfallsave.macos.makefile clean
	$(MAKE) -f cfallsave++.macos.makefile clean

full-clean:
	$(MAKE) -f cfallsave.macos.makefile full-clean
	$(MAKE) -f cfallsave++.macos.makefile full-clean

build:
# $(MAKE) -f cfallsave.macos.makefile ARCH=x86_64
	$(MAKE) -f cfallsave.macos.makefile ARCH=arm64
# $(MAKE) -f cfallsave++.macos.makefile ARCH=x86_64
	$(MAKE) -f cfallsave++.macos.makefile ARCH=arm64

rebuild: clean build
