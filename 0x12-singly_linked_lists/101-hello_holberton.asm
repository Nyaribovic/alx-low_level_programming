; File: 101-hello_holberton.asm
; Auth: Budi Victor
; Desc: 64-bit assembly program that prints
;       Hello, Holberton followed by a new line.

section .data
    hello db 'Hello, Holberton', 0
    format db '%s', 0
    newline db 10, 0

section .text
    global main

    extern printf

main:
    ; Call printf with the hello string as the argument
    mov rdi, format
    mov rsi, hello
    call printf

    ; Print a new line
    mov rdi, format
    mov rsi, newline
    call printf

    ; Exit the program
    xor rdi, rdi
    call exit

section .bss
    ; Reserve space for the exit function
    resb 8
