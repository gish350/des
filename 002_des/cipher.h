#pragma once
#include <windows.h>
#include <winDNS.h>
#include "keys.h"

BYTE* ecb_cipher(BYTE* plain_text, int text_size, QWORD key);
BYTE* ecb_decipher(BYTE* cipher_text, int text_size, QWORD key);
BYTE* eee3_cipher(BYTE* plain_text, int text_size, QWORD key1, QWORD key2, QWORD key3);
BYTE* eee3_decipher(BYTE* cipher_text, int text_size, QWORD key1, QWORD key2, QWORD key3);
BYTE* eee2_cipher(BYTE* plain_text, int text_size, QWORD key1, QWORD key2);
BYTE* eee2_decipher(BYTE* cipher_text, int text_size, QWORD key1, QWORD key2);
BYTE* ede3_cipher(BYTE* plain_text, int text_size, QWORD key1, QWORD key2, QWORD key3);
BYTE* ede3_decipher(BYTE* cipher_text, int text_size, QWORD key1, QWORD key2, QWORD key3);
BYTE* ede2_cipher(BYTE* cipher_text, int text_size, QWORD key1, QWORD key2);
BYTE* ede2_decipher(BYTE* cipher_text, int text_size, QWORD key1, QWORD key2);


