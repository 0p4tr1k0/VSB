section .text
global faktorial

faktorial:
    ; Nastavení registru
    mov rdi, rdi                  ; N

    ; Inicializace proměnných
    mov rax, 1                    ; Inicializace faktoriálu na 1

    ; Výpočet faktoriálu
    faktorial_loop:
        ; Test, zda došlo k přetečení
        imul rax, rdi
        jc faktorial_overflow

        ; Dekrementace N
        sub rdi, 1
        ; Podmínka pro konec cyklu
        jz faktorial_end

        ; Pokračování v cyklu
        jmp faktorial_loop

    faktorial_end:
        ; Návratová hodnota (faktoriál)
        ret

    faktorial_overflow:
        ; Návratová hodnota 0 v případě přetečení
        mov rax, 0
        ret
;*******************************************************

section .text
global nejvetsi_modulo

nejvetsi_modulo:
    ; Nastavení registrů
    mov rdi, rdi                  ; tp_pole
    mov rsi, rsi                  ; t_N
    mov rdx, rdx                  ; t_K

    ; Inicializace proměnných
    mov rax, 0xFFFFFFFFFFFFFFFF  ; Inicializace nejvyššího zbytku na nejnižší hodnotu

    ; Iterace přes pole
    mov rcx, rsi
    mov rbx, rdi
    nejvetsi_modulo_loop:
        ; Načtení hodnoty z pole
        mov r8, [rbx]

        ; Výpočet zbytku po dělení
        mov r9, r8
        xor r9, rdx
        and r9, rdx

        ; Test, zda je zbytek větší než aktuální maximum
        cmp r9, rax
        jle nejvetsi_modulo_skip

        ; Aktualizace nejvyššího zbytku
        mov rax, r9

    nejvetsi_modulo_skip:
        ; Vynulování čísla, pokud je zbytek menší
        cmp r9, rax
        jne nejvetsi_modulo_zero
        mov [rbx], 0

    nejvetsi_modulo_zero:
        ; Přesun na další prvek v poli
        add rbx, 4

        ; Dekrementace počtu prvků
        loop nejvetsi_modulo_loop

        ; Návratová hodnota (nebylo potřeba vracet žádnou hodnotu)
        ret

;******************************************************************

section .text
global preved_na_velka

preved_na_velka:
    ; Nastavení registru
    mov rdi, rdi                  ; tp_str

    ; Inicializace proměnných
    xor rcx, rcx                 ; Inicializace indexu

    ; Převod řetězce na velká písmena
    preved_na_velka_loop:
        ; Načtení aktuálního znaku z tp_str
        movzx rax, byte [rdi + rcx]

        ; Test, zda je konec řetězce
        test rax, rax
        jz preved_na_velka_end

        ; Test, zda je znak malým písmenem
        cmp rax, 'a'
        jl preved_na_velka_next
        cmp rax, 'z'
        jg preved_na_velka_next

        ; Převod na velké písmeno pomocí instrukce CMOV
        sub rax, 'a' - 'A'
        cmovl rax, rax

        ; Uložení nového znaku na původní místo
        mov [rdi + rcx], al

    preved_na_velka_next:
        ; Inkrementace indexu
        inc rcx
        ; Pokračování v cyklu
        jmp

;*************************************************************************

section .text
global convert_case

convert_case:
    ; Nastavení registru
    mov rdi, rdi      ; tp_str

    ; Přechod přes řetězec
    convert_case_loop:
        ; Načtení aktuálního znaku z řetězce
        mov al, [rdi]

        ; Test, zda je konec řetězce
        test al, al
        jz convert_case_end

        ; Test, zda je znak malým písmenem
        cmp al, 'a'
        jl convert_case_next
        cmp al, 'z'
        jg convert_case_next

        ; Převod malého písmene na velké a uložení zpět do řetězce
        sub al, 32
        mov [rdi], al

    convert_case_next:
        ; Posun na další znak v řetězce
        inc rdi
        jmp convert_case_loop

    convert_case_end:
        ; Návrat
        ret


;**************************************************************************

section .text
global je_prvocislo

je_prvocislo:
    ; Nastavení registru
    mov rdi, rdi      ; num

    ; Ověření, zda je číslo menší než 2
    cmp rdi, 2
    jl je_prvocislo_false

    ; Test, zda je číslo rovno 2
    cmp rdi, 2
    je je_prvocislo_true

    ; Test, zda je číslo dělitelné 2
    test rdi, 1
    jz je_prvocislo_false

    ; Test, zda je číslo dělitelné lichými čísly od 3 do odmocniny z čísla
    mov rax, 3
    je_prvocislo_loop:
        ; Test, zda je číslo dělitelné aktuálním číslem
        mov rdx,


;*******************************************************************************


section .data
    ; Konstanta pro nulu
    zero db '0'

section .text
global soucin

soucin:
    ; Nastavení registru
    mov rdi, rdi                  ; tp_str

    ; Inicializace proměnných
    mov rax, 1                    ; součin = 1

    ; Vypočítej číselný součin všech číslic v řetězci
    soucin_loop:
        ; Načtení aktuálního znaku z tp_str
        movzx rdx, byte [rdi]
        ; Test, zda je konec řetězce
        test rdx, rdx
        jz soucin_end

        ; Test, zda je aktuální znak číslo
        sub rdx, zero
        cmp rdx, 0
        jl soucin_next
        cmp rdx, 9
        jg soucin_next

        ; Převod znaku na číslo a vynásobení součinem
        imul rax, rax, 10
        add rax, rdx

    soucin_next:
        ; Posun na další znak v řetězci
        inc rdi
        jmp soucin_loop

    soucin_end:
        ; Návratová hodnota (součin)
        ret
