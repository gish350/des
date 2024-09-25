#include "cipher.h"
#include <iostream> // убрать



QWORD make_ip(QWORD* block_64)
{
	QWORD ip = 0;
	int ip_table[] = {
			58, 50, 42, 34, 26, 18, 10, 2,
			60, 52, 44, 36, 28, 20, 12, 4,
			62, 54, 46, 38, 30, 22, 14, 6,
			64, 56, 48, 40, 32, 24, 16, 8,
			57, 49, 41, 33, 25, 17, 9, 1,
			59, 51, 43, 35, 27, 19, 11, 3,
			61, 53, 45, 37, 29, 21, 13, 5,
			63, 55, 47, 39, 31, 23, 15, 7
	};
	ip = make_bit_permutation(block_64, ip_table, 64);
	return ip;
}

QWORD make_ip1(QWORD* block_64)
{
	QWORD ip1 = 0;
	int ip_table[] = {
		40, 8, 48, 16, 56, 24, 64, 32,
		39, 7, 47, 15, 55, 23, 63, 31,
		38, 6, 46, 14, 54, 22, 62, 30,
		37, 5, 45, 13, 53, 21, 61, 29,
		36, 4, 44, 12, 52, 20, 60, 28,
		35, 3, 43, 11, 51, 19, 59, 27,
		34, 2, 42, 10, 50, 18, 58, 26,
		33, 1, 41, 9, 49, 17, 57, 25
	};
	ip1 = make_bit_permutation(block_64, ip_table, 64);
	//ip1 = ip1 | ((*block_64 & 0x1000000) >> 24 - 0);						// 40
	//ip1 = ip1 | ((*block_64 & 0x100000000000000) >> 56 - 1);				// 8
	//ip1 = ip1 | ((*block_64 & 0x10000) >> 16 - 2);						 // 48
	//ip1 = ip1 | ((*block_64 & 0x1000000000000) >> 48 - 3);                 // 16
	//ip1 = ip1 | ((*block_64 & 0x100) >> 8 - 4);							 // 56
	//ip1 = ip1 | ((*block_64 & 0x10000000000) >> 40 - 5);                   // 24
	//ip1 = ip1 | ((*block_64 & 0x1) << 6 - 0);								 // 64
	//ip1 = ip1 | ((*block_64 & 0x100000000) >> 32 - 7);                     // 32

	//ip1 = ip1 | ((*block_64 & 0x2000000) >> 25 - 8);						 // 39
	//ip1 = ip1 | ((*block_64 & 0x200000000000000) >> 57 - 9);               // 7
	//ip1 = ip1 | ((*block_64 & 0x20000) >> 17 - 10);						 // 47
	//ip1 = ip1 | ((*block_64 & 0x2000000000000) >> 49 - 11);                // 15
	//ip1 = ip1 | ((*block_64 & 0x200) <<12 -9 );							 // 55
	//ip1 = ip1 | ((*block_64 & 0x20000000000) >> 41 - 13);                  // 23
	//ip1 = ip1 | ((*block_64 & 0x2) << 14 - 1);							 // 63
	//ip1 = ip1 | ((*block_64 & 0x200000000) >> 33 - 15);                    // 31

	//ip1 = ip1 | ((*block_64 & 0x4000000) >> 26 - 16);				         // 38
	//ip1 = ip1 | ((*block_64 & 0x400000000000000) >> 58 - 17);	           // 6
	//ip1 = ip1 | ((*block_64 & 0x40000) >> 18 - 18);				         // 46
	//ip1 = ip1 | ((*block_64 & 0x4000000000000) >> 50 - 19);                  // 14
	//ip1 = ip1 | ((*block_64 & 0x400) << 20 -10 );						     // 54
	//ip1 = ip1 | ((*block_64 & 0x40000000000) >> 42 - 21);                  // 22
	//ip1 = ip1 | ((*block_64 & 0x4) << 22 - 2);						     // 62
	//ip1 = ip1 | ((*block_64 & 0x400000000) >> 34 - 23);                    // 30

	//ip1 = ip1 | ((*block_64 & 0x8000000) >> 27 - 24);                      // 37
	//ip1 = ip1 | ((*block_64 & 0x800000000000000) >> 59 - 25);                 // 5
	//ip1 = ip1 | ((*block_64 & 0x80000) << 26 - 19);					     // 45
	//ip1 = ip1 | ((*block_64 & 0x8000000000000) >> 51 - 27);                   // 13
	//ip1 = ip1 | ((*block_64 & 0x800) << 28 - 11);							 // 53
	//ip1 = ip1 | ((*block_64 & 0x80000000000) >> 43 - 29);                  // 21
	//ip1 = ip1 | ((*block_64 & 0x8) << 30 - 3);							 // 61
	//ip1 = ip1 | ((*block_64 & 0x800000000) >> 35 - 31);                    // 29

	//ip1 = ip1 | ((*block_64 & 0x10000000) <<32 - 28);                     // 36
	//ip1 = ip1 | ((*block_64 & 0x1000000000000000) >> 60 - 33);             // 4
	//ip1 = ip1 | ((*block_64 & 0x100000) << 34 - 20);				         // 44
	//ip1 = ip1 | ((*block_64 & 0x10000000000000) >> 52 - 35);                 // 12
	//ip1 = ip1 | ((*block_64 & 0x1000) << 36 - 12);					     // 52
	//ip1 = ip1 | ((*block_64 & 0x100000000000) >> 44 - 37);                 // 20
	//ip1 = ip1 | ((*block_64 & 0x10) << 38 - 4);						     // 60
	//ip1 = ip1 | ((*block_64 & 0x1000000000) << 39 - 36);                   // 28

	//ip1 = ip1 | ((*block_64 & 0x20000000) << 40 - 29);                     // 35
	//ip1 = ip1 | ((*block_64 & 0x2000000000000000) >> 61 - 41);            // 3
	//ip1 = ip1 | ((*block_64 & 0x200000) <<42 -  21);					     // 43
	//ip1 = ip1 | ((*block_64 & 0x20000000000000) >> 53 - 43);             // 11
	//ip1 = ip1 | ((*block_64 & 0x2000) <<44 - 13);					   // 51
	//ip1 = ip1 | ((*block_64 & 0x200000000000) >> 45 - 45);                 // 19
	//ip1 = ip1 | ((*block_64 & 0x20) << 46 - 5);						     // 59
	//ip1 = ip1 | ((*block_64 & 0x2000000000) << 47 - 37);                   // 27

	//ip1 = ip1 | ((*block_64 & 0x40000000) << 48 - 30);                      // 34
	//ip1 = ip1 | ((*block_64 & 0x4000000000000000) >> 62 - 49);               // 2
	//ip1 = ip1 | ((*block_64 & 0x400000) << 50 - 22);				        // 42
	//ip1 = ip1 | ((*block_64 & 0x40000000000000) >> 54 - 51);                  // 10
	//ip1 = ip1 | ((*block_64 & 0x4000) << 52 - 14);					     // 50
	//ip1 = ip1 | ((*block_64 & 0x400000000000) << 53 - 46);                 // 18
	//ip1 = ip1 | ((*block_64 & 0x40) <<54 - 6);						     // 58
	//ip1 = ip1 | ((*block_64 & 0x4000000000) << 55 -38);                   // 26

	//ip1 = ip1 | ((*block_64 & 0x80000000) <<56 - 31);                     // 33
	//ip1 = ip1 | ((*block_64 & 0x8000000000000000) >> 63 - 57);               // 1
	//ip1 = ip1 | ((*block_64 & 0x800000) << 58 - 23);				         // 41
	//ip1 = ip1 | ((*block_64 & 0x80000000000000) << 59 - 55);                 // 9
	//ip1 = ip1 | ((*block_64 & 0x8000) << 60 - 15);						 // 49
	//ip1 = ip1 | ((*block_64 & 0x800000000000) <<  61 - 47);                 // 17
	//ip1 = ip1 | ((*block_64 & 0x80) << 62 - 7);							 // 57
	//ip1 = ip1 | ((*block_64 & 0x8000000000) << 63 - 39);                      // 25

	return ip1;
}

void split_ip(QWORD ip, DWORD* h, DWORD* l)
{
	// Преобразуем 32-битный h-буфер; отбрасываем последние 32 бита
	*h = ip >> 32;

	// Преобразуем 32-битный l-буфер; отбрасываем первые 32 бита
	*l = (ip << 32) >> 32;
}

void get_row_col(BYTE h, BYTE* out_row, BYTE* out_col)
{
	*out_row = 0;
	*out_col = 0;
	BYTE tmpRow = 0;
	tmpRow = (h & 0x20) >> 4;			// 0010 0000
	*out_row = (h & 0x2) >> 1;			// 0000 0010

	*out_row = *out_row | tmpRow;
	*out_col = (h & 0x1E) >> 1;			// 011110
}

QWORD make_e(DWORD l)
{
	QWORD e = 0;
	QWORD tmp_l = 0;
	tmp_l = (tmp_l | l) << 32;

	int e_block[] = {
		32,   1,   2,   3,   4,   5,
		4,    5,   6 ,  7,   8,   9,
		8,   9,   10,  11,  12,  13,
		12,  13,  14,  15,  16,  17,
		16,  17,  18,  19,  20,  21,
		20,  21,  22,  23,  24,  25,
		24,  25,  26,  27,  28,  29,
		28,  29,  30,  31,  32,  1
	};
	e = make_bit_permutation(&l, e_block, 48);

	//e = e | ((tmp_l & 0x40) >> 6 - 0);											  // 58

	//e = e | ((tmp_l & 0x100000000) >> 32 - 0);										 //32
	//e = e | ((tmp_l & 0x8000000000000000) >> 63 - 1);                               //1
	//e = e | ((tmp_l & 0x4000000000000000) >> 62 - 2);                               //2
	//e = e | ((tmp_l & 0x2000000000000000) >> 61 - 3);                               //3
	//e = e | ((tmp_l & 0x1000000000000000) >> 60 - 4);                               //4
	//e = e | ((tmp_l & 0x800000000000000) >> 59 - 5);                                //5
	//e = e | ((tmp_l & 0x1000000000000000) >> 60 - 6);                               //4
	//e = e | ((tmp_l & 0x800000000000000) >> 59 - 7);                                //5
	//e = e | ((tmp_l & 0x400000000000000) >> 58 - 8);                                //6
	//e = e | ((tmp_l & 0x200000000000000) >> 57 - 9);                                //7
	//e = e | ((tmp_l & 0x100000000000000) >> 56 - 10);                               //8
	//e = e | ((tmp_l & 0x80000000000000) >> 55 - 11);                                //9
	//e = e | ((tmp_l & 0x100000000000000) >> 56 - 12);                               //8
	//e = e | ((tmp_l & 0x80000000000000) >> 55 - 13);                                //9
	//e = e | ((tmp_l & 0x40000000000000) >> 54 - 14);                                //10
	//e = e | ((tmp_l & 0x20000000000000) >> 53 - 15);                                //11
	//e = e | ((tmp_l & 0x10000000000000) >> 52 - 16);                                //12
	//e = e | ((tmp_l & 0x8000000000000) >> 51 - 17);									//13
	//e = e | ((tmp_l & 0x10000000000000) >> 52 - 18);                                //12
	//e = e | ((tmp_l & 0x8000000000000) >> 51 - 19);									  //13
	//e = e | ((tmp_l & 0x4000000000000) >> 50 - 20);									 //14
	//e = e | ((tmp_l & 0x2000000000000) >> 49 - 21);									 //15
	//e = e | ((tmp_l & 0x1000000000000) >> 48 - 22);									  //16
	//e = e | ((tmp_l & 0x800000000000) >> 47 - 23);									  //17
	//e = e | ((tmp_l & 0x1000000000000) >> 48 - 24);									   //16
	//e = e | ((tmp_l & 0x800000000000) >> 47 - 25);								   //17
	//e = e | ((tmp_l & 0x400000000000) >> 46 - 26);                          //18
	//e = e | ((tmp_l & 0x200000000000) >> 45 - 27);                          //19
	//e = e | ((tmp_l & 0x100000000000) >> 44 - 28);                          //20
	//e = e | ((tmp_l & 0x80000000000) >> 43 - 29);                           //21
	//e = e | ((tmp_l & 0x100000000000) >> 44 - 30);                          //20
	//e = e | ((tmp_l & 0x80000000000) >> 43 - 31);                           //21
	//e = e | ((tmp_l & 0x40000000000) >> 42 - 32);                           //22
	//e = e | ((tmp_l & 0x20000000000) >> 41 - 33);                           //23
	//e = e | ((tmp_l & 0x10000000000) >> 40 - 34);                           //24
	//e = e | ((tmp_l & 0x8000000000) >> 39 - 35);                            //25
	//e = e | ((tmp_l & 0x10000000000) >> 40 - 36);                           //24
	//e = e | ((tmp_l & 0x8000000000) >> 39 - 37);                            //25
	//e = e | ((tmp_l & 0x4000000000) >> 38 - 38);                            //26
	//e = e | ((tmp_l & 0x2000000000) << 39 - 37);                            //27
	//e = e | ((tmp_l & 0x1000000000) << 40 - 36);                            //28
	//e = e | ((tmp_l & 0x800000000) << 41 - 35);                             //29
	//e = e | ((tmp_l & 0x1000000000) << 42 - 36);                            //28
	//e = e | ((tmp_l & 0x800000000) << 43 - 35);                             //29
	//e = e | ((tmp_l & 0x400000000) << 44 - 34);                             //30
	//e = e | ((tmp_l & 0x200000000) << 45 - 33);                             //31
	//e = e | ((tmp_l & 0x100000000) << 46 - 32);                             //32
	//e = e | ((tmp_l & 0x8000000000000000) >> 63 - 47);                              //1
	
	return e;
}

#pragma region MAKE Tn
BYTE make_t1(BYTE row, BYTE column)
{
	if (row == 0)
	{
		if (column == 0) return 14;
		if (column == 1) return 4;
		if (column == 2) return 13;
		if (column == 3) return 1;
		if (column == 4) return 2;
		if (column == 5) return 15;
		if (column == 6) return 11;
		if (column == 7) return 8;
		if (column == 8) return 3;
		if (column == 9) return 10;
		if (column == 10) return 6;
		if (column == 11) return 12;
		if (column == 12) return 5;
		if (column == 13) return 9;
		if (column == 14) return 0;
		if (column == 15) return 7;
	}
	if (row == 1)
	{
		if (column == 0) return 0;
		if (column == 1) return 15;
		if (column == 2) return 7;
		if (column == 3) return 4;
		if (column == 4) return 14;
		if (column == 5) return 2;
		if (column == 6) return 13;
		if (column == 7) return 1;
		if (column == 8) return 10;
		if (column == 9) return 6;
		if (column == 10) return 12;
		if (column == 11) return 11;
		if (column == 12) return 9;
		if (column == 13) return 5;
		if (column == 14) return 3;
		if (column == 15) return 8;
	}

	if (row == 2)
	{
		if (column == 0) return 4;
		if (column == 1) return 1;
		if (column == 2) return 14;
		if (column == 3) return 8;
		if (column == 4) return 13;
		if (column == 5) return 6;
		if (column == 6) return 2;
		if (column == 7) return 11;
		if (column == 8) return 15;
		if (column == 9) return 12;
		if (column == 10) return 9;
		if (column == 11) return 7;
		if (column == 12) return 3;
		if (column == 13) return 10;
		if (column == 14) return 5;
		if (column == 15) return 0;
	}
	if (row == 3)
	{
		if (column == 0) return 5;
		if (column == 1) return 12;
		if (column == 2) return 8;
		if (column == 3) return 2;
		if (column == 4) return 4;
		if (column == 5) return 9;
		if (column == 6) return 1;
		if (column == 7) return 7;
		if (column == 8) return 5;
		if (column == 9) return 11;
		if (column == 10) return 3;
		if (column == 11) return 14;
		if (column == 12) return 10;
		if (column == 13) return 0;
		if (column == 14) return 6;
		if (column == 15) return 13;
	}
}


BYTE make_t2(BYTE row, BYTE column)
{
	if (row == 0)
	{
		if (column == 0) return 15;
		if (column == 1) return 1;
		if (column == 2) return 8;
		if (column == 3) return 14;
		if (column == 4) return 6;
		if (column == 5) return 11;
		if (column == 6) return 3;
		if (column == 7) return 4;
		if (column == 8) return 9;
		if (column == 9) return 7;
		if (column == 10) return 2;
		if (column == 11) return 13;
		if (column == 12) return 12;
		if (column == 13) return 0;
		if (column == 14) return 5;
		if (column == 15) return 10;
	}
	if (row == 1)
	{
		if (column == 0) return 3;
		if (column == 1) return 13;
		if (column == 2) return 4;
		if (column == 3) return 7;
		if (column == 4) return 15;
		if (column == 5) return 2;
		if (column == 6) return 8;
		if (column == 7) return 14;
		if (column == 8) return 12;
		if (column == 9) return 0;
		if (column == 10) return 1;
		if (column == 11) return 10;
		if (column == 12) return 6;
		if (column == 13) return 9;
		if (column == 14) return 11;
		if (column == 15) return 5;
	}

	if (row == 2)
	{
		if (column == 0) return 0;
		if (column == 1) return 14;
		if (column == 2) return 7;
		if (column == 3) return 11;
		if (column == 4) return 10;
		if (column == 5) return 4;
		if (column == 6) return 13;
		if (column == 7) return 1;
		if (column == 8) return 5;
		if (column == 9) return 8;
		if (column == 10) return 12;
		if (column == 11) return 6;
		if (column == 12) return 9;
		if (column == 13) return 3;
		if (column == 14) return 2;
		if (column == 15) return 15;
	}
	if (row == 3)
	{
		if (column == 0) return 13;
		if (column == 1) return 8;
		if (column == 2) return 10;
		if (column == 3) return 1;
		if (column == 4) return 3;
		if (column == 5) return 15;
		if (column == 6) return 4;
		if (column == 7) return 2;
		if (column == 8) return 11;
		if (column == 9) return 6;
		if (column == 10) return 7;
		if (column == 11) return 12;
		if (column == 12) return 0;
		if (column == 13) return 5;
		if (column == 14) return 14;
		if (column == 15) return 9;
	}
}

BYTE make_t3(BYTE row, BYTE column)
{
	if (row == 0)
	{
		if (column == 0) return 10;
		if (column == 1) return 0;
		if (column == 2) return 9;
		if (column == 3) return 14;
		if (column == 4) return 6;
		if (column == 5) return 3;
		if (column == 6) return 15;
		if (column == 7) return 5;
		if (column == 8) return 1;
		if (column == 9) return 13;
		if (column == 10) return 12;
		if (column == 11) return 7;
		if (column == 12) return 11;
		if (column == 13) return 4;
		if (column == 14) return 2;
		if (column == 15) return 8;
	}
	if (row == 1)
	{
		if (column == 0) return 13;
		if (column == 1) return 7;
		if (column == 2) return 0;
		if (column == 3) return 9;
		if (column == 4) return 3;
		if (column == 5) return 4;
		if (column == 6) return 6;
		if (column == 7) return 10;
		if (column == 8) return 2;
		if (column == 9) return 8;
		if (column == 10) return 5;
		if (column == 11) return 14;
		if (column == 12) return 12;
		if (column == 13) return 11;
		if (column == 14) return 15;
		if (column == 15) return 1;
	}

	if (row == 2)
	{
		if (column == 0) return 13;
		if (column == 1) return 6;
		if (column == 2) return 4;
		if (column == 3) return 9;
		if (column == 4) return 8;
		if (column == 5) return 15;
		if (column == 6) return 3;
		if (column == 7) return 0;
		if (column == 8) return 11;
		if (column == 9) return 1;
		if (column == 10) return 2;
		if (column == 11) return 12;
		if (column == 12) return 5;
		if (column == 13) return 10;
		if (column == 14) return 14;
		if (column == 15) return 7;
	}
	if (row == 3)
	{
		if (column == 0) return 1;
		if (column == 1) return 10;
		if (column == 2) return 13;
		if (column == 3) return 0;
		if (column == 4) return 6;
		if (column == 5) return 9;
		if (column == 6) return 8;
		if (column == 7) return 7;
		if (column == 8) return 4;
		if (column == 9) return 15;
		if (column == 10) return 14;
		if (column == 11) return 3;
		if (column == 12) return 11;
		if (column == 13) return 5;
		if (column == 14) return 2;
		if (column == 15) return 12;
	}
}

BYTE make_t4(BYTE row, BYTE column)
{
	if (row == 0)
	{
		if (column == 0) return 7;
		if (column == 1) return 13;
		if (column == 2) return 14;
		if (column == 3) return 3;
		if (column == 4) return 0;
		if (column == 5) return 6;
		if (column == 6) return 9;
		if (column == 7) return 10;
		if (column == 8) return 1;
		if (column == 9) return 2;
		if (column == 10) return 8;
		if (column == 11) return 5;
		if (column == 12) return 11;
		if (column == 13) return 12;
		if (column == 14) return 4;
		if (column == 15) return 15;
	}
	if (row == 1)
	{
		if (column == 0) return 13;
		if (column == 1) return 8;
		if (column == 2) return 11;
		if (column == 3) return 5;
		if (column == 4) return 6;
		if (column == 5) return 15;
		if (column == 6) return 0;
		if (column == 7) return 3;
		if (column == 8) return 4;
		if (column == 9) return 7;
		if (column == 10) return 2;
		if (column == 11) return 12;
		if (column == 12) return 1;
		if (column == 13) return 10;
		if (column == 14) return 14;
		if (column == 15) return 9;
	}

	if (row == 2)
	{
		if (column == 0) return 10;
		if (column == 1) return 6;
		if (column == 2) return 9;
		if (column == 3) return 0;
		if (column == 4) return 12;
		if (column == 5) return 11;
		if (column == 6) return 7;
		if (column == 7) return 13;
		if (column == 8) return 15;
		if (column == 9) return 1;
		if (column == 10) return 3;
		if (column == 11) return 14;
		if (column == 12) return 5;
		if (column == 13) return 2;
		if (column == 14) return 8;
		if (column == 15) return 4;
	}
	if (row == 3)
	{
		if (column == 0) return 3;
		if (column == 1) return 15;
		if (column == 2) return 0;
		if (column == 3) return 6;
		if (column == 4) return 10;
		if (column == 5) return 1;
		if (column == 6) return 13;
		if (column == 7) return 8;
		if (column == 8) return 9;
		if (column == 9) return 4;
		if (column == 10) return 5;
		if (column == 11) return 11;
		if (column == 12) return 12;
		if (column == 13) return 7;
		if (column == 14) return 2;
		if (column == 15) return 14;
	}
}

BYTE make_t5(BYTE row, BYTE column)
{
	if (row == 0)
	{
		if (column == 0) return 2;
		if (column == 1) return 12;
		if (column == 2) return 4;
		if (column == 3) return 1;
		if (column == 4) return 7;
		if (column == 5) return 10;
		if (column == 6) return 11;
		if (column == 7) return 6;
		if (column == 8) return 8;
		if (column == 9) return 5;
		if (column == 10) return 3;
		if (column == 11) return 15;
		if (column == 12) return 13;
		if (column == 13) return 0;
		if (column == 14) return 14;
		if (column == 15) return 9;
	}
	if (row == 1)
	{
		if (column == 0) return 14;
		if (column == 1) return 11;
		if (column == 2) return 2;
		if (column == 3) return 12;
		if (column == 4) return 4;
		if (column == 5) return 7;
		if (column == 6) return 13;
		if (column == 7) return 1;
		if (column == 8) return 5;
		if (column == 9) return 0;
		if (column == 10) return 15;
		if (column == 11) return 10;
		if (column == 12) return 3;
		if (column == 13) return 9;
		if (column == 14) return 8;
		if (column == 15) return 6;
	}

	if (row == 2)
	{
		if (column == 0) return 4;
		if (column == 1) return 2;
		if (column == 2) return 1;
		if (column == 3) return 11;
		if (column == 4) return 10;
		if (column == 5) return 13;
		if (column == 6) return 7;
		if (column == 7) return 8;
		if (column == 8) return 15;
		if (column == 9) return 9;
		if (column == 10) return 12;
		if (column == 11) return 5;
		if (column == 12) return 6;
		if (column == 13) return 3;
		if (column == 14) return 0;
		if (column == 15) return 14;
	}
	if (row == 3)
	{
		if (column == 0) return 11;
		if (column == 1) return 8;
		if (column == 2) return 12;
		if (column == 3) return 7;
		if (column == 4) return 1;
		if (column == 5) return 14;
		if (column == 6) return 2;
		if (column == 7) return 13;
		if (column == 8) return 6;
		if (column == 9) return 15;
		if (column == 10) return 0;
		if (column == 11) return 9;
		if (column == 12) return 10;
		if (column == 13) return 4;
		if (column == 14) return 5;
		if (column == 15) return 3;
	}
}
BYTE make_t6(BYTE row, BYTE column)
{
	if (row == 0)
	{
		if (column == 0) return 2;
		if (column == 1) return 1;
		if (column == 2) return 10;
		if (column == 3) return 15;
		if (column == 4) return 9;
		if (column == 5) return 2;
		if (column == 6) return 6;
		if (column == 7) return 8;
		if (column == 8) return 0;
		if (column == 9) return 13;
		if (column == 10) return 3;
		if (column == 11) return 4;
		if (column == 12) return 14;
		if (column == 13) return 7;
		if (column == 14) return 5;
		if (column == 15) return 11;
	}
	if (row == 1)
	{
		if (column == 0) return 10;
		if (column == 1) return 15;
		if (column == 2) return 4;
		if (column == 3) return 2;
		if (column == 4) return 7;
		if (column == 5) return 12;
		if (column == 6) return 9;
		if (column == 7) return 5;
		if (column == 8) return 6;
		if (column == 9) return 1;
		if (column == 10) return 13;
		if (column == 11) return 14;
		if (column == 12) return 0;
		if (column == 13) return 11;
		if (column == 14) return 3;
		if (column == 15) return 8;
	}

	if (row == 2)
	{
		if (column == 0) return	9;
		if (column == 1) return	14;
		if (column == 2) return	15;
		if (column == 3) return	5;
		if (column == 4) return	2;
		if (column == 5) return	8;
		if (column == 6) return	12;
		if (column == 7) return	3;
		if (column == 8) return	7;
		if (column == 9) return	0;
		if (column == 10) return 4;
		if (column == 11) return 10;
		if (column == 12) return 1;
		if (column == 13) return 13;
		if (column == 14) return 11;
		if (column == 15) return 6;
	}
	if (row == 3)
	{
		if (column == 0) return 4;
		if (column == 1) return 3;
		if (column == 2) return 2;
		if (column == 3) return 12;
		if (column == 4) return 9;
		if (column == 5) return 5;
		if (column == 6) return 15;
		if (column == 7) return 10;
		if (column == 8) return 11;
		if (column == 9) return 14;
		if (column == 10) return 1;
		if (column == 11) return 7;
		if (column == 12) return 6;
		if (column == 13) return 0;
		if (column == 14) return 8;
		if (column == 15) return 13;
	}
}

BYTE make_t7(BYTE row, BYTE column)
{
	if (row == 0)
	{
		if (column == 0) return 4;
		if (column == 1) return 11;
		if (column == 2) return 2;
		if (column == 3) return 14;
		if (column == 4) return 15;
		if (column == 5) return 0;
		if (column == 6) return 8;
		if (column == 7) return 13;
		if (column == 8) return 3;
		if (column == 9) return 12;
		if (column == 10) return 9;
		if (column == 11) return 7;
		if (column == 12) return 5;
		if (column == 13) return 10;
		if (column == 14) return 6;
		if (column == 15) return 1;
	}
	if (row == 1)
	{
		if (column == 0) return 13;
		if (column == 1) return 0;
		if (column == 2) return 11;
		if (column == 3) return 7;
		if (column == 4) return 4;
		if (column == 5) return 9;
		if (column == 6) return 1;
		if (column == 7) return 10;
		if (column == 8) return 14;
		if (column == 9) return 3;
		if (column == 10) return 5;
		if (column == 11) return 12;
		if (column == 12) return 2;
		if (column == 13) return 15;
		if (column == 14) return 8;
		if (column == 15) return 6;
	}

	if (row == 2)
	{
		if (column == 0) return 1;
		if (column == 1) return 4;
		if (column == 2) return 11;
		if (column == 3) return 13;
		if (column == 4) return 12;
		if (column == 5) return 3;
		if (column == 6) return 7;
		if (column == 7) return 14;
		if (column == 8) return 10;
		if (column == 9) return 15;
		if (column == 10) return 6;
		if (column == 11) return 8;
		if (column == 12) return 0;
		if (column == 13) return 5;
		if (column == 14) return 9;
		if (column == 15) return 2;
	}
	if (row == 3)
	{
		if (column == 0) return 6;
		if (column == 1) return 11;
		if (column == 2) return 13;
		if (column == 3) return 8;
		if (column == 4) return 1;
		if (column == 5) return 4;
		if (column == 6) return 10;
		if (column == 7) return 7;
		if (column == 8) return 9;
		if (column == 9) return 5;
		if (column == 10) return 0;
		if (column == 11) return 15;
		if (column == 12) return 14;
		if (column == 13) return 2;
		if (column == 14) return 3;
		if (column == 15) return 12;
	}
}

BYTE make_t8(BYTE row, BYTE column)
{
	if (row == 0)
	{
		if (column == 0) return 13;
		if (column == 1) return 2;
		if (column == 2) return 8;
		if (column == 3) return 4;
		if (column == 4) return 6;
		if (column == 5) return 15;
		if (column == 6) return 11;
		if (column == 7) return 1;
		if (column == 8) return 10;
		if (column == 9) return 9;
		if (column == 10) return 3;
		if (column == 11) return 14;
		if (column == 12) return 5;
		if (column == 13) return 0;
		if (column == 14) return 12;
		if (column == 15) return 7;
	}
	if (row == 1)
	{
		if (column == 0) return 1;
		if (column == 1) return 15;
		if (column == 2) return 13;
		if (column == 3) return 8;
		if (column == 4) return 10;
		if (column == 5) return 3;
		if (column == 6) return 7;
		if (column == 7) return 4;
		if (column == 8) return 12;
		if (column == 9) return 5;
		if (column == 10) return 6;
		if (column == 11) return 11;
		if (column == 12) return 0;
		if (column == 13) return 14;
		if (column == 14) return 9;
		if (column == 15) return 2;
	}

	if (row == 2)
	{
		if (column == 0) return 7;
		if (column == 1) return 11;
		if (column == 2) return 4;
		if (column == 3) return 1;
		if (column == 4) return 9;
		if (column == 5) return 12;
		if (column == 6) return 14;
		if (column == 7) return 2;
		if (column == 8) return 0;
		if (column == 9) return 6;
		if (column == 10) return 10;
		if (column == 11) return 13;
		if (column == 12) return 15;
		if (column == 13) return 3;
		if (column == 14) return 5;
		if (column == 15) return 8;
	}
	if (row == 3)
	{
		if (column == 0) return 2;
		if (column == 1) return 1;
		if (column == 2) return 14;
		if (column == 3) return 7;
		if (column == 4) return 4;
		if (column == 5) return 10;
		if (column == 6) return 8;
		if (column == 7) return 13;
		if (column == 8) return 15;
		if (column == 9) return 12;
		if (column == 10) return 9;
		if (column == 11) return 0;
		if (column == 12) return 3;
		if (column == 13) return 5;
		if (column == 14) return 6;
		if (column == 15) return 11;
	}
}
#pragma endregion

DWORD make_p(DWORD h_dash)
{
	DWORD p = 0;
	int p_block[] = {
		1, 6, 20, 21, 29, 12, 28, 17,
		1, 15, 23, 26, 5, 18, 31, 10,
		2, 8, 24, 14, 32, 27, 3, 9,
		19, 13, 30, 6, 22, 11, 4, 25,
	};
	p = make_bit_permutation(&h_dash, p_block, 32);
	//p = p | ((h_dash & 0x10000) >> (16 - 0));                       // 16
	//p = p | ((h_dash & 0x2000000) >> (25 - 1));                     // 7
	//p = p | ((h_dash & 0x1000) >> (12 - 2));                        // 20
	//p = p | ((h_dash & 0x800) >> (11 - 3));							// 21
	//p = p | ((h_dash & 0x8) << (4 - 3));						    // 29
	//p = p | ((h_dash & 0x100000) >> (20 - 5));                      // 12
	//p = p | ((h_dash & 0x10) << (6 - 4));						   // 28
	//p = p | ((h_dash & 0x8000) >> (15 - 7));                        // 17

	//p = p | ((h_dash & 0x80000000) >> (31 - 8));                    // 1
	//p = p | ((h_dash & 0x20000) >> (17 - 9));                       // 15
	//p = p | ((h_dash & 0x200) << (10 - 9));						   // 23
	//p = p | ((h_dash & 0x40) << (11 - 6));						   // 26
	//p = p | ((h_dash & 0x8000000) >> (27 - 12));                    // 5
	//p = p | ((h_dash & 0x4000) >> (14 - 13));                       // 18
	//p = p | ((h_dash & 0x2) << (14 - 1));						   // 31
	//p = p | ((h_dash & 0x400000) >> (22 - 15));                     // 10

	//p = p | ((h_dash & 0x40000000) >> (30 - 16));                   // 2
	//p = p | ((h_dash & 0x1000000) >> (24 - 17));                    // 8
	//p = p | ((h_dash & 0x100) << (18 - 8));							// 24
	//p = p | ((h_dash & 0x40000) << (19 - 18));                      // 14
	//p = p | ((h_dash & 0x1) << (20));							// 32
	//p = p | ((h_dash & 0x20) << (21 - 5));						  // 27
	//p = p | ((h_dash & 0x20000000) >> (29 - 22));                   // 3
	//p = p | ((h_dash & 0x800000) >> (23 - 23));                     // 9

	//p = p | ((h_dash & 0x2000) << (24 - 13));                       // 19
	//p = p | ((h_dash & 0x80000) << (25 - 19));                      // 13
	//p = p | ((h_dash & 0x4) << (26 - 2));							 // 30
	//p = p | ((h_dash & 0x4000000) << (27 - 26));                    // 6
	//p = p | ((h_dash & 0x400) << (28 - 10));                        // 22
	//p = p | ((h_dash & 0x200000) << (29 - 21));                     // 11
	//p = p | ((h_dash & 0x10000000) << (30 - 28));                   // 4
	//p = p | ((h_dash & 0x80) << (31 - 7));						  // 25

	return p;
}

DWORD make_l(QWORD h)
{
	// 48-битовый блок данных H разделяется на восемь 6-битовых фрагментов, обозначенных h1, h2, …, h8.

	/*h1 = h | 0xFC00000000000000;
	h2 = h | 0x3F0000000000000;
	h3 = h | 0xFC00000000000;
	h4 = h | 0x3F0000000000;
	h5 = h | 0xFC00000000;
	h6 = h | 0x3F0000000;
	h7 = h | 0xFC00000;
	h8 = h | 0x3F0000;*/

	BYTE h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0, h6 = 0, h7 = 0, h8 = 0;
	h1 = (h & 0xFC00000000000000) >> 64 - 8;
	h2 = (h & (0xFC00000000000000 >> 6)) >> 64 - 8 * 2 + 2;
	h3 = (h & (0xFC00000000000000 >> 12)) >> 64 - 8 * 3 + 4;
	h4 = (h & (0xFC00000000000000 >> 18)) >> 64 - 8 * 4 + 6;
	h5 = (h & (0xFC00000000000000 >> 24)) >> 64 - 8 * 5 + 8;
	h6 = (h & (0xFC00000000000000 >> 30)) >> 64 - 8 * 6 + 10;
	h7 = (h & (0xFC00000000000000 >> 36)) >> 64 - 8 * 7 + 12;
	h8 = (h & (0xFC00000000000000 >> 42)) >> 64 - 8 * 8 + 14;

	// Каждое из значений hj преобразуется в новое 4-битовое значение tj с помощью соответствующего узла замены Sj.
	BYTE row = 0;
	BYTE col = 0;

	BYTE t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	get_row_col(h1, &row, &col);
	t1 = make_t1(row, col) << 4;

	get_row_col(h2, &row, &col);
	t2 = make_t2(row, col) << 4;

	get_row_col(h3, &row, &col);
	t3 = make_t3(row, col) << 4;

	get_row_col(h4, &row, &col);
	t4 = make_t4(row, col) << 4;

	get_row_col(h5, &row, &col);
	t5 = make_t5(row, col) << 4;

	get_row_col(h6, &row, &col);
	t6 = make_t6(row, col) << 4;

	get_row_col(h7, &row, &col);
	t7 = make_t7(row, col) << 4;

	get_row_col(h8, &row, &col);
	t8 = make_t8(row, col) << 4;


	//  Полученные восемь фрагментов tj вновь объединяются в 32-битовый блок H’.
	DWORD h_dash = 0;
	h_dash = h_dash | ((DWORD)t1 << 24);
	h_dash = h_dash | (((DWORD)t2 << 24) >> 4);
	h_dash = h_dash | (((DWORD)t3 << 24) >> 8);
	h_dash = h_dash | (((DWORD)t4 << 24) >> 12);
	h_dash = h_dash | (((DWORD)t5 << 24) >> 16);
	h_dash = h_dash | (((DWORD)t6 << 24) >> 20);
	h_dash = h_dash | (((DWORD)t7 << 24) >> 24);
	h_dash = h_dash | (((DWORD)t8 << 24) >> 28);

	// Для H’ выполняется перестановка битов P. 
	DWORD l = 0;
	l = make_p(h_dash);
	return l;
}

DWORD make_f(DWORD l, QWORD k)
{
	// На вход поступает 32-битовая половинка шифруемого блока Li и 48-битовый ключевой элемент ki.
	// Li разбивается на 8 тетрад по 4 бита. 
	// Каждая тетрада по циклическому закону дополняется крайними битами из соседних тетрад до 6-битового фрагмента (функция расширения Е)
	QWORD e = 0;
	e = make_e(l); // указатель не нужен?

	// Х побитово суммируется по модулю 2 с ключевым элементом ki.
	QWORD h = e ^ k;

	DWORD l_out = 0;
	l_out = make_l(h);
	return l_out;
}	

QWORD swap_qword_bytes(QWORD qword) {

	QWORD swapped_qword = 0;

	swapped_qword = (swapped_qword | (qword & 0xff)) ;
	swapped_qword = (swapped_qword | (qword & 0xff00)) << 47;
	swapped_qword = (swapped_qword | (qword & 0xff0000)) << 39;
	swapped_qword = (swapped_qword | (qword & 0xff000000)) << 31;
	swapped_qword = (swapped_qword | (qword & 0xff00000000)) << 23;
	swapped_qword = (swapped_qword | (qword & 0xff0000000000)) << 15;
	swapped_qword = (swapped_qword | (qword & 0xff000000000000)) << 7;
	swapped_qword = (swapped_qword | (qword & 0xff00000000000000));

	return swapped_qword;
}

BYTE* ecb_cipher(BYTE* plain_text, int text_size, QWORD key)
{
	std::cout << std::endl << "==========CIPHERING STARTS===========" << std::endl;

	std::cout << "key before correction: " << std::hex << key << std::endl;
	key_correction(&key); 
	std::cout << "key after correction: " << std::hex << key << std::endl;

	// Выработка ключевых элементов
	make_k_keys(key);

	// Зашифрование
	BYTE* hCipherText = (BYTE*)GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, text_size);
	int curBlock = 0;
	int nBlocks = text_size / 64;

	//while (curBlock != nBlocks - 1)
	while (curBlock != 1)
	{
		std::cout << std::endl << "====BLOCK: " << std::dec << curBlock << " ====" << std::endl;
		QWORD block_64 = 0;
		block_64 = *((QWORD*)plain_text + curBlock);
		std::cout << "block: " << block_64 << std::endl;

		// Шифрование 64-битового блока открытого текста T начинается с начальной перестановки битов IP. 
		// В таблице указывается новое положение соответствующего бита.
		// Таким образом, при выполнении начальной перестановки 58-ый бит станет 1-ым, 50-ый – 2-ым, 42-ой – 3-им и т.д.
		QWORD t_star = 0;
		t_star = make_ip(&block_64);
		std::cout << "T*: " << std::hex << t_star << std::endl;
		// Результат перестановки Т* разделяется на две 32 - битовые половинки H1 и L1, 
		DWORD h = 0, l = 0;
		split_ip(t_star, & h, & l);

		// с которыми выполняются 16 раундов преобразования(ячеек Фейстеля)
		int j = 0;
		DWORD l_tmp;
		DWORD f_result;
		QWORD k;
		std::cout << std::endl << "=FEISTEL=" << std::endl;
		while (j < 15)
		{
			l_tmp = 0;
			f_result = 0;
			k = 0;

			k = *(((QWORD*)k_keys_buffer + j));
			std::cout << std::endl << "before iteration: " << j << " h: " << h << "  l: " << l << " k: " << k << " f_result: " << f_result << std::endl;
			f_result = make_f(l, k); 
			l_tmp = l;
			l = h ^ f_result;
			h = l_tmp;
			std::cout << "after iteration: " << j << " h: " << h << "  l: " << l << " k: " << k << " f_result: " << f_result << std::endl;
			j++;
		}
		
		// В последнем раунде происходит то же самое, за исключением обмена значениями половинок блока.
		l_tmp = 0;
		f_result = 0;
		k = 0;

		k = *((QWORD*)k_keys_buffer + j);
		std::cout << std::endl << "before iteration: " << j << " h: " << h << "  l: " << l << " k: " << k << " f_result: " << f_result << std::endl;
		f_result = make_f(l, k); 
		h = h ^ f_result;
		std::cout  << "after iteration: " << j << " h: " << h << "  l: " << l << " k: " << k <<  " f_result: " << f_result <<std::endl;
		std::cout << std::endl << "=FEISTEL ENDS=" << std::endl;

		// Половинки H17 и L17 объединяются в полный блок Т**, 
		QWORD t_star_star = 0;
		t_star_star = h;
		t_star_star = t_star_star << 32;
		QWORD l_tmp2 = 0;
		l_tmp2 = l;
		l_tmp2 = l_tmp2;
		t_star_star = t_star_star | l_tmp2;

		// в котором выполняется конечная битовая перестановка IP–1 по аналогии с начальной.
		QWORD c = 0;
		std::cout << "T**: " << std::hex << t_star_star << std::endl;
		c = make_ip1(&t_star_star);
		std::cout << "after IP-1: " << std::hex << c << std::endl;
		memmove((QWORD*)hCipherText + curBlock, &c,  8);

		curBlock++;
	}
	std::cout << std::endl << "==========CIPHERING ENDS===========" << std::endl;
	return hCipherText;
}

BYTE* ecb_decipher(BYTE* cipher_text, int text_size, QWORD key)
{
	std::cout << std::endl << "==========DECIPHERING STARTS===========" << std::endl;

	std::cout << "key before correction: " << std::hex << key << std::endl;
	key_correction(&key);
	std::cout << "key after correction: " << std::hex << key << std::endl;
	// Выработка ключевых элементов
	make_k_keys(key);

	BYTE* hDeCipherText = (BYTE*)GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, text_size);
	int curBlock = 0;
	int nBlocks = text_size / 64;

	//while (curBlock != nBlocks - 1)
	while (curBlock != 1)
	{
		std::cout << std::endl << "====BLOCK: " << std::dec <<curBlock << " ====" << std::endl;
		QWORD block_64 = *((QWORD*)cipher_text + curBlock);
		std::cout << "block: " << curBlock << " " << std::hex << block_64 << std::endl;
		// Дешифрование 64-битового блока текста C начинается с начальной перестановки битов IP. 
		// В таблице указывается новое положение соответствующего бита.
		// Таким образом, при выполнении начальной перестановки 58-ый бит станет 1-ым, 50-ый – 2-ым, 42-ой – 3-им и т.д.
		QWORD t_star = 0;
		t_star = make_ip(&block_64);
		std::cout << "T*: " << std::hex << t_star << std::endl;
		// Результат перестановки Т* разделяется на две 32 - битовые половинки H1 и L1, 
		DWORD h = 0, l = 0;
		split_ip(t_star, &h, &l);

		// с которыми выполняются 16 раундов преобразования(ячеек Фейстеля)
		int j = 15;
		DWORD l_tmp;
		DWORD f_result;
		QWORD k;
		std::cout << std::endl << "=FEISTEL=" << std::endl;
		while (j > 0)
		{
			l_tmp = 0;
			f_result = 0;
			k = 0;

			k = *(((QWORD*)k_keys_buffer + j));
			std::cout << std::endl << "before iteration: " << j << " h: " << h << "  l: " << l << " k: " << k << " f_result: " << f_result << std::endl;
			f_result = make_f(l, k);
			l_tmp = l;
			l = h ^ f_result;
			h = l_tmp;
			std::cout << "after iteration: " << j << " h: " << h << "  l: " << l << " k: " << k << " f_result: " << f_result << std::endl;
			j--;
		}
		

		// В последнем раунде происходит то же самое, за исключением обмена значениями половинок блока.
		l_tmp = 0;
		f_result = 0;
		k = 0;


		k = *((QWORD*)k_keys_buffer + j);
		std::cout << std::endl << "before iteration: " << j << " h: " << h << "  l: " << l << " k: " << k << " f_result: " << f_result << std::endl;
		f_result = make_f(l, k);
		h = h ^ f_result;
		std::cout << "after iteration: " << j << " h: " << h << "  l: " << l << " k: " << k << " f_result: " << f_result << std::endl;
		std::cout << std::endl << "=FEISTEL ENDS=" << std::endl;

		// Половинки H17 и L17 объединяются в полный блок Т**, 
		QWORD t_star_star = 0;
		t_star_star = h;
		t_star_star = t_star_star << 32;
		l_tmp = 0;
		l_tmp = l;
		l_tmp = l_tmp << 4;
		t_star_star = t_star_star | l_tmp;

		// в котором выполняется конечная битовая перестановка IP–1 по аналогии с начальной.
		QWORD c = 0;
		std::cout << "T**: " << std::hex << &t_star_star << std::endl;
		c = make_ip1(&t_star_star);
		std::cout << "IP-1: " << std::hex << c << std::endl;
		memmove((QWORD*)hDeCipherText + curBlock, &c, 8);

		curBlock++;
	}
	std::cout << std::endl << "==========DECIPHERING ENDS===========" << std::endl;
	return hDeCipherText;
}