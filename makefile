.PHONY: help build rebuild clean full-clean default

default: build

help:
	@echo "help       : No description needed"
	@echo "build      : Build project"
	@echo "rebuild    : Rebuild project"
	@echo "clean      : Clean output"
	@echo "full-clean : Clean ALL output"

clean:
	$(MAKE) -f cfallsave.makefile clean
	$(MAKE) -f cfallsave.dev.makefile clean
	$(MAKE) -f cfallsave++.makefile clean
	$(MAKE) -f cfallsave++.dev.makefile  clean

full-clean:
	$(MAKE) -f cfallsave.makefile full-clean
	$(MAKE) -f cfallsave.dev.makefile full-clean
	$(MAKE) -f cfallsave++.makefile full-clean
	$(MAKE) -f cfallsave++.dev.makefile  full-clean

build:
	$(MAKE) -f cfallsave.makefile
	$(MAKE) -f cfallsave.dev.makefile
	$(MAKE) -f cfallsave++.makefile
	$(MAKE) -f cfallsave++.dev.makefile

rebuild: clean build
