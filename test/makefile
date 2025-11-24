# --------------------
# CFallSave Builder v3
# --------------------
#
# /!\ LINUX ONLY /!\
# For macOS makefiles check /macos/!

.PHONY: help build rebuild clean full-clean default

default: build

help:
	@cat ../make/docs/help.txt

clean:
	$(MAKE) -f cfallsave.test.makefile clean
	$(MAKE) -f cfallsave++.test.makefile clean

full-clean:
	$(MAKE) -f cfallsave.test.makefile full-clean
	$(MAKE) -f cfallsave++.test.makefile full-clean

build:
	$(MAKE) -f cfallsave.test.makefile ARCH=i686
	$(MAKE) -f cfallsave.test.makefile ARCH=x86_64
	$(MAKE) -f cfallsave.test.makefile ARCH=aarch64
	$(MAKE) -f cfallsave++.test.makefile ARCH=i686
	$(MAKE) -f cfallsave++.test.makefile ARCH=x86_64
	$(MAKE) -f cfallsave++.test.makefile ARCH=aarch64

rebuild: clean build
