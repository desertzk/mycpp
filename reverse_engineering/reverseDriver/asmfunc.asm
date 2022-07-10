option casemap:none

;main Proto

.data
;ttt qword ?

.code

getcurthread Proc
    int 3
	mov rax, qword ptr gs:[188h]
	add rax, 184
	mov rcx, [rax]
	mov rax, rcx
	ret
getcurthread Endp


END