.PHONY: help build rebuild clean full-clean default

default: build

help:
	@echo "help       : No description needed"
	@echo "build      : Build project"
	@echo "rebuild    : Rebuild project"
	@echo "clean      : Clean output"
	@echo "full-clean : Clean ALL output"

clean:
	$(MAKE) -f cfallsave.osx.makefile clean
	$(MAKE) -f cfallsave.dev.osx.makefile clean
	$(MAKE) -f cfallsave++.osx.makefile clean
	$(MAKE) -f cfallsave++.dev.osx.makefile  clean

full-clean:
	$(MAKE) -f cfallsave.osx.makefile full-clean
	$(MAKE) -f cfallsave.dev.osx.makefile full-clean
	$(MAKE) -f cfallsave++.osx.makefile full-clean
	$(MAKE) -f cfallsave++.dev.osx.makefile  full-clean

build:
	$(MAKE) -f cfallsave.osx.makefile
	$(MAKE) -f cfallsave.dev.osx.makefile
	$(MAKE) -f cfallsave++.osx.makefile
	$(MAKE) -f cfallsave++.dev.osx.makefile

rebuild: clean build
