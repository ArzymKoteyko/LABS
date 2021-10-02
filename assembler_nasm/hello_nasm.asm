section .data
msg db "Hello, nasm!"
len equ $-msg 

section .text
global _start 

_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, msg
	mov edx, len
	int 80h
	mov eax, 1
	xor ebx, ebx
	int 80h

