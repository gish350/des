#include <windows.h>
#include <string>
#include <winDNS.h>
#include <iostream>
#include "cipher.h"
#include <iomanip>



#define TRUNC(a, b) (a + (b - ((a % b) ? (a % b) : b)))



std::string memToStr(const void* memory, size_t size) 
{
    const char* temp = static_cast<const char*>(memory);
    std::string str(temp, size);
    return str;
}

void dumpMemory(const void* ptr, size_t length) {
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(ptr);
    size_t index = 0;

    while (index < length) {
        std::cout << std::hex << std::setfill('0');
        for (size_t i = 0; i < 16 && index + i < length; ++i) {
            std::cout << std::setw(2) << (int)(bytes[index + i]) << ' ';
        }
        std::cout << std::dec << std::setfill(' ') << std::endl;
        index += 16;
    }
}

int main()
{
    std::string plain_text;
   // plain_text = "Alexey Fyodorovitch Karamazov was the third son of Fyodor Pavlovitch Karamazov, a land owner well known in our district in his own day, and still remembered among us owing to his gloomy and tragic death, which happened thirteen years ago, and which I shall describe in its proper place. For the present I will only say that this �landowner��for so we used to call him, although he hardly spent a day of his life on his own estate�was a strange type, yet one pretty frequently to be met with, a type abject and vicious and at the same time senseless. But he was one of those senseless persons who are very well capable of looking after their worldly affairs, and, apparently, after nothing else. Fyodor Pavlovitch, for instance, began with next to nothing; his estate was of the smallest; he ran to dine at other men�s tables, and fastened on them as a toady, yet at his death it appeared that he had a hundred thousand roubles in hard cash. At the same time, he was all his life one of the most senseless, fantastical fellows in the whole district. I repeat, it was not stupidity�the majority of these fantastical fellows are shrewd and intelligent enough�but just senselessness, and a peculiar national form of it.";
    std::getline(std::cin, plain_text);
    
    
   
    
    QWORD key = 0xBEEFBABECAFEBABE;

    DWORD text_size = plain_text.length();
    DWORD newTextSize = TRUNC(text_size, 8); // ������������ �� 64 ������ ������
    auto dataPtr = plain_text.data();
    BYTE* hPlainText = (BYTE*)GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, newTextSize);
    memmove(hPlainText, dataPtr, newTextSize);
    BYTE* hCipherText = 0;
    std::cout << std::endl << "PLAIN TEXT: " << plain_text << std::endl;
    std::cout << std::endl << "KEY: " << std::hex << key << std::endl;
    std::cout << std::endl << "          =====PLAIN TEXT (HEX)=====" << std::endl;
    dumpMemory(hPlainText, newTextSize);
    std::cout << "          =====PLAIN TEXT (HEX) END=====" << std::endl;
    hCipherText = ecb_cipher(hPlainText, newTextSize, key);

    
    std::cout << std::endl << "          =====DES-ECB (HEX)=====" <<std::endl;
    dumpMemory(hCipherText, newTextSize);
    std::cout  << "          =====DES-ECB (HEX) END=====" <<std::endl;

    BYTE* hDeCipher = 0;
    hDeCipher = ecb_decipher(hCipherText, newTextSize, key);
    std::string decipher_ecb = memToStr(hDeCipher, newTextSize);
    std::cout << std::endl << "          =====DES-ECB DECIPHERED ===== " << std::endl;
    std::cout << decipher_ecb << std::endl;
   
    return 0;
}


