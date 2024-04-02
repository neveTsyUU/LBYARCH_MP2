section .text
global daxpy_asm

daxpy_asm:
    ; RDI = n, XMM0 = A, RSI = X, RDX = Y, RCX = Z
    xor rax, rax            ; Counter set to 0

loop_start:
    cmp rax, rdi            ; Compare counter with n
    jge loop_end            ; If counter >= n, exit loop

    movsd xmm1, [rsi + rax*8] ; Load X[i] into xmm1
    movsd xmm2, [rdx + rax*8] ; Load Y[i] into xmm2
    mulsd xmm1, xmm0        ; Multiply X[i] by A: xmm1 = xmm1 * A
    addsd xmm1, xmm2        ; Add Y[i] to the product: xmm1 = xmm1 + xmm2
    movsd [rcx + rax*8], xmm1 ; Store result in Z[i]

    inc rax                 ; Increment counter
    jmp loop_start          ; Repeat loop

loop_end:
    ret                     ; Return from function