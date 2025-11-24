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
	$(MAKE) -f cfallsave.makefile clean
	$(MAKE) -f cfallsave++.makefile clean

full-clean:
	$(MAKE) -f cfallsave.makefile full-clean
	$(MAKE) -f cfallsave++.makefile full-clean

build:
# $(MAKE) -f cfallsave.makefile ARCH=x86_64
	$(MAKE) -f cfallsave.makefile ARCH=arm64
# $(MAKE) -f cfallsave++.makefile ARCH=x86_64
	$(MAKE) -f cfallsave++.makefile ARCH=arm64

rebuild: clean build
