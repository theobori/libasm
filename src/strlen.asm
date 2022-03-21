bits 64
global strlen

section	.text

strlen:
  	xor   	rcx, rcx

.loop:
	cmp 	rdi, 0
	jz 		.end

  	cmp   	byte [rdi], 0
  	jz    	.end

  	inc   	rcx
  	inc   	rdi
  	jmp   	.loop

.end:
  	mov   	rax, rcx
  	ret
