bits 64
global strrchr
global rindex

section	.text

rindex:
strrchr:
    xor     rax, rax
	cmp 	rdi, 0
	jz 		.end

.loop:
  	cmp   	[rdi], sil
  	jz    	.store_addr

	jmp 	.end_loop

.end_loop:
	cmp 	[rdi], byte 0
    jz 		.end
    inc     rdi
	jmp		.loop

.store_addr:
    mov     rax, rdi
    jmp     .end_loop

.end:
  	ret
