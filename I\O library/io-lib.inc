	sectino .data


	section .text

exit:
	mov rax, 60
	syscall
	ret

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
