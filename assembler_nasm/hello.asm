section .data
	hello:	db 'Hello world!',10
	len:	equ $-hello

section .bss
	input:		resb 16
	input_len:	equ $-input


section .text
	global _start

_start:

	mov eax, 4
	mov ebx, 1
	mov ecx, hello
	mov edx, len
	int 80h

	mov eax, 3
	mov ebx, 2
	mov ecx, input
	mov edx, input_len
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, input
	mov edx, input_len
	int 80h

	mov eax, 1
	mov ebx, 0

	int 80h
