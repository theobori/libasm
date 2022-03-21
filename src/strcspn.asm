bits 64
global strcspn

section	.text

strcspn:
    xor     rcx, rcx

	cmp 	rdi, 0
	jz 		.end
	cmp 	rsi, 0
	jz 		.end

.loop:
  	cmp   	byte [rdi], 0
  	jz    	.end

    jmp    .is_in
	jmp    .loop_next

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

.loop_next:
	inc		rdi
    inc     rcx
	jmp 	.loop

.end:
	mov 	rax, rcx
	ret
