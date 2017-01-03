	.386
	.model flat, stdcall

	include    \masm32\include\msvcrt.inc
	includelib \masm32\lib\msvcrt.lib




	.data
	_n DWORD 0
	_t DWORD 0
	_i DWORD 0
	_b DWORD 0
	_a DWORD 0
	buffer db '%d',0
	data_blank db  ' ',0




	.code
_start:
	MOV eax,0
	MOV _a,eax
	MOV eax,1
	MOV _b,eax
	MOV eax,1
	MOV _i,eax
	push eax
	push ebx
	push ecx
	push edx
	invoke     crt_scanf, addr buffer,addr _n
	pop edx
	pop ecx
	pop ebx
	pop eax
	push eax
	push ebx
	push ecx
	push edx
	invoke     crt_printf,addr data_blank
	invoke     crt_printf, addr buffer, _a
	pop edx
	pop ecx
	pop ebx
	pop eax
	push eax
	push ebx
	push ecx
	push edx
	invoke     crt_printf,addr data_blank
	invoke     crt_printf, addr buffer, _b
	pop edx
	pop ecx
	pop ebx
	pop eax
@0:
	MOV eax, _i
	CMP eax, _n
	jl @1
	jmp @2
@1:
	MOV eax,_b
	MOV _t,eax
	MOV eax, _a
	ADD eax, _b
	MOV _b,eax
	push eax
	push ebx
	push ecx
	push edx
	invoke     crt_printf,addr data_blank
	invoke     crt_printf, addr buffer, _b
	pop edx
	pop ecx
	pop ebx
	pop eax
	MOV eax,_t
	MOV _a,eax
	MOV eax, _i
	ADD eax, 1
	MOV _i,eax
	jmp @0
@2:
	ret 
end _start
