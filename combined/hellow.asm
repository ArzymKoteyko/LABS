section .data
	msg db "Test status: OK"
	len equ $-msg

section .text
	hellow PROC
		mov eax, 4
		mov ebx, 1
		mov ecx, msg
		mov edx, len
		int 80h
		mov eax, 1
		xor ebx, ebx
		int 80h
	hellow ENDP

