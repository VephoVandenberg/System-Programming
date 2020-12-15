	sectino .data


	section .text

; Accepts an exit code and terminates current process 
exit:
	mov rax, 60
	syscall
	ret

;Accepst a pointer to a string and returns its length
string_length:
	xor r11, r11
.loop:
	cmp [rdi + r11], 0
	je .end
	inc r13
	jmp .loop
.end:
	mov rax, r11
	ret
