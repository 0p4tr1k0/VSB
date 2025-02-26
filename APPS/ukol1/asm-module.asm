section .text
    global count_odd_numbers
    global move_negative_numbers
    global count_vowels
    global replace_third_char

; Function to count odd numbers in an array
; Parameters:
;   rdi = pointer to g_int_array
;   rsi = size of array
;   rdx = pointer to g_int_outup
; Return:
;   rax = number of odd numbers
count_odd_numbers:
    push rbp
    mov rbp, rsp
    push rbx
    push r12
    
    xor rax, rax        ; Initialize counter to 0
    xor rbx, rbx        ; Use as array index
    
.count_loop:
    cmp rbx, rsi        ; Check if we've reached the end of the array
    jge .count_done     ; If so, exit the loop
    
    mov r12d, [rdi + rbx*4]  ; Load current array element
    test r12d, 1        ; Test if the number is odd (bit 0 is set)
    jz .next_element    ; If not odd, go to next element
    
    inc rax             ; Increment odd number counter
    
.next_element:
    inc rbx             ; Move to next array element
    jmp .count_loop
    
.count_done:
    ; Store the result (rax) in g_int_outup
    mov [rdx], eax
    
    pop r12
    pop rbx
    pop rbp
    ret

; Function to move negative numbers to a new array
; Parameters:
;   rdi = pointer to g_int_array
;   rsi = size of array
;   rdx = pointer to g_neg_val_array
; Return: none
move_negative_numbers:
    push rbp
    mov rbp, rsp
    push rbx
    push r12
    push r13
    
    xor rbx, rbx        ; Input array index
    xor r12, r12        ; Output array index
    
.move_loop:
    cmp rbx, rsi        ; Check if we've reached the end of the array
    jge .move_done      ; If so, exit the loop
    
    mov r13d, [rdi + rbx*4]  ; Load current array element
    test r13d, r13d     ; Test if the number is negative
    jns .next_element   ; If not negative, go to next element
    
    mov [rdx + r12*4], r13d  ; Store negative number in output array
    inc r12             ; Increment output array index
    
.next_element:
    inc rbx             ; Move to next input array element
    jmp .move_loop
    
.move_done:
    pop r13
    pop r12
    pop rbx
    pop rbp
    ret

; Function to count vowels in a character array
; Parameters:
;   rdi = pointer to g_char_array
;   rsi = size of array
; Return:
;   rax = number of vowels
count_vowels:
    push rbp
    mov rbp, rsp
    push rbx
    
    xor rax, rax        ; Initialize vowel counter to 0
    xor rbx, rbx        ; Use as array index
    
.vowel_loop:
    cmp rbx, rsi        ; Check if we've reached the end of the array
    jge .vowel_done     ; If so, exit the loop
    
    mov cl, [rdi + rbx] ; Load current character
    test cl, cl         ; Check if null terminator
    jz .vowel_done      ; If null terminator, we're done
    
    ; Convert to lowercase for easier comparison
    cmp cl, 'A'
    jl .not_uppercase
    cmp cl, 'Z'
    jg .not_uppercase
    add cl, 32          ; Convert to lowercase
    
.not_uppercase:
    ; Check if vowel (a, e, i, o, u)
    cmp cl, 'a'
    je .is_vowel
    cmp cl, 'e'
    je .is_vowel
    cmp cl, 'i'
    je .is_vowel
    cmp cl, 'o'
    je .is_vowel
    cmp cl, 'u'
    je .is_vowel
    ; Czech vowels with diacritics
    cmp cl, 0xE1        ; á
    je .is_vowel
    cmp cl, 0xE9        ; é
    je .is_vowel
    cmp cl, 0xED        ; í
    je .is_vowel
    cmp cl, 0xF3        ; ó
    je .is_vowel
    cmp cl, 0xFA        ; ú
    je .is_vowel
    cmp cl, 0xFD        ; ý
    je .is_vowel
    jmp .next_char
    
.is_vowel:
    inc rax             ; Increment vowel counter
    
.next_char:
    inc rbx             ; Move to next character
    jmp .vowel_loop
    
.vowel_done:
    pop rbx
    pop rbp
    ret

; Function to replace every third character with '3'
; Parameters:
;   rdi = pointer to g_char_array
;   rsi = size of array
; Return: none
replace_third_char:
    push rbp
    mov rbp, rsp
    push rbx
    
    xor rbx, rbx        ; Use as array index
    
.replace_loop:
    cmp rbx, rsi        ; Check if we've reached the end of the array
    jge .replace_done   ; If so, exit the loop
    
    mov cl, [rdi + rbx] ; Load current character
    test cl, cl         ; Check if null terminator
    jz .replace_done    ; If null terminator, we're done
    
    ; Check if this is third character (index % 3 == 2)
    mov rax, rbx
    xor rdx, rdx
    mov rcx, 3
    div rcx
    
    cmp rdx, 2          ; Is remainder 2? (3rd character)
    jne .next_char
    
    mov byte [rdi + rbx], '3'  ; Replace with '3'
    
.next_char:
    inc rbx             ; Move to next character
    jmp .replace_loop
    
.replace_done:
    pop rbx
    pop rbp
    ret

section .note.GNU-stack noalloc noexec nowrite progbits