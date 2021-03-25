section .text

global _ft_read
extern ___error

; rdi - our fd
; rsi - our buf
; rdx - our symbols count
_ft_read:
			mov rax, 0x02000003
			syscall
			jc error
			ret

error:
			push rax
			call ___error
			pop QWORD [rax]
			mov rax, -1
			ret
