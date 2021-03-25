section .text

global _ft_strcpy

; rdi - our dst str
; rsi - our src str
_ft_strcpy:
			xor rcx, rcx
			xor rax, rax
			.loop_counter:
			cmp BYTE [rsi + rcx], 0
			jz out
			mov r10b, BYTE [rsi + rcx]
			mov BYTE [rdi + rcx], r10b
			inc rcx
			jmp .loop_counter

out:
			mov BYTE [rdi + rcx], 0
			mov rax, rdi
			ret
