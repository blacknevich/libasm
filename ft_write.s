section .text

global _ft_write
extern ___error

; rdi - our fd
; rsi - our message
; rdx - our symbols count
_ft_write:
			mov rax, 0x02000004
			syscall
			jc error
			ret

error:
			push rax
			call ___error
			pop QWORD [rax]
			mov rax, -1
			ret
