section .text
	global _start

_start:
	push eax
	push ebx 
	push ecx
	push edx
	
	mov eax, 1
	mov ebx, 2
	
	push eax 
	push ebx
	push ecx
	push edx

	add eax, ebx
	
	push eax 
	push ebx 
	push ecx
	push edx
	
	mov eax, 4
	mov ebx, 1 
	mov ecx, 4 
	mov edx, 16
	int 80h
	

