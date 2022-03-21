bits 64
global strchr
global index

section	.text

index:
strchr:
    xor     rax, rax
	cmp 	rdi, 0
	jz 		.null

.loop:
  	cmp   	[rdi], sil
  	je    	.store_addr

	cmp 	[rdi], byte 0
	jz 		.end

  	inc   	rdi
  	jmp   	.loop

.store_addr:
    mov     rax, rdi
    inc     rdi
    jmp     .end

.null:
	mov 	rax, 0
	ret

.end:
  	ret
