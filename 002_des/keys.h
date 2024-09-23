#pragma once
#include <windows.h>
#include <winDNS.h>


extern BYTE* k_keys_buffer;

void make_k_keys(QWORD pc1);
QWORD make_pc1(QWORD* key);
void key_correction(LPVOID key);

