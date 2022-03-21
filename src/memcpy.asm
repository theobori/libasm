bits 64
global memcpy

section	.text

memcpy:
	push	rcx
	xor 	rcx, rcx

	cmp 	rdi, 0
	jz 		.end
	cmp 	rsi, 0
	jz 		.end
	cmp 	rdi, rsi
	je 		.end

.loop:
  	mov 	r8b, [rsi + rcx]
	mov 	[rdi + rcx], r8b

  	dec		rdx
	inc 	rcx

	cmp 	rdx, 0
	jz 		.end

  	jmp   	.loop

.end:
	pop		rcx

	mov   	rax, rdi
  	ret
