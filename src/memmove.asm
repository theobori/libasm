bits 64
global memmove

section	.text

memmove:
	push 	rcx
	xor 	rcx, rcx

	cmp 	rdi, 0
	jz 		.end
	cmp 	rsi, 0
	jz 		.end
	cmp 	rdi, rsi
	jae 	.loop_from_right

.loop_from_left:
	cmp 	rdx, rcx
	jz 		.end
  	mov 	r8b, [rsi + rcx]
	mov 	[rdi + rcx], r8b
	inc 	rcx
  	jmp   	.loop_from_left

.loop_from_right:
	cmp 	rdx, 0
	jz 		.end
  	mov 	r8b, [rsi + rdx - 1]
	mov 	[rdi + rdx - 1], r8b
  	dec		rdx
  	jmp   	.loop_from_right

.end:
	pop		rcx

	mov   	rax, rdi
  	ret
