section .text

global _ft_strlen

; rdi - our input str
_ft_strlen:
			xor rax, rax
			.loop_counter:
			cmp BYTE [rdi + rax], 0
			jz out
			inc rax
			jmp .loop_counter

out:
			ret
