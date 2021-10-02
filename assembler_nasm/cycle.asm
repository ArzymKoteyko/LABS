SYS_WRITE 	equ 	4
STDOUT 		equ 	1

section .data
	msg: 	db 		'Cycle '
	msg_l: 	equ 	$-msg
section .bss
	index: 	resb 	16

section .text
	global _start
_start:

	mov esi, 10
	cycle:
	cmp esi, 0
	sub esi, 1
	
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, msg
	mov edx, msg_l
	int 80h

	jne cycle

	mov eax, 1
	mov ebx, 0
	int 80h
