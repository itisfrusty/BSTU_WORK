#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int Asmb_str()
{
    _asm {
        model small
        .stack 100h
        .data
        mes1 db "Vvedite stroky: $"
        mes3 db 0ah, 0dh, "Kol-vo povtoreniy vvedennogo simvola: $"
        mes4 db 0ah, 0dh, "Vvedite proizvonuy simvol dlya sravneniya: $"
        mes5 db 0ah, 0dh, "Simvol nekorrekten: $"
        string db 10 dup("$")
        len_string = $ - string
        adr_string dd string
        .code
        main :
        mov ax, @data
            mov ds, ax
            xor ax, ax
            mov ah, 09h; заносим в ah 09h
            lea dx, mes1; в dx смещение строки mes1
            int 21h; вызов прерывани€ DOS дл€ вывода строки
            mov cx, len_string; в cx заносим длину строки
            dec cx; уменьшить на * 1 счЄтчик cx
            les di, adr_string; в di смещение, в es сегментный адресс
            m1 :
        mov ah, 01h; в ah заносим 01h
            int 21h; в AL - символ, полученный из станлартного ввода*
            cmp al, 0dh; провер€ем нажатие Enter
            je prov; если равно прыгаем на метку prov
            cmp al, 0; сравниваем al с нулЄм
            jne m2; если не равно прыгаем на метку m2
            jmp prov; прыгаем на метку prov
            m2 :
        stosb; переписываем содержимое AL в €чейку пам€ти с адрессом ES : (E)DI, после чего прибовл€ем единицу к(E)DI.

            loop m1; выполн€ем m1, пока* cx не станет равным нулю
            prov :
        mov cx, len_string; в cx заносим длину строки
            dec cx; уменьшаем cx на единицу
            mov si, 0; переводим сегментный регистор si** в начало строки
            exit :

        lea dx, mes4
            mov ah, 09h
            int 21h
            mov ah, 01h
            int 21h
            cmp al, 0
            je not2
            go :
        cmp string[si], al
            jne go1
            inc bh
            go1 :
        inc si
            loop go
            lea dx, mes3
            mov ah, 09h
            int 21h
            add bh, "0"
            mov dl, bh
            mov ah, 02h
            int 21h
            jmp ex
            not2 :
        lea dx, mes5
            mov ah, 09h
            int 21h
            ex :
        mov ax, 4c00h
            mov ah, 10h

            mov ah, 0
            int 16h

            mov ah, 4Ch
            int 21h
            end main
    }
    return 0;
}

int main()
{
    Asmb_str();
    return 0;
}
