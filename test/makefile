.PHONY: help build rebuild clean full-clean default

default: build

help:
	@echo "help       : No description needed"
	@echo "build      : Build project"
	@echo "rebuild    : Rebuild project"
	@echo "clean      : Clean output"
	@echo "full-clean : Clean ALL output"

clean:
	$(MAKE) -f cfallsave.test.makefile clean
	$(MAKE) -f cfallsave++.test.makefile clean

full-clean:
	$(MAKE) -f cfallsave.test.makefile full-clean
	$(MAKE) -f cfallsave++.test.makefile full-clean

build:
	$(MAKE) -f cfallsave.test.makefile
	$(MAKE) -f cfallsave++.test.makefile

rebuild: clean build
