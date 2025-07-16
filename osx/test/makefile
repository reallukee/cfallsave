.PHONY: help build rebuild clean full-clean default

default: build

help:
	@echo "help       : No description needed"
	@echo "build      : Build project"
	@echo "rebuild    : Rebuild project"
	@echo "clean      : Clean output"
	@echo "full-clean : Clean ALL output"

clean:
	$(MAKE) -f cfallsave.test.osx.makefile clean
	$(MAKE) -f cfallsave++.test.osx.makefile clean

full-clean:
	$(MAKE) -f cfallsave.test.osx.makefile full-clean
	$(MAKE) -f cfallsave++.test.osx.makefile full-clean

build:
	$(MAKE) -f cfallsave.test.osx.makefile
	$(MAKE) -f cfallsave++.test.osx.makefile

rebuild: clean build
