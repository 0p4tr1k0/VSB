;***************************************************************************
;
; Program for education in subject "Assembly Languages" and "APPS"
; petr.olivka@vsb.cz, Department of Computer Science, VSB-TUO
;
; Empty project
;
;***************************************************************************

    bits 64

    section .data

    ;variables

    global g_some_asm_var
    extern g_some_c_var

    
    extern g_string
    

    section .text
    ;functions


    global set_string

set_string:
    enter 0,0

    mov [ g_string ], 'X' ; g_string = X
    mov ah, 'A'          ; ah = A
    mov [ g_string + 1], ah ; [g_string + ah] = XA

    leave
    ret