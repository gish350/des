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
    std::cout << std::endl << "Welcome to DES encrypt tester!" << std::endl;
    std::cout << std::endl << "Enter text to encrypt: " << std::endl;

    std::string plain_text;
    // plain_text = "Alexey Fyodorovitch Karamazov was the third son of Fyodor Pavlovitch Karamazov, a land owner well known in our district in his own day, and still remembered among us owing to his gloomy and tragic death, which happened thirteen years ago, and which I shall describe in its proper place. For the present I will only say that this “landowner”—for so we used to call him, although he hardly spent a day of his life on his own estate—was a strange type, yet one pretty frequently to be met with, a type abject and vicious and at the same time senseless. But he was one of those senseless persons who are very well capable of looking after their worldly affairs, and, apparently, after nothing else. Fyodor Pavlovitch, for instance, began with next to nothing; his estate was of the smallest; he ran to dine at other men’s tables, and fastened on them as a toady, yet at his death it appeared that he had a hundred thousand roubles in hard cash. At the same time, he was all his life one of the most senseless, fantastical fellows in the whole district. I repeat, it was not stupidity—the majority of these fantastical fellows are shrewd and intelligent enough—but just senselessness, and a peculiar national form of it.";
    QWORD key = 0xBEEFBABECAFEBABE;
    std::getline(std::cin, plain_text);

    DWORD text_size = plain_text.length();
    DWORD newTextSize = TRUNC(text_size, 8); // âûðàâíèâàíèå ïî 64 áèòíûì áëîêàì
    auto dataPtr = plain_text.data();
    BYTE* hPlainText = (BYTE*)GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, newTextSize);
    memmove(hPlainText, dataPtr, newTextSize);
    BYTE* hCipherText = 0;
    std::cout << std::endl << "          =====PLAIN TEXT (HEX)=====" << std::endl;
    dumpMemory(hPlainText, newTextSize);
    std::cout << "          =====PLAIN TEXT (HEX) END=====" << std::endl;

    std::cout << std::endl << "Select DES encryption mode:" << std::endl;
    std::cout << "1 - DES-ECB" << std::endl;
    std::cout << "2 - Triple-DES" << std::endl;
    std::cout << "3 - DES-CBC" << std::endl;
    std::cout << "0 - exit" << std::endl;
    int mode = 0;
    std::cin >> mode;

    switch (mode)
    {
        case 1:
        {
            std::cout << "====DES-ECB====" << std::endl;
            std::cout << std::endl << "Enter key in hex (max 16 symbols): " << std::endl;
          //  std::cin >> key;
            hCipherText = ecb_cipher(hPlainText, newTextSize, key);
            std::cout << std::endl << "          =====DES-ECB (HEX)=====" << std::endl;
            dumpMemory(hCipherText, newTextSize);
            std::cout << "          =====DES-ECB (HEX) END=====" << std::endl;
            BYTE* hDeCipher = 0;
            hDeCipher = ecb_decipher(hCipherText, newTextSize, key);
            std::string decipher_ecb = memToStr(hDeCipher, newTextSize);
            std::cout << std::endl << "          =====DES-ECB DECIPHERED=====" << std::endl;
            std::cout << decipher_ecb << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "====Triple-DES====" << std::endl;
            std::cout << "Select Triple-DES type" << std::endl;
            std::cout << "1 - DES-EEE3" << std::endl;
            std::cout << "2 - DES-EDE3" << std::endl;
            std::cout << "3 - DES-EEE2" << std::endl;
            std::cout << "4 - DES-EDE2" << std::endl;
            std::cin >> mode;
            switch (mode)
            {
                case 1:
                {
                    
                    BYTE* hEee3_c = eee3_cipher(hPlainText, newTextSize, 0xBEEFBEEFBEEFBEEF, 0xCAFECAFECAFECAFE, 0xDEADDEADDEADDEAD);
                    BYTE* hEee3_decipher = eee3_decipher(hEee3_c, newTextSize, 0xBEEFBEEFBEEFBEEF, 0xCAFECAFECAFECAFE, 0xDEADDEADDEADDEAD);
                    std::string decipher_eee3 = memToStr(hEee3_decipher, newTextSize);
                    std::cout << std::endl << "          =====DES-EEE3 DECIPHERED===== " << std::endl;
                    std::cout << decipher_eee3 << std::endl;
                    break;
                }
                case 2:
                {
                    BYTE* hEde3_c = ede3_cipher(hPlainText, newTextSize, 0xBEEFBEEFBEEFBEEF, 0xCAFECAFECAFECAFE, 0xDEADDEADDEADDEAD);
                    BYTE* hEde3_decipher = ede3_decipher(hEde3_c, newTextSize, 0xBEEFBEEFBEEFBEEF, 0xCAFECAFECAFECAFE, 0xDEADDEADDEADDEAD);
                    std::string decipher_ede3 = memToStr(hEde3_decipher, newTextSize);
                    std::cout << std::endl << "          =====DES-EDE3 DECIPHERED===== " << std::endl;
                    std::cout << decipher_ede3 << std::endl;
                    break;
                }
                case 3:
                {
                    BYTE* hEee2_c = eee2_cipher(hPlainText, newTextSize, 0xBEEFBEEFBEEFBEEF, 0xCAFECAFECAFECAFE);
                    BYTE* hEee2_decipher = eee2_decipher(hEee2_c, newTextSize, 0xBEEFBEEFBEEFBEEF, 0xCAFECAFECAFECAFE);
                    std::string decipher_eee2 = memToStr(hEee2_decipher, newTextSize);
                    std::cout << std::endl << "          =====DES-EEE2 DECIPHERED===== " << std::endl;
                    std::cout << decipher_eee2 << std::endl;
                    break;
                }
                case 4:
                {
                    BYTE* hEde2_c = ede2_cipher(hPlainText, newTextSize, 0xBEEFBEEFBEEFBEEF, 0xCAFECAFECAFECAFE);
                    BYTE* hEde2_decipher = ede2_decipher(hEde2_c, newTextSize, 0xBEEFBEEFBEEFBEEF, 0xCAFECAFECAFECAFE);
                    std::string decipher_ede2 = memToStr(hEde2_decipher, newTextSize);
                    std::cout << std::endl << "          =====DES-EDE2 DECIPHERED===== " << std::endl;
                    std::cout << decipher_ede2 << std::endl;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            srand(time(NULL));
            int init_vector = rand();
            BYTE* hCbc_c = cbc_cipher(hPlainText, newTextSize, 0xBEEFBEEFBEEFBEEF, init_vector);
          //  BYTE* hCbc_decipher = cbc_decipher(hCbc_c, newTextSize, 0xBEEFBEEFBEEFBEEF, 0xCAFECAFECAFECAFE);
        //    std::string decipher_cbc = memToStr(hCbc_decipher, newTextSize);
            std::cout << std::endl << "          =====DES-CBC DECIPHERED===== " << std::endl;
         //   std::cout << decipher_cbc << std::endl;
            break;
        }
        case 0:
        {
            return 0;
        }    
        break;
    }
    return 0;
}


