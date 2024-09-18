#include <windows.h>
#include <winDNS.h>


QWORD get_bit(QWORD bit, int sh)
{
	int rsh = 64 - sh - 1;
	return bit << rsh;
}

//todo: сдвиг на 1 меньше чем в таблице
QWORD pc1(QWORD* hKey)
{
	QWORD tmp_test = 0xFFFFFFFFFFFFFFFF;
	hKey = &tmp_test;

	QWORD pc1_key = 0;
	pc1_key = pc1_key | ((*hKey & 0x80) >> 7);						// 57-й бит (56)
	pc1_key = pc1_key | ((*hKey & 0x8000) >> 15 - 1);				// 49 (48)
	pc1_key = pc1_key | ((*hKey & 0x800000) >> 23 - 2);				// 41
	pc1_key = pc1_key | ((*hKey & 0x80000000) >> 31 - 3);			// 33
	pc1_key = pc1_key | ((*hKey & 0x8000000000) >> 39 - 4);			// 25
	pc1_key = pc1_key | ((*hKey & 0x800000000000) >> 47 - 5);		// 17
	pc1_key = pc1_key | ((*hKey & 0x80000000000000) >> 55 - 6);		// 9

	pc1_key = pc1_key | ((*hKey & 0x8000000000000000) >> 63 - 7);	// 1
	pc1_key = pc1_key | ((*hKey & 0x40) << 2);						// 58
	pc1_key = pc1_key | ((*hKey & 0x4000) >> 14 - 9);				// 50
	pc1_key = pc1_key | ((*hKey & 0x400000) >> 22 - 10);			// 42
	pc1_key = pc1_key | ((*hKey & 0x40000000) >> 30 - 11);			// 34
	pc1_key = pc1_key | ((*hKey & 0x4000000000) >> 38 - 12);		// 26
	pc1_key = pc1_key | ((*hKey & 0x400000000000) >> 46 - 13);		// 18

	pc1_key = pc1_key | ((*hKey & 0x40000000000000) >> 54 - 14);	// 10
	pc1_key = pc1_key | ((*hKey & 0x4000000000000000) >> 62 - 15);	// 2
	pc1_key = pc1_key | ((*hKey & 0x20) << 16 - 5);						// 59
	pc1_key = pc1_key | ((*hKey & 0x2000) << 17 - 13);					// 51
	pc1_key = pc1_key | ((*hKey & 0x200000) >> 21 - 18);			// 43
	pc1_key = pc1_key | ((*hKey & 0x20000000) >> 29 - 19);			// 35
	pc1_key = pc1_key | ((*hKey & 0x2000000000) >> 37 - 20);		// 27

	pc1_key = pc1_key | ((*hKey & 0x200000000000) >> 45 - 21);		// 19
	pc1_key = pc1_key | ((*hKey & 0x20000000000000) >> 53 - 22);	// 11
	pc1_key = pc1_key | ((*hKey & 0x2000000000000000) >> 61 - 23);	// 3
	pc1_key = pc1_key | ((*hKey & 0x10) << 20);						// 60
	pc1_key = pc1_key | ((*hKey & 0x1000) << 13);					// 52
	pc1_key = pc1_key | ((*hKey & 0x100000) << 6);					// 44
	pc1_key = pc1_key | ((*hKey & 0x10000000) >> 28 - 27);				// 36

	pc1_key = pc1_key | ((*hKey & 0x2) << 28 - 1 );						// 63
	pc1_key = pc1_key | ((*hKey & 0x200) <<29 -9);						// 55
	pc1_key = pc1_key | ((*hKey & 0x20000) << 30 -17);					// 47
	pc1_key = pc1_key | ((*hKey & 0x2000000) << 31 - 25);				// 39
	pc1_key = pc1_key | ((*hKey & 0x200000000) >> 33 - 32);				// 31
	pc1_key = pc1_key | ((*hKey & 0x20000000000) >> 41 - 33);			// 23
	pc1_key = pc1_key | ((*hKey & 0x2000000000000) >> 49 - 34);			// 15

	pc1_key = pc1_key | ((*hKey & 0x200000000000000) >> 57 - 35);		// 7
	pc1_key = pc1_key | ((*hKey & 0x4) << 36 - 2);						// 62
	pc1_key = pc1_key | ((*hKey & 0x400) << 37 - 10);					// 54
	pc1_key = pc1_key | ((*hKey & 0x40000) << 38 - 18);					// 46
	pc1_key = pc1_key | ((*hKey & 0x4000000) << 39 - 26);				// 38
	pc1_key = pc1_key | ((*hKey & 0x400000000) << 40 -  34);			// 30
	pc1_key = pc1_key | ((*hKey & 0x40000000000) >> 42 - 41);			// 22

	pc1_key = pc1_key | ((*hKey & 0x4000000000000) >> 50 - 42);			// 14
	pc1_key = pc1_key | ((*hKey & 0x400000000000000) >> 58 - 43);		// 6
	pc1_key = pc1_key | ((*hKey & 0x8) << 44 - 3);					// 61
	pc1_key = pc1_key | ((*hKey & 0x800) << 45 - 11);				// 53
	pc1_key = pc1_key | ((*hKey & 0x80000) << 46 - 19);					// 45
	pc1_key = pc1_key | ((*hKey & 0x8000000) << 47 - 27);				// 37
	pc1_key = pc1_key | ((*hKey & 0x800000000) << 48 - 35);				// 29

	pc1_key = pc1_key | ((*hKey & 0x80000000000) << 49 - 43);			// 21
	pc1_key = pc1_key | ((*hKey & 0x8000000000000) >> 51 - 50);			// 13
	pc1_key = pc1_key | ((*hKey & 0x800000000000000) >> 59 - 51);		// 5
	pc1_key = pc1_key | ((*hKey & 0x1000000000) << 52 - 36);				// 28
	pc1_key = pc1_key | ((*hKey & 0x100000000000) << 53- 44);			// 20
	pc1_key = pc1_key | ((*hKey & 0x10000000000000) << 54 - 52);			// 12
	pc1_key = pc1_key | ((*hKey & 0x1000000000000000) >> 60 - 55);		// 4	
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
	
	*(k1_buffer + i) = (hlUnion & 0x4000000000000) >> 50;							// 14 (13)
	*(k1_buffer + i) = *(k1_buffer + i) | (hlUnion & 0x800000000000) >> 47 - 1 ;			// 17
	*(k1_buffer + i) = *(k1_buffer + i) | (hlUnion & 0x20000000000000) >> 53 - 2;		// 11
	*(k1_buffer + i) = *(k1_buffer + i) | (hlUnion & 0x10000000000) >> 40 - 3;			// 24	
	*(k1_buffer + i) = *(k1_buffer + i) | (hlUnion & 0x8000000000000000) >> 63 - 4;		// 1
	*(k1_buffer + i) = *(k1_buffer + i) | (hlUnion & 0x800000000000000) >> 59 - 5;		// 5

	*(k1_buffer + i) = *(k1_buffer + i) | (hlUnion & 0x2000000000000000) >> 61;			//3
	*(k1_buffer + i) = *(k1_buffer + i) | (hlUnion & 0x1000000000) >> 36;			//28
	*(k1_buffer + i) = *(k1_buffer + i) | (hlUnion & 0x2000000000000) >> 49;			//15
	*(k1_buffer + i) = *(k1_buffer + i) | (hlUnion & 0x400000000000000) >> 58;			//6
																					



	



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