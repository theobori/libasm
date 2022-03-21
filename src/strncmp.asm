bits 64
global strncmp

section	.text

strncmp:
	xor 	r8, r8
	xor 	r9, r9

	cmp 	rsi, 0
	jz 		.ret_positive
	cmp 	rdi, 0
	jz 		.ret_negative

	push 	rdi
    push 	rsi

.loop:
	cmp 	rdx, 0
	jz 		.end

	mov 	r8b, [rdi]
	mov 	r9b, [rsi]

	cmp 	byte [rdi], 0
	jz 		.end

	cmp 	byte [rsi], 0
	jz 		.end

	cmp		r8b, r9b
	jne		.end

	dec 	rdx
  	inc		rdi
	inc 	rsi
  	jmp   	.loop

.ret_positive:
	mov 	rax, 1
  	ret

.ret_negative:
	mov 	rax, -1
  	ret

.end:
	sub 	r8, r9
	mov   	rax, r8

	pop 	rsi
    pop 	rdi

  	ret
