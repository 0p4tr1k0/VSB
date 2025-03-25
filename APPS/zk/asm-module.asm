section .text
global jen_prvocisla
global bubble
global pocet_malych_pismen

; Prvni funkce: Oznaceni prvocisel
jen_prvocisla:
    ; rdi = pole (ukazatel na pole)
    ; rsi = velikost (delka pole)
    push rbp
    mov rbp, rsp
    
    mov rcx, 2  ; start od 2
.outer_loop:
    cmp rcx, rsi
    jge .end_prvocisla

    ; Kontrola, zda je cislo prvocislo
    mov r8, rcx  ; r8 = aktualni cislo
    mov r9, 2    ; delitel

.inner_loop:
    cmp r9, r8
    jge .je_prvocislo

    ; Kontrola delitelnosti
    mov rax, r8
    xor rdx, rdx
    div r9
    
    ; Pokud zbytek 0, neni prvocislo
    cmp rdx, 0
    je .oznacz_nulou

    inc r9
    jmp .inner_loop

.oznacz_nulou:
    mov qword [rdi + (rcx - 1) * 8], 0
    jmp .dalsi_cislo

.je_prvocislo:
    ; Prvocislo zustava beze zmeny
.dalsi_cislo:
    inc rcx
    jmp .outer_loop

.end_prvocisla:
    pop rbp
    ret

; Druha funkce: Bubble Sort
bubble:
    ; rdi = pole (ukazatel na pole)
    ; rsi = velikost (delka pole)
    ; rdx = smer (1 pro vzestupny, 0 pro sestupny)
    push rbp
    mov rbp, rsp

    ; Vnější cyklus
    mov rcx, 0  ; i = 0
.outer_sort:
    cmp rcx, rsi
    jge .end_bubble

    ; Vnitřní cyklus
    mov r8, 0  ; j = 0
.inner_sort:
    mov r9, rsi
    sub r9, rcx
    sub r9, 1
    cmp r8, r9
    jge .next_outer_iteration

    ; Porovnání a prohazování
    mov eax, [rdi + r8 * 4]
    mov ebx, [rdi + (r8 + 1) * 4]

    ; Kontrola směru řazení
    cmp rdx, 1
    je .vzestupne
    
    ; Sestupně
    cmp eax, ebx
    jl .prohod
    jmp .pokracuj_vnitrni

.vzestupne:
    cmp eax, ebx
    jg .prohod
    jmp .pokracuj_vnitrni

.prohod:
    mov [rdi + r8 * 4], ebx
    mov [rdi + (r8 + 1) * 4], eax

.pokracuj_vnitrni:
    inc r8
    jmp .inner_sort

.next_outer_iteration:
    inc rcx
    jmp .outer_sort

.end_bubble:
    pop rbp
    ret

; Treti funkce: Pocet ruznych malych pismen
pocet_malych_pismen:
    ; rdi = retezec (ukazatel na retezec)
    push rbp
    mov rbp, rsp
    
    ; Bitove pole pro sledovani unikatních písmen
    mov rax, 0  ; Inicializace bitoveho pole na 0

.cyklus:
    ; Nacti aktualni znak
    movzx rcx, byte [rdi]
    
    ; Kontrola konce retezce
    test rcx, rcx
    jz .konec

    ; Kontrola zda je znak male pismeno (a-z)
    cmp rcx, 'a'
    jl .dalsi_znak
    cmp rcx, 'z'
    jg .dalsi_znak

    ; Vypocet bitove pozice (a=0, b=1, ...)
    sub rcx, 'a'
    
    ; Nastaveni prislusneho bitu v bitovem poli
    mov rdx, 1
    shl rdx, cl
    or rax, rdx

.dalsi_znak:
    ; Posun na dalsi znak
    inc rdi
    jmp .cyklus

.konec:
    ; Spocitej nastavene bity
    xor rcx, rcx  ; Pocitadlo nastavených bitu
    mov rdx, rax  ; Kopie bitoveho pole

.pocitej_bity:
    test rdx, rdx
    jz .navrat

    ; Pocitej nejmensi bit
    mov rsi, rdx
    and rsi, 1
    add rcx, rsi

    ; Posun doprava
    shr rdx, 1
    jmp .pocitej_bity

.navrat:
    ; Vrat pocet unikatnich malych pismen
    mov rax, rcx
    pop rbp
    ret