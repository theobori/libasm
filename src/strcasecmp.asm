bits 64
global strcasecmp

section	.text

strcasecmp:
	xor 	r8, r8
	xor 	r9, r9
	xor 	r10, r10

	cmp 	rsi, 0
	jz 		.ret_positive
	cmp 	rdi, 0
	jz 		.ret_negative

.loop:
	mov 	r8b, [rdi]
	mov 	r9b, [rsi]

	mov 	r10b, r8b
	call 	.is_lower_after
	mov 	r8b, r10b
	mov 	r10b, r9b
	call 	.is_lower_after
	mov 	r9b, r10b

	cmp 	byte [rdi], 0
	jz 		.end

	cmp 	byte [rsi], 0
	jz 		.end

	cmp		r8b, r9b
	jne		.end

  	inc		rdi
	inc 	rsi
  	jmp   	.loop

.is_lower_after:
	cmp 	byte r10b, 'a'
	jge 	.is_lower_before
	ret

.is_lower_before:
	cmp 	byte r10b, 'z'
	jle 	.to_upper
	ret

.to_upper:
	sub 	r10b, 32
	ret

.ret_positive:
	mov 	rax, 1
  	ret

.ret_negative:
	mov 	rax, -1
  	ret

.end:
	sub 	r8, r9

	mov   	rax, r8
  	ret
