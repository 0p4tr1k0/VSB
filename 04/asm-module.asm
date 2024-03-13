section .text
global mocniny

mocniny:
    mov rdi, rdi
    mov ecx, edi
    mov edx, esi
    mov rax, 1

mocnina_loop:
    imul rax, rdx
    mov [rdi], rax
    add rdi, 8
    loop micnina_loop
    ret

;section .text
;global bez_prvocisel_asm
;extern sqrt
;
;bez_prvocisel_asm:
;    mov rsi, rdi
;    mov rcx, rdx
;
;    xor rdi, rdi
;
;    loop_start:
;        cmp rdi, rcx
;        jge end_loop
;
;        mov eax, [rsi + rdi * 4]
;        mov rax, eax
;        call sqrt


section .data
    extern convert_char
    ;extern slovo
    ;extern volba   
    
    extern slovo db 'P', 'e', 't', 'r', 0
    volba db 1

section .text
convert_char:
    xor eax, eax
    cmp [volba], byte 0
    je capitalize
    jne tolower



capitalize:
    movsx bx, [slovo + eax]
    mov dx, bx
    sub bx, 32
    cmp dx, byte 'a'
    cmovge dx, bx
    mov [slovo + eax], dl

    inc eax
    cmp [slovo + eax], byte 0
    je end
    jne capitalize

tolower:
    movsx bx, [slovo + eax]
    mov dx, bx
    add bx, 32
    cmp dx, byte 'a'
    cmovl dx, bx
    mov [slovo + eax], dl

    inc eax
    cmp [slovo + eax], byte 0
    je end
    jne tolower


end:
    ret