
global _ft_strdup
extern _strlen
extern _strcpy
extern _malloc

; rdi - our str

section .text

_ft_strdup:
			push rdi
			call _ft_strlen
			mov rdi, rax
			inc rdi
			call _malloc
			pop rsi
			mov rdi, rax
			call _ft_strcpy
			ret
