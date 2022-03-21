bits 64
global strfry

section	.text

.max_index:
	push rcx
  	xor   	rcx, rcx

.max_index_loop:
	cmp 	r13, 0
	jz 		.max_index_end

  	cmp   	byte [r13 + rcx], 0
  	jz    	.max_index_end

  	inc   	rcx
  	jmp   	.max_index_loop

.max_index_end:
  	mov   	r14, rcx
	pop 	rcx
  	ret

mod:
    xor 	rdx, rdx
    div 	r14
    mov 	rax, rdx
    ret

swap:
	mov 	r10b, byte [rdi + rax]
	mov 	r8b, byte [rdi]

	mov 	byte [rdi + rax], r8b
	mov 	byte [rdi], r10b

	ret

strfry:

	xor 	rax, rax

	cmp 	rdi, 0
	jz 		.end

	; get rdi lenght in r14
	mov 	r13, rdi
	call 	.max_index


.loop:
	cmp 	byte [rdi + rcx], 0
	jz 		.end

	; random number in ecx
	rdtsc
	mov 	rdx, rcx
	call 	mod

	; changing char in rdi
	call 	swap

	inc 	rcx
	jmp 	.loop

.end:
	mov 	rax, rdi
	ret
