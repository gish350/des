#pragma once
#include <windows.h>
#include <winDNS.h>
#include "keys.h"
BYTE* ecb_cipher(BYTE* plain_text, int text_size, QWORD key);
BYTE* ecb_decipher(BYTE* cipher_text, int text_size, QWORD key);


