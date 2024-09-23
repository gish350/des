#pragma once
#include <windows.h>
#include <winDNS.h>
#include "keys.h"
BYTE* ecb_cipher(BYTE* plain_text, int text_size, QWORD key);


