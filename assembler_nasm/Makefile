install: compile
	@echo [linking]
	@for file in $(shell ls ./build/*.o); do \
		ld $$file -o $${file:0:-2}; \
		rm $$file; \
	done
	@echo [job done]

compile:
	@mkdir build
	@echo [compiling]
	@for file in $(shell ls *.asm); do \
		nasm -f elf64 $$file -o ./build/$${file:0:-4}.o; \
	done

clean:
	@rm -r ./build
