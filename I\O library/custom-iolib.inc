	section .data
new_line:	db 0xa

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
	
; Prints a character with code 0xa	
print_newline:
	mov rdi, new_line
	call print_char
	ret

; Prints unsigned integer
print_uint:
    xor rax, rax
    mov r8, 10
    mov r9, rsp
    mov rax, rdi
    dec rsp
    mov byte[rsp], 0
parse_loop:
    dec rsp
    xor rdx, rdx
    div r8 
    add rdx, '0'
    mov byte[rsp], dl
    test rax, rax
    jnz parse_loop

    mov rdi, rsp
    call print_string

    mov rsp, r9   
    ret

