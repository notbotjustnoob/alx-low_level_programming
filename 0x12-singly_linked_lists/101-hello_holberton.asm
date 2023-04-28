section .data
    hello db "Hello, Holberton", 0

section .text
    global main

    extern printf

    main:
        push rbp
        mov rbp, rsp

        ; format string "%s\n" in rdi
        mov rdi, format
        ; address of hello string in rsi
        mov rsi, hello
        ; call printf
        call printf

        mov rsp, rbp
        pop rbp
        xor eax, eax
        ret

    section .rodata
        format db "%s", 0x0A, 0
