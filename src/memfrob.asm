bits 64
global memfrob

section	.text

memfrob:
    xor     rax, rax
	xor 	rcx, rcx

	cmp 	rdi, 0
	jz 		.null

.loop:
	cmp 	rsi, rcx
	jz 		.end

	xor 	byte [rdi + rcx], 42

	inc 	rcx
	jmp 	.loop

.null:
	ret

.end:
	mov 	rax, rdi
	ret
