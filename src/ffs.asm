bits 64
global ffs

section	.text

ffs:
	push 	rdi
	push 	rcx
    xor     rax, rax
	xor 	rcx, rcx

	cmp 	rdi, 0
	jz 		.zero

.loop:
	cmp 	rcx, 32
	jz 		.not_zero

	mov 	r8, rdi
	and 	r8, 1

	cmp 	r8, 1
	je 		.not_zero

	shr 	rdi, 1
	inc 	rcx

	jmp 	.loop

.not_zero:
	inc 	rcx

.zero:
	mov 	rax, rcx
	pop 	rcx
	pop 	rdi
  	ret
