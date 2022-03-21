bits 64
global strstr

%include "src/strlen.asm"
%include "src/strncmp.asm"

section	.text

strstr:
    cmp 	rdi, 0
	jz 		.not_found
	cmp 	rsi, 0
	jz 		.not_found

    call 	.get_length
    mov 	rdx, rax

.loop:

    call 	strncmp

    cmp 	rax, 0
    je 		.end

    cmp 	[rdi], byte 0
    je 		.not_found

    inc 	rdi

    jmp 	.loop

.not_found:
	xor 	rax, rax
	ret

.get_length:
    push 	rdi

    mov 	rdi, rsi
    call 	strlen

    pop 	rdi
    ret

.end:
    mov     rax, rdi
    ret
