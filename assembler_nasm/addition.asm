SYS_EXIT 	equ	1
SYS_READ 	equ 3
SYS_WRITE	equ	4
STDIN		equ 0
STDOUT		equ 1


section .data
	f_msg:		db		'Entre first value: '
	f_len:		equ		$-f_msg
	s_msg:		db 		'Enter second value: '
	s_len:		equ 	$-s_msg
	r_msg:		db 		'Result is: '
	r_len:		equ 	$-r_msg
	line:		db 		'',10
	len_line: 	equ 	$-line
section .bss
	num_1:		resb 	16
	num_1_len:	equ 	$-num_1
	num_2: 		resb 	16
	num_2_len: 	equ 	$-num_2
	sum: 		resb 	1

section .text
	global _start

_start: 
	
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, f_msg
	mov edx, f_len
	int 80h

	mov eax, SYS_READ
	mov ebx, STDIN
	mov ecx, num_1
	mov edx, num_1_len
	int 80h

	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, s_msg
	mov edx, s_len
	int 80h

	mov eax, SYS_READ
	mov ebx, STDIN
	mov ecx, num_2
	mov edx, num_2_len
	int 80h

	mov eax, [num_1]
	sub eax, '0'
	mov ebx, [num_2]
	sub ebx, '0'

	add eax, ebx
	add eax, '0'
	mov [sum], eax
	
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, r_msg
	mov	edx, r_len
	int 80h

	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, sum
	mov edx, 16
	int 80h

	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, line
	mov edx, len_line
	int 80h

	mov eax, SYS_EXIT
	mov ebx, 0
	int 80h
