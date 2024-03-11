##
## EPITECH PROJECT, 2024
## GLIBChecker
## File description:
## Makefile
##

.ONESHELL:

CMAKE	=	$$(which cmake)

_:
	@echo "Please use one of the following commands:"
	@echo "  - \33[3mmake build\33[0m: to build the GLIBChecker"
	@echo "  - \33[3mmake path\33[0m: to move the binary to the /usr/bin/ directory (requires sudo)"
	@echo "  - \33[3mmake install\33[0m: build and path commands combined"
	@echo "  - \33[3mmake clean\33[0m: to remove the build directory"

build:
	@echo "Building GLIBChecker..."
	@mkdir -p build
	@cd build
	@$(CMAKE) .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
	@$(CMAKE) --build .
	@cd ..
	@echo "GLIBChecker built successfully!"

path:
	@echo "Moving GLIBChecker to /usr/bin/..."
	@sudo mv build/glib_checker /usr/bin/
	@echo "GLIBChecker moved successfully!"

install:	build path

clean:
	@echo "Removing build directory..."
	@rm -rf build
	@echo "Build directory removed successfully!"

fclean:	clean

.PHONY: _ build path install clean fclean
