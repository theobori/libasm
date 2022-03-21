bits 64
global memset

section	.text

memset:
	push 	rcx
	xor 	rcx, rcx

.loop:
	cmp 	rdi, 0
	jz 		.end

	cmp 	rdx, 0
	jz 		.end

  	mov 	byte [rdi + rcx], sil

  	dec		rdx
	inc 	rcx
  	jmp   	.loop

.end:
	pop 	rcx

  	mov   	rax, rdi
  	ret
