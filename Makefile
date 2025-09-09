.PHONY: build clean run_tests flash

build:
	make clean
	cmake -S . -B build
	cmake --build build -j

clean:
	rm -rf build

run_tests:
	make build
	sudo picotool load build/test/mytest.uf2
	sudo picotool reboot

# Generic flash target
flash:
	@if [ -z "$(FILE)" ]; then \
		echo "Usage: make flash FILE=<path-to-uf2-or-elf>"; \
		exit 1; \
	fi
	sudo picotool load $(FILE) -f
	sudo picotool reboot