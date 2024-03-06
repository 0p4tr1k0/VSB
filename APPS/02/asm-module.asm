bits 64

    section .data
        
    
    section .text
        global nsc
        global nlc

nsc:
    mov rcx, 0
    mov rax, 0

najdinsc:
    cmp rcx, 6

    jge print_najdinsc

    mov rbx, [intArray + rcx*8]
    test rbx, 1
    jnz next_int
    
    cmp rax, 0
    je save_nc

    cmp rax, rbx
    jge next_int

save_nc:
    mov rax, rbx

next_int:
    inc rcx
    jmp najdinsc

nlc:
    mov rcx, 0
    mov rax, 0

najdinlc:
    cmp ecx, 6

    jge exit_program

    mov rdx, [longArray + ecx*8]
    test rdx, 1
    jnz next_long

    cmp rdx, rax
    jle next_long

save_nlc
    mov rax, rdx

next_long:
    inc rcx
    jmp najdinlc


exit_program:
    ret
    

    
