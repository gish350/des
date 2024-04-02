#include <windows.h>
#include <winDNS.h>


QWORD get_bit(QWORD bit, int sh)
{
	int rsh = 64 - sh - 1;
	return bit << rsh;
}

QWORD pc1(QWORD* key)
{
	QWORD pc1_key = 0;
	pc1_key = pc1_key | ((*key & 0x40) << 57);						// 57-� ���
	pc1_key = pc1_key | ((*key & 0x4000) << 49 - 1);				// 49
	pc1_key = pc1_key | ((*key & 0x400000) << 41 - 2);				// 41
	pc1_key = pc1_key | ((*key & 0x40000000) << 33 - 3);			// 33
	pc1_key = pc1_key | ((*key & 0x4000000000) << 25 - 4);			// 25
	pc1_key = pc1_key | ((*key & 0x400000000000) << 17 - 5);		// 17
	pc1_key = pc1_key | ((*key & 0x40000000000000) << 9 - 6);		// 9

	pc1_key = pc1_key | ((*key & 0x4000000000000000) >> 6 );		// 1
	pc1_key = pc1_key | ((*key & 0x20) << 58 - 8);					// 58
	pc1_key = pc1_key | ((*key & 0x2000) << 50 - 9);				// 50
	pc1_key = pc1_key | ((*key & 0x200000) << 42 - 10);				// 42
	pc1_key = pc1_key | ((*key & 0x20000000) << 34 - 11);			// 34
	pc1_key = pc1_key | ((*key & 0x2000000000) << 26 - 12);			// 26
	pc1_key = pc1_key | ((*key & 0x200000000000) << 18 - 13);		// 18

	pc1_key = pc1_key | ((*key & 0x20000000000000) >> 4);			// 10
	pc1_key = pc1_key | ((*key & 0x2000000000000000) >> 13);		// 2
	pc1_key = pc1_key | ((*key & 0x10) << 59 - 16);					// 59
	pc1_key = pc1_key | ((*key & 0x1000) << 51 - 17);				// 51
	pc1_key = pc1_key | ((*key & 0x100000) << 43 - 18);				// 43
	pc1_key = pc1_key | ((*key & 0x10000000) << 35 - 19);			// 35
	pc1_key = pc1_key | ((*key & 0x1000000000) << 27 - 20);			// 27

	pc1_key = pc1_key | ((*key & 0x100000000000) >> 2);				// 19
	pc1_key = pc1_key | ((*key & 0x10000000000000) >> 11);			// 11
	pc1_key = pc1_key | ((*key & 0x1000000000000000) >> 20);		// 3
	pc1_key = pc1_key | ((*key & 0x8) << 60 - 24);					// 60
	pc1_key = pc1_key | ((*key & 0x800) << 52 - 25);				// 52
	pc1_key = pc1_key | ((*key & 0x80000) << 44 -26);				// 44
	pc1_key = pc1_key | ((*key & 0x8000000) << 36 - 27);			// 36

	pc1_key = pc1_key | ((*key & 0x1) << 63 - 28);					// 63
	pc1_key = pc1_key | ((*key & 0x100) << 55 - 29);				// 55
	pc1_key = pc1_key | ((*key & 0x10000) << 47 - 30);				// 47
	pc1_key = pc1_key | ((*key & 0x1000000) << 39 - 31);			// 39
	pc1_key = pc1_key | ((*key & 0x100000000) >> 1);				// 31
	pc1_key = pc1_key | ((*key & 0x10000000000) >> 10);				// 23
	pc1_key = pc1_key | ((*key & 0x1000000000000) >> 19);			// 15

	pc1_key = pc1_key | ((*key & 0x100000000000000) >> 28);			// 7
	pc1_key = pc1_key | ((*key & 0x2) << 62 - 36);					// 62
	pc1_key = pc1_key | ((*key & 0x200) << 54 - 37);				// 54
	pc1_key = pc1_key | ((*key & 0x20000) << 46 - 38);				// 46
	pc1_key = pc1_key | ((*key & 0x2000000) >> 1);					// 38
	pc1_key = pc1_key | ((*key & 0x200000000) >> 10);				// 30
	pc1_key = pc1_key | ((*key & 0x20000000000) >> 19);				// 22

	pc1_key = pc1_key | ((*key & 0x2000000000000) >> 28);			// 14
	pc1_key = pc1_key | ((*key & 0x200000000000000) >> 37);			// 6
	pc1_key = pc1_key | ((*key & 0x4) << 61 - 44);					// 61
	pc1_key = pc1_key | ((*key & 0x400) << 53 - 45);				// 53
	pc1_key = pc1_key | ((*key & 0x40000) >> 1);					// 45
	pc1_key = pc1_key | ((*key & 0x4000000) >> 10);					// 37
	pc1_key = pc1_key | ((*key & 0x400000000) >> 19);				// 29

	pc1_key = pc1_key | ((*key & 0x40000000000) >> 28);				// 21
	pc1_key = pc1_key | ((*key & 0x4000000000000) >> 37);			// 13
	pc1_key = pc1_key | ((*key & 0x400000000000000) >> 46);			// 5
	pc1_key = pc1_key | ((*key & 0x800000000) >> 24);				// 28
	pc1_key = pc1_key | ((*key & 0x80000000000) >> 33);				// 20
	pc1_key = pc1_key | ((*key & 0x8000000000000) >> 42);			// 12
	pc1_key = pc1_key | ((*key & 0x800000000000000) >> 51);			// 4	
	return pc1_key;
}

void cyclic_shift(LPVOID h, LPVOID l, int iteration)
{

}