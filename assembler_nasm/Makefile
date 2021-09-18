all:
	nasm -f elf64 $(source).asm -o out.o
	sudo chmod +x out.o
	ld out.o -o $(source)
	rm out.o
