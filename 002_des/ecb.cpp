#include <windows.h>
#include <winDNS.h>


void pc1(QWORD* key)
{
	QWORD pc1_key = 0;

	*(&pc1_key) = *(&pc1_key) | (*key & 0x40); // 57
	*(&pc1_key) = *(&pc1_key) | (*key & 0x4000); // 49
	*(&pc1_key) = *(&pc1_key) | (*key & 0x400000); // 41
}