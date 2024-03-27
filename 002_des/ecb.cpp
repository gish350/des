#include <windows.h>
#include <winDNS.h>

void pc1(LPVOID key)
{
	BYTE* pKey = (BYTE*)key;
	QWORD pc1_key = 0;

	*(BYTE*)pc1_key = *(pKey + 7) && 0x1;
}