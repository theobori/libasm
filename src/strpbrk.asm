bits 64
global strpbrk

section	.text

strpbrk:
	cmp 	rdi, 0
	jz 		.not_found
	cmp 	rsi, 0
	jz 		.not_found
  	cmp   	 byte [rdi], 0
  	jz    	.not_found

    jmp    	.is_in
	jmp		.loop_next

.is_in:
	xor 	r9, r9

.is_in_loop:
	mov 	r10b, byte [rsi + r9]

	cmp 	r10b, 0
	jz 		.loop_next

	cmp 	r10b, byte [rdi]
	jz 		.end

	inc 	r9
	jmp 	.is_in_loop

.not_found:
	xor 	rax, rax
	ret

.loop_next:
	inc		rdi
	jmp 	strpbrk

.end:
	mov 	rax, rdi
	ret
