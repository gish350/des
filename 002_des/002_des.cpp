#include <windows.h>
#include <string>
#include <winDNS.h>
#include <iostream>
#include "keys.h"
#include "cipher.h"


//  оррекци€ ключа: требуетс€, чтобы сумма битов каждого байта ключа, 
// включа€ контрольный, была нечетной (нечетный паритетный бит).
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

        *(BYTE*)key = *(BYTE*)key | 0x1; // контрольный бит - всегда 1

        if (!((_0 + _1 + _2 + _3 + _4 + _5 + _6 + 1) % 2)) // если сумма битов четна€:
        {
            *(BYTE*)key = *(BYTE*)key ^ 0x80; // мен€ем первый бит на противоположный
        }
        key = (BYTE*)key + 1; // указатель на i-ый байт ключа
    }

    key = (BYTE*)key - 8; // возврат указател€ в начало
}
#define TRUNC(a, b) (a + (b - ((a % b) ? (a % b) : b)))

int main()
{
    std::string plain_text = "Alexey Fyodorovitch Karamazov was the third son of Fyodor Pavlovitch Karamazov, a land owner well known in our district in his own day, and still remembered among us owing to his gloomy and tragic death, which happened thirteen years ago, and which I shall describe in its proper place. For the present I will only say that this УlandownerФЧfor so we used to call him, although he hardly spent a day of his life on his own estateЧwas a strange type, yet one pretty frequently to be met with, a type abject and vicious and at the same time senseless. But he was one of those senseless persons who are very well capable of looking after their worldly affairs, and, apparently, after nothing else. Fyodor Pavlovitch, for instance, began with next to nothing; his estate was of the smallest; he ran to dine at other menТs tables, and fastened on them as a toady, yet at his death it appeared that he had a hundred thousand roubles in hard cash. At the same time, he was all his life one of the most senseless, fantastical fellows in the whole district. I repeat, it was not stupidityЧthe majority of these fantastical fellows are shrewd and intelligent enoughЧbut just senselessness, and a peculiar national form of it.";
  
    QWORD key = 0xBEEFBABECAFEBABE;

    DWORD text_size = plain_text.length();
    DWORD newTextSize = TRUNC(text_size, 8); // выравнивание по 64 битным блокам
    BYTE* hPlainText = (BYTE*)GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, newTextSize);
    memmove(hPlainText, &plain_text, text_size);
    ecb_cipher(hPlainText);

    key_correction(&key);
    QWORD pc1_key = 0; 
    pc1_key = pc1(&key);
    make_k1(pc1_key);
        
    return 0;
}


