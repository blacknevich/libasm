section .text

global _ft_strcmp

; rdi - our first str
; rsi - our second str
_ft_strcmp:
			xor rcx, rcx
			xor rax, rax
			.loop_counter:
			mov al, BYTE [rdi + rcx]
			sub al, BYTE [rsi + rcx]
			jnz out
			cmp BYTE [rdi + rcx], 0
			jz out
			cmp BYTE [rsi + rcx], 0
			jz out
			inc rcx
			jmp .loop_counter

out:
			cmp al, 127
			ja negative
			ret

negative:
			sub rax, 256
			ret
