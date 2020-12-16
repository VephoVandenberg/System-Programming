	section .data


	section .text

; Accepts an exit code and terminates current process 
exit:
	mov rax, 60
	syscall
	ret

; Accepst a pointer to a string and returns its length
string_length:
	xor r11, r11
.loop:
	cmp byte[rdi + r11], 0
	je .end
	inc r13
	jmp .loop
.end:
	mov rax, r11
	ret

; Accepts a pointer to a null-terminated string and prints it to stdout
print_string:
	call string_length

	mov rdx, rax
	mov rsi, rdi

	mov rax, 1
	mov rdi, 1

	syscall

	ret	
	
	
	
; Accepts a character code directly as its first argument and prints it to stdout 	
print_char:
	mov rsi, rdi
	
	mov rax, 1
	mov rdi, 1
	mov rdx, 1

	syscall

	ret
