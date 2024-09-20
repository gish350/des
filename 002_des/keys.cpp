#include <windows.h>
#include <winDNS.h>

// Коррекция ключа: требуется, чтобы сумма битов каждого байта ключа, 
// включая контрольный, была нечетной (нечетный паритетный бит).
void key_correction(LPVOID key)
{
	BYTE* base = (BYTE*)key;

	while ((BYTE*)key - (BYTE*)base != 7)
	{
		int _0 = (*(BYTE*)key & 0x80) >> 7; // 1000 0000
		int _1 = (*(BYTE*)key & 0x40) >> 6; // 0100 0000
		int _2 = (*(BYTE*)key & 0x20) >> 5; // 0010 0000
		int _3 = (*(BYTE*)key & 0x10) >> 4; // 0001 0000
		int _4 = (*(BYTE*)key & 0x8) >> 3;  // 0000 1000
		int _5 = (*(BYTE*)key & 0x4) >> 2;  // 0000 0100
		int _6 = (*(BYTE*)key & 0x2) >> 1;  // 0000 0010
		//7-ой бит - контрольный

		*(BYTE*)key = *(BYTE*)key | 0x1; // контрольный бит - всегда 1

		if (!((_0 + _1 + _2 + _3 + _4 + _5 + _6 + 1) % 2)) // если сумма битов четная:
		{
			*(BYTE*)key = *(BYTE*)key ^ 0x80; // меняем первый бит на противоположный
		}
		key = (BYTE*)key + 1; // указатель на i-ый байт ключа
	}

	key = (BYTE*)key - 8; // возврат указателя в начало
}

QWORD get_bit(QWORD bit, int sh)
{
	int rsh = 64 - sh - 1;
	return bit << rsh;
}

QWORD make_pc1(QWORD* hKey)
{
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

	pc1_key = pc1_key | ((*hKey & 0x2) << 28 - 1);						// 63
	pc1_key = pc1_key | ((*hKey & 0x200) << 29 - 9);						// 55
	pc1_key = pc1_key | ((*hKey & 0x20000) << 30 - 17);					// 47
	pc1_key = pc1_key | ((*hKey & 0x2000000) << 31 - 25);				// 39
	pc1_key = pc1_key | ((*hKey & 0x200000000) >> 33 - 32);				// 31
	pc1_key = pc1_key | ((*hKey & 0x20000000000) >> 41 - 33);			// 23
	pc1_key = pc1_key | ((*hKey & 0x2000000000000) >> 49 - 34);			// 15

	pc1_key = pc1_key | ((*hKey & 0x200000000000000) >> 57 - 35);		// 7
	pc1_key = pc1_key | ((*hKey & 0x4) << 36 - 2);						// 62
	pc1_key = pc1_key | ((*hKey & 0x400) << 37 - 10);					// 54
	pc1_key = pc1_key | ((*hKey & 0x40000) << 38 - 18);					// 46
	pc1_key = pc1_key | ((*hKey & 0x4000000) << 39 - 26);				// 38
	pc1_key = pc1_key | ((*hKey & 0x400000000) << 40 - 34);			// 30
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
	pc1_key = pc1_key | ((*hKey & 0x100000000000) << 53 - 44);			// 20
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

	DWORD _l = DWORD((*hPc1 << 28) >> 32);
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
void make_pc2(DWORD h, DWORD l, int k)
{
	// объединяем h и l
	QWORD hlUnion = 0;
	hlUnion = h;
	hlUnion = hlUnion << 32;
	QWORD l_tmp = 0;
	l_tmp = l;
	l_tmp = l_tmp << 4;
	hlUnion = hlUnion | l_tmp;

	QWORD tmpBuffer = 0;
	tmpBuffer = tmpBuffer | (hlUnion & 0x4000000000000) >> 50;						 // 14
	tmpBuffer = tmpBuffer | (hlUnion & 0x800000000000) >> 47 - 1;					 // 17
	tmpBuffer = tmpBuffer | (hlUnion & 0x20000000000000) >> 53 - 2;					 // 11
	tmpBuffer = tmpBuffer | (hlUnion & 0x10000000000) >> 40 - 3;                     // 24
	tmpBuffer = tmpBuffer | (hlUnion & 0x8000000000000000) >> 63 - 4;                // 1
	tmpBuffer = tmpBuffer | (hlUnion & 0x800000000000000) >> 59 - 5;                 // 5

	tmpBuffer = tmpBuffer | (hlUnion & 0x2000000000000000) >> 61 - 6;                // 3
	tmpBuffer = tmpBuffer | (hlUnion & 0x1000000000) >> 36 - 7;                      // 28
	tmpBuffer = tmpBuffer | (hlUnion & 0x2000000000000) >> 49 - 8;                   // 15
	tmpBuffer = tmpBuffer | (hlUnion & 0x400000000000000) >> 58 - 9;                 // 6
	tmpBuffer = tmpBuffer | (hlUnion & 0x80000000000) >> 43 - 10;                    // 21
	tmpBuffer = tmpBuffer | (hlUnion & 0x40000000000000) >> 54 - 11;                 // 10

	tmpBuffer = tmpBuffer | (hlUnion & 0x20000000000) >> 41 - 12;                    // 23
	tmpBuffer = tmpBuffer | (hlUnion & 0x200000000000) >> 45 - 13;                   // 19
	tmpBuffer = tmpBuffer | (hlUnion & 0x10000000000000) >> 52 - 14;                 // 12
	tmpBuffer = tmpBuffer | (hlUnion & 0x1000000000000000) >> 60 - 15;               // 4
	tmpBuffer = tmpBuffer | (hlUnion & 0x4000000000) >> 38 - 16;                     // 26
	tmpBuffer = tmpBuffer | (hlUnion & 0x100000000000000) >> 56 - 17;                // 8

	tmpBuffer = tmpBuffer | (hlUnion & 0x1000000000000) >> 48 - 18;                  // 16
	tmpBuffer = tmpBuffer | (hlUnion & 0x200000000000000) >> 57 - 19;                // 7
	tmpBuffer = tmpBuffer | (hlUnion & 0x2000000000) >> 37 - 20;                     // 27
	tmpBuffer = tmpBuffer | (hlUnion & 0x100000000000) >> 44 - 21;                   // 20
	tmpBuffer = tmpBuffer | (hlUnion & 0x8000000000000) >> 51 - 22;                  // 13
	tmpBuffer = tmpBuffer | (hlUnion & 0x4000000000000000) >> 62 - 23;               // 2

	tmpBuffer = tmpBuffer | (hlUnion & 0x800000) << 24 - 23;					     // 41
	tmpBuffer = tmpBuffer | (hlUnion & 0x1000) << 25 - 12;						     // 52
	tmpBuffer = tmpBuffer | (hlUnion & 0x200000000) >> 33 - 26;                      // 31
	tmpBuffer = tmpBuffer | (hlUnion & 0x8000000) >> 27 - 27;                        // 37
	tmpBuffer = tmpBuffer | (hlUnion & 0x20000) << 28 - 17;						     // 47
	tmpBuffer = tmpBuffer | (hlUnion & 0x200) << 29 - 9;						     // 55

	tmpBuffer = tmpBuffer | (hlUnion & 0x400000000) >> 34 - 30;                      // 30
	tmpBuffer = tmpBuffer | (hlUnion & 0x1000000) << 31 - 24;                        // 40
	tmpBuffer = tmpBuffer | (hlUnion & 0x2000) << 32 - 13;							 // 51
	tmpBuffer = tmpBuffer | (hlUnion & 0x80000) << 33 - 19;						     // 45
	tmpBuffer = tmpBuffer | (hlUnion & 0x80000000) << 34 - 31;                       // 33
	tmpBuffer = tmpBuffer | (hlUnion & 0x10000) << 35 - 16;						     // 48

	tmpBuffer = tmpBuffer | (hlUnion & 0x100000) << 36 - 20;						  // 44
	tmpBuffer = tmpBuffer | (hlUnion & 0x8000) << 37 - 15;							  // 49
	tmpBuffer = tmpBuffer | (hlUnion & 0x2000000) << 38 - 25;					      // 39
	tmpBuffer = tmpBuffer | (hlUnion & 0x100) << 39 - 8;							  // 56
	tmpBuffer = tmpBuffer | (hlUnion & 0x40000000) << 40 - 30;					      // 34
	tmpBuffer = tmpBuffer | (hlUnion & 0x800) << 41 - 11;							  // 53

	tmpBuffer = tmpBuffer | (hlUnion & 0x40000) << 42 - 18;							  // 46
	tmpBuffer = tmpBuffer | (hlUnion & 0x400000) << 43 - 22;						  // 42
	tmpBuffer = tmpBuffer | (hlUnion & 0x4000) << 44 - 14;							  // 50
	tmpBuffer = tmpBuffer | (hlUnion & 0x10000000) << 45 - 28;						  // 36
	tmpBuffer = tmpBuffer | (hlUnion & 0x800000000) << 46 - 35;						  // 29
	tmpBuffer = tmpBuffer | (hlUnion & 0x100000000) << 47 - 32;                       // 32

	memmove(k1_buffer + k, (BYTE*)&tmpBuffer, 6);






}


void make_k1(QWORD key)
{
	// Выработка ключевых элементов из ключа K начинается со входной выборки-перестановки битов PC1,
	// которая отбирает 56 из 64 битов ключа и располагает их в другом порядке.
	// В таблице указывается новое положение соответствующего бита.
	QWORD pc1 = make_pc1(&key);
	DWORD h = 0, l = 0; // 28 битные буферы, последние 32-28=4 бита не используем
	//Результат выборки-перестановки K* разделяется на две 28-битовые половинки: старшую H1 и младшую L1
	split_pc1(&pc1, h, l);


	// 48 * 16 / 8 = 96 байт - суммарный размер блоков k1
	k1_buffer = (BYTE*)GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, 96);

	int i = 0;
	int k = 0;
	//16 раз выполняется процедура.
	while (i < 16)
	{	
		// В зависимости от номера итерации обе половинки циклически сдвигаются на 1 или 2 бита влево.
		make_shift(&h, &l, i);
		// После сдвига половинки объединяются и из них с помощью выборки-перестановки PC2 отбираются 48 битов, 
		// которые и формируют очередной ключевой элемент.
		make_pc2(h, l, k);
		k += 6; // 6 байт (48 бит) размер одного k1 элемента
		i++;
	}
}