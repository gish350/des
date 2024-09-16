#include <windows.h>
#include <winDNS.h>


QWORD get_bit(QWORD bit, int sh)
{
	int rsh = 64 - sh - 1;
	return bit << rsh;
}

// неправильно для 1 бита?
QWORD pc1(QWORD* hKey)
{
	QWORD pc1_key = 0;
	pc1_key = pc1_key | ((*hKey & 0x40) << 57);						// 57-й бит
	pc1_key = pc1_key | ((*hKey & 0x4000) << 49 - 1);				// 49
	pc1_key = pc1_key | ((*hKey & 0x400000) << 41 - 2);				// 41
	pc1_key = pc1_key | ((*hKey & 0x40000000) << 33 - 3);			// 33
	pc1_key = pc1_key | ((*hKey & 0x4000000000) << 25 - 4);			// 25
	pc1_key = pc1_key | ((*hKey & 0x400000000000) << 17 - 5);		// 17
	pc1_key = pc1_key | ((*hKey & 0x40000000000000) << 9 - 6);		// 9

	pc1_key = pc1_key | ((*hKey & 0x4000000000000000) >> 6 );		// 1
	pc1_key = pc1_key | ((*hKey & 0x20) << 58 - 8);					// 58
	pc1_key = pc1_key | ((*hKey & 0x2000) << 50 - 9);				// 50
	pc1_key = pc1_key | ((*hKey & 0x200000) << 42 - 10);			// 42
	pc1_key = pc1_key | ((*hKey & 0x20000000) << 34 - 11);			// 34
	pc1_key = pc1_key | ((*hKey & 0x2000000000) << 26 - 12);		// 26
	pc1_key = pc1_key | ((*hKey & 0x200000000000) << 18 - 13);		// 18

	pc1_key = pc1_key | ((*hKey & 0x20000000000000) >> 4);			// 10
	pc1_key = pc1_key | ((*hKey & 0x2000000000000000) >> 13);		// 2
	pc1_key = pc1_key | ((*hKey & 0x10) << 59 - 16);				// 59
	pc1_key = pc1_key | ((*hKey & 0x1000) << 51 - 17);				// 51
	pc1_key = pc1_key | ((*hKey & 0x100000) << 43 - 18);			// 43
	pc1_key = pc1_key | ((*hKey & 0x10000000) << 35 - 19);			// 35
	pc1_key = pc1_key | ((*hKey & 0x1000000000) << 27 - 20);		// 27

	pc1_key = pc1_key | ((*hKey & 0x100000000000) >> 2);			// 19
	pc1_key = pc1_key | ((*hKey & 0x10000000000000) >> 11);			// 11
	pc1_key = pc1_key | ((*hKey & 0x1000000000000000) >> 20);		// 3
	pc1_key = pc1_key | ((*hKey & 0x8) << 60 - 24);					// 60
	pc1_key = pc1_key | ((*hKey & 0x800) << 52 - 25);				// 52
	pc1_key = pc1_key | ((*hKey & 0x80000) << 44 -26);				// 44
	pc1_key = pc1_key | ((*hKey & 0x8000000) << 36 - 27);			// 36

	pc1_key = pc1_key | ((*hKey & 0x1) << 63 - 28);					// 63
	pc1_key = pc1_key | ((*hKey & 0x100) << 55 - 29);				// 55
	pc1_key = pc1_key | ((*hKey & 0x10000) << 47 - 30);				// 47
	pc1_key = pc1_key | ((*hKey & 0x1000000) << 39 - 31);			// 39
	pc1_key = pc1_key | ((*hKey & 0x100000000) >> 1);				// 31
	pc1_key = pc1_key | ((*hKey & 0x10000000000) >> 10);			// 23
	pc1_key = pc1_key | ((*hKey & 0x1000000000000) >> 19);			// 15

	pc1_key = pc1_key | ((*hKey & 0x100000000000000) >> 28);		// 7
	pc1_key = pc1_key | ((*hKey & 0x2) << 62 - 36);					// 62
	pc1_key = pc1_key | ((*hKey & 0x200) << 54 - 37);				// 54
	pc1_key = pc1_key | ((*hKey & 0x20000) << 46 - 38);				// 46
	pc1_key = pc1_key | ((*hKey & 0x2000000) >> 1);					// 38
	pc1_key = pc1_key | ((*hKey & 0x200000000) >> 10);				// 30
	pc1_key = pc1_key | ((*hKey & 0x20000000000) >> 19);			// 22

	pc1_key = pc1_key | ((*hKey & 0x2000000000000) >> 28);			// 14
	pc1_key = pc1_key | ((*hKey & 0x200000000000000) >> 37);		// 6
	pc1_key = pc1_key | ((*hKey & 0x4) << 61 - 44);					// 61
	pc1_key = pc1_key | ((*hKey & 0x400) << 53 - 45);				// 53
	pc1_key = pc1_key | ((*hKey & 0x40000) >> 1);					// 45
	pc1_key = pc1_key | ((*hKey & 0x4000000) >> 10);				// 37
	pc1_key = pc1_key | ((*hKey & 0x400000000) >> 19);				// 29

	pc1_key = pc1_key | ((*hKey & 0x40000000000) >> 28);			// 21
	pc1_key = pc1_key | ((*hKey & 0x4000000000000) >> 37);			// 13
	pc1_key = pc1_key | ((*hKey & 0x400000000000000) >> 46);		// 5
	pc1_key = pc1_key | ((*hKey & 0x800000000) >> 24);				// 28
	pc1_key = pc1_key | ((*hKey & 0x80000000000) >> 33);			// 20
	pc1_key = pc1_key | ((*hKey & 0x8000000000000) >> 42);			// 12
	pc1_key = pc1_key | ((*hKey & 0x800000000000000) >> 51);		// 4	
	return pc1_key;
}

void split_pc1(QWORD* hPc1, DWORD& hH, DWORD& hL)
{

	// Преобразуем 32-битный h-буфер; отбрасываем последние 32 + 4 бита
	DWORD _h = *hPc1 >> 32;
	_h = _h & 0xFFFFFFF0;
	hH = _h;

	// Преобразуем 32-битный l-буфер; отбрасываем первые 28 бит,
	// отбрасываем последние (64-56) 8 бит
	
	DWORD _l = DWORD((*hPc1  << 28) >> 32);
	hL = _l;
}
void make_shift(DWORD* hH, DWORD* hL, int i)
{
	if (i == 0 || i == 1 || i == 8 || i == 15)
	{
		*hH = *hH << 1;
	}
	else
	{
		*hH = *hH << 2;
	}
}
BYTE* k1_buffer;
void make_pc2(DWORD h, DWORD l, int i)
{
	// объединяем h и l
	QWORD hlUnion = 0;
	hlUnion = h;
	hlUnion = hlUnion << 32;
	QWORD l_tmp = 0;
	l_tmp = l;
	l_tmp = l_tmp << 4;
	hlUnion = hlUnion | l_tmp;
	
	*(k1_buffer + i) = hlUnion & 0x2000000000000;							// 14
	*(k1_buffer + i) = *(k1_buffer + i) | hlUnion & 0x400000000000;			// 17
	*(k1_buffer + i) = *(k1_buffer + i) | hlUnion & 0x10000000000000;		// 11
	*(k1_buffer + i) = *(k1_buffer + i) | hlUnion & 0x8000000000;			// 24	
	*(k1_buffer + i) = *(k1_buffer + i) | hlUnion & 0x4000000000000000;		// 1
	*(k1_buffer + i) = *(k1_buffer + i) | hlUnion & 0x400000000000000;		// 5



}


void make_k1(QWORD pc1)
{
	DWORD h = 0, l = 0; // 28 битные буферы, последние 32-28=4 бита не используем
	split_pc1(&pc1, h, l);


	// 48 * 16 / 8 = 96 байт - суммарный размер блоков k1
	k1_buffer = (BYTE*)GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, 96);

	int i = 0;
	while (i < 16)
	{
		make_shift(&h, &l, i);
		make_pc2(h, l, i);
		i++;
	}

	
	
}