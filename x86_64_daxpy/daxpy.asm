global daxpy_asm
section .text

daxpy_asm:
    push rsi
    push rbp
    mov rbp, rsp
    add rbp, 8
    add rbp, 16

    mov r11, 0
    mov r11d, [rbp+32]
    mov rax, 0

L1_unique:
    movsd xmm1, xmm0
    mulsd xmm1, [rdx+8*rax]
    vaddsd xmm2, xmm1, [r8+8*rax]
    movsd [r9+8*rax], xmm2
    xorpd xmm2, xmm2
    xorpd xmm1, xmm1

    add rax, 1
    cmp rax, r11
    jne L1_unique

    pop rbp
    pop rsi
    ret