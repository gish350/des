#include <windows.h>
#include <winDNS.h>


QWORD get_bit(QWORD bit, int sh)
{
	int rsh = 64 - sh - 1;
	return bit << rsh;
}

void pc1(QWORD* key)
{
	QWORD pc1_key = 0;

	pc1_key = pc1_key | (*key & 0x40);					// 57-й бит
	pc1_key = pc1_key | (*key & 0x4000);				// 49
	pc1_key = pc1_key | (*key & 0x400000);				// 41
	pc1_key = pc1_key | (*key & 0x40000000);			// 33
	pc1_key = pc1_key | (*key & 0x4000000000);			// 25
	pc1_key = pc1_key | (*key & 0x400000000000);		// 17
	pc1_key = pc1_key | (*key & 0x40000000000000);		// 9

	pc1_key = pc1_key | (*key & 0x4000000000000000);	// 1
	pc1_key = pc1_key | (*key & 0x20);					// 58
	pc1_key = pc1_key | (*key & 0x2000);				// 50
	pc1_key = pc1_key | (*key & 0x200000);				// 42
	pc1_key = pc1_key | (*key & 0x20000000);			// 34
	pc1_key = pc1_key | (*key & 0x2000000000);			// 26
	pc1_key = pc1_key | (*key & 0x200000000000);		// 18

	pc1_key = pc1_key | (*key & 0x20000000000000);		// 10
	pc1_key = pc1_key | (*key & 0x2000000000000000);	// 2
	pc1_key = pc1_key | (*key & 0x10);					// 59
	pc1_key = pc1_key | (*key & 0x1000);				// 51
	pc1_key = pc1_key | (*key & 0x100000);				// 43
	pc1_key = pc1_key | (*key & 0x10000000);			// 35
	pc1_key = pc1_key | (*key & 0x1000000000);			// 27

	pc1_key = pc1_key | (*key & 0x100000000000);		// 19
	pc1_key = pc1_key | (*key & 0x10000000000000);		// 11
	pc1_key = pc1_key | (*key & 0x1000000000000000);	// 3
	pc1_key = pc1_key | (*key & 0x8);					// 60
	pc1_key = pc1_key | (*key & 0x800);					// 52
	pc1_key = pc1_key | (*key & 0x80000);				// 44
	pc1_key = pc1_key | (*key & 0x8000000);				// 36

	pc1_key = pc1_key | (*key & 0x1);					// 63
	pc1_key = pc1_key | (*key & 0x100);					// 55
	pc1_key = pc1_key | (*key & 0x10000);				// 47
	pc1_key = pc1_key | (*key & 0x1000000);				// 39
	pc1_key = pc1_key | (*key & 0x100000000);			// 31
	pc1_key = pc1_key | (*key & 0x10000000000);			// 23
	pc1_key = pc1_key | (*key & 0x1000000000000);		// 15

	pc1_key = pc1_key | (*key & 0x1000000000000);		// 7
	pc1_key = pc1_key | (*key & 0x2);					// 62
	pc1_key = pc1_key | (*key & 0x200);					// 54
	pc1_key = pc1_key | (*key & 0x200);					// 46
	pc1_key = pc1_key | (*key & 0x20000);				// 38
	pc1_key = pc1_key | (*key & 0x2000000);				// 30
	pc1_key = pc1_key | (*key & 0x200000000);			// 22

	pc1_key = pc1_key | (*key & 0x20000000000);			// 14
	pc1_key = pc1_key | (*key & 0x2000000000000);		// 6
	pc1_key = pc1_key | (*key & 0x4);					// 61
	pc1_key = pc1_key | (*key & 0x400);					// 53
	pc1_key = pc1_key | (*key & 0x40000);				// 45
	pc1_key = pc1_key | (*key & 0x4000000);				// 37
	pc1_key = pc1_key | (*key & 0x400000000);			// 29

	pc1_key = pc1_key | (*key & 0x40000000000);			// 21
	pc1_key = pc1_key | (*key & 0x4000000000000);		// 13
	pc1_key = pc1_key | (*key & 0x400000000000000);		// 5
	pc1_key = pc1_key | (*key & 0x800000000);			// 28
	pc1_key = pc1_key | (*key & 0x80000000000);			// 20
	pc1_key = pc1_key | (*key & 0x8000000000000);		// 12
	pc1_key = pc1_key | (*key & 0x800000000000000);		// 4


	
	
}