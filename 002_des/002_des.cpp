#include <windows.h>
#include <string>
#include <winDNS.h>
#include <iostream>
#include "cipher.h"



#define TRUNC(a, b) (a + (b - ((a % b) ? (a % b) : b)))

int main()
{
    std::string plain_text = "Alexey Fyodorovitch Karamazov was the third son of Fyodor Pavlovitch Karamazov, a land owner well known in our district in his own day, and still remembered among us owing to his gloomy and tragic death, which happened thirteen years ago, and which I shall describe in its proper place. For the present I will only say that this ìlandownerîófor so we used to call him, although he hardly spent a day of his life on his own estateówas a strange type, yet one pretty frequently to be met with, a type abject and vicious and at the same time senseless. But he was one of those senseless persons who are very well capable of looking after their worldly affairs, and, apparently, after nothing else. Fyodor Pavlovitch, for instance, began with next to nothing; his estate was of the smallest; he ran to dine at other menís tables, and fastened on them as a toady, yet at his death it appeared that he had a hundred thousand roubles in hard cash. At the same time, he was all his life one of the most senseless, fantastical fellows in the whole district. I repeat, it was not stupidityóthe majority of these fantastical fellows are shrewd and intelligent enoughóbut just senselessness, and a peculiar national form of it.";
  
    QWORD key = 0xBEEFBABECAFEBABE;

    DWORD text_size = plain_text.length();
    DWORD newTextSize = TRUNC(text_size, 8); // ‚˚‡‚ÌË‚‡ÌËÂ ÔÓ 64 ·ËÚÌ˚Ï ·ÎÓÍ‡Ï
    BYTE* hPlainText = (BYTE*)GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, newTextSize);
    memmove(hPlainText, &plain_text, text_size);
    QWORD c_text = 0;
    c_text = ecb_cipher(hPlainText, key);
    
    return 0;
}


