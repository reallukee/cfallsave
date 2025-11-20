# --------------------
# CFallSave Builder v3
# --------------------
#
# /!\ MACOS ONLY /!\

.PHONY: help build rebuild clean full-clean default

default: build

help:
	@cat ../../make/docs/help.txt

clean:
	$(MAKE) -f cfallsave.test.osx.makefile clean
	$(MAKE) -f cfallsave++.test.osx.makefile clean

full-clean:
	$(MAKE) -f cfallsave.test.osx.makefile full-clean
	$(MAKE) -f cfallsave++.test.osx.makefile full-clean

build:
#$(MAKE) -f cfallsave.test.osx.makefile ARCH=x86_64
	$(MAKE) -f cfallsave.test.osx.makefile ARCH=arm64
#$(MAKE) -f cfallsave++.test.osx.makefile ARCH=x86_64
	$(MAKE) -f cfallsave++.test.osx.makefile ARCH=arm64

rebuild: clean build
