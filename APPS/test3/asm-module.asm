section .text
global nejmensi_56bit

nejmensi_56bit:
    ; Nastavení registru
    mov rdi, rdi                  ; tp_array
    mov rsi, rsi                  ; t_N

    ; Inicializace proměnných
    mov rax, 0xFFFFFFFFFFFFFFF   ; Inicializace s nejvyšší hodnotou

    ; Iterace přes pole
    mov rcx, rsi
    mov rdx, rdi
    nejmensi_56bit_loop:
        ; Načtení hodnoty z pole
        mov r8, [rdx]

        ; Test, zda je dolní bajt nulový
        test byte [rdx], 0xFF

        ; Podmínka - pokud je dolní bajt nulový a hodnota menší než aktuální minimum
        jnz nejmensi_56bit_skip
        cmp r8, rax
        jl nejmensi_56bit_update
        nejmensi_56bit_skip:

        ; Přesun na další prvek v poli
        add rdx, 8

        ; Dekrementace počtu prvků
        loop nejmensi_56bit_loop
        jmp nejmensi_56bit_end

    nejmensi_56bit_update:
        ; Aktualizace aktuálního minima
        mov rax, r8
        jmp nejmensi_56bit_skip

    nejmensi_56bit_end:
        ; Návratová hodnota (minimum)
        ret
;******************************************************
section .data
    g_tabulka db "0123456789ABCDEF"

section .text
global long2hexstr

long2hexstr:
    ; Nastavení registru
    mov rdi, rdi                  ; t_num
    mov rsi, rsi                  ; tp_str

    ; Inicializace proměnných
    mov rcx, 8                    ; Počet hex znaků
    mov rdx, rdi                  ; Kopie hodnoty t_num pro manipulaci

    ; Převeď číslo na hex string
    hexstr_loop:
        ; Poslední čtyři bity čísla
        and dl, 0xF
        ; Získání odpovídajícího hex znaku z tabulky
        mov al, [g_tabulka + dl]
        ; Uložení hex znaku do tp_str
        mov [rsi], al
        ; Posun na další pozici v tp_str
        inc rsi
        ; Posunutí čísla o čtyři bity doprava
        shr rdx, 4

        ; Dekrementace počtu zbývajících hex znaků
        loop hexstr_loop

    ; Přidání null-terminátoru
    mov byte [rsi], 0

    ; Návratová hodnota (žádná)
    ret

;*********************************************************

section .text
global pismena

pismena:
    ; Nastavení registru
    mov rdi, rdi                  ; tp_str

    ; Inicializace proměnných
    xor rax, rax                  ; citac = 0

    ; Zjisti, zda je v řetězci více malých či velkých písmen
    pismena_loop:
        ; Načtení aktuálního znaku z tp_str
        mov al, [rdi]
        ; Test, zda je konec řetězce
        test al, al
        jz pismena_end

        ; Test, zda je znak velkým písmenem
        cmp al, 'A'
        jl pismena_maly
        cmp al, 'Z'
        jg pismena_velky
        jmp pismena_next

    pismena_maly:
        ; Malé písmeno - sniž citac
        sub rax, 1
        jmp pismena_next

    pismena_velky:
        ; Velké písmeno - zvyš citac
        add rax, 1

    pismena_next:
        ; Posun na další znak v řetězci
        inc rdi
        jmp pismena_loop

    pismena_end:
        ; Návratová hodnota (citac)
        ret

;*************************************************************

section .text
global pocet_slov

pocet_slov:
    ; Nastavení registru
    mov rdi, rdi                  ; tp_str

    ; Inicializace proměnných
    xor rax, rax                  ; pocet_slov = 0
    xor rcx, rcx                  ; flag_mezera = 0

    ; Projdi celý řetězec
    pocet_slov_loop:
        ; Načtení aktuálního znaku z tp_str
        mov al, [rdi]
        ; Test, zda je konec řetězce
        test al, al
        jz pocet_slov_end

        ; Preskakuj mezery
        cmp al, ' '
        je preskoc_mezery
        jmp pocet_slov_ne_mezery

    preskoc_mezery:
        ; Zjištění, zda jsou mezery za sebou
        cmp rcx, 1
        je preskoc_mezery_next
        ; Nastavení flagu_mezera na 1 (detekce začátku slova)
        mov rcx, 1
        jmp pocet_slov_next

    preskoc_mezery_next:
        ; Preskoč mezery za sebou
        inc rdi
        jmp pocet_slov_loop

    pocet_slov_ne_mezery:
        ; Nastavení flagu_mezera na 0 (detekce konce slova)
        mov rcx, 0
        ; Inkrementace počtu slov
        inc rax

    pocet_slov_next:
        ; Posun na další znak v řetězci
        inc rdi
        jmp pocet_slov_loop

    pocet_slov_end:
        ; Návratová hodnota (pocet_slov)
        ret
