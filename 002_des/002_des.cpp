#include <windows.h>
#include <winDNS.h>
#include <iostream>
#include "ecb.h"

// Коррекция ключа: требуется, чтобы сумма битов каждого байта ключа, 
// включая контрольный, была нечетной (нечетный паритетный бит).
void key_correction(LPVOID key)
{
    BYTE* base = (BYTE*)key;

    while ((BYTE*)key - (BYTE*)base != 7)
    {
        int _0 = (*(BYTE*)key & 0x80) >> 7; // 1000 0000
        int _1 = (*(BYTE*)key & 0x40) >> 6; // 0100 0000
        int _2 = (*(BYTE*)key & 0x20) >> 5; // 0010 0000
        int _3 = (*(BYTE*)key & 0x10) >> 4; // 0001 0000
        int _4 = (*(BYTE*)key & 0x8) >> 3;  // 0000 1000
        int _5 = (*(BYTE*)key & 0x4) >> 2;  // 0000 0100
        int _6 = (*(BYTE*)key & 0x2) >> 1;  // 0000 0010
        //7-ой бит - контрольный

        *(BYTE*)key = *(BYTE*)key || 0x1; // контрольный бит - всегда 1

        if (!((_0 + _1 + _2 + _3 + _4 + _5 + _6 + 1) % 2)) // если сумма битов четная:
        {
            *(BYTE*)key = *(BYTE*)key ^ 0x80; // меняем первый бит на противоположный
        }
        key = (BYTE*)key + 1; // указатель на i-ый байт ключа
    }

    key = (BYTE*)key - 8; // возврат указателя в начало
}

int main()
{
    const char plain_text[] = "plain text ;)";
    QWORD key = 0xBEEFBABECAFEBABE;

    key_correction(&key);
    QWORD pc1_key = 0; 
    pc1_key = pc1(&key);
    make_k1(pc1_key);
        
    return 0;
}


