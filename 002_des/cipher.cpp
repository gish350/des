#include <windows.h>
#include <winDNS.h>

QWORD make_ip(QWORD* block_64)
{
	QWORD ip = 0;

	ip = ip | ((*block_64 & 0x40) >> 6 - 0);                         // 58
	ip = ip | ((*block_64 & 0x4000) >> 14 - 1);                      // 50
	ip = ip | ((*block_64 & 0x400000) >> 22 - 2);                    // 42
	ip = ip | ((*block_64 & 0x40000000) >> 30 - 3);                 // 34
	ip = ip | ((*block_64 & 0x4000000000) >> 38 - 4);               // 26
	ip = ip | ((*block_64 & 0x400000000000) >> 46 - 5);             // 18
	ip = ip | ((*block_64 & 0x40000000000000) >> 54 - 6);           // 10
	ip = ip | ((*block_64 & 0x4000000000000000) >> 62 - 7);          // 2

	ip = ip | ((*block_64 & 0x10) << 8 - 4);                         // 60
	ip = ip | ((*block_64 & 0x1000) >> 12 - 9);                      // 52
	ip = ip | ((*block_64 & 0x100000) >> 20 - 10);                   // 44
	ip = ip | ((*block_64 & 0x10000000) >> 28 - 11);                // 36
	ip = ip | ((*block_64 & 0x1000000000) >> 36 - 12);              // 28
	ip = ip | ((*block_64 & 0x100000000000) >> 44 - 13);            // 20
	ip = ip | ((*block_64 & 0x10000000000000) >> 52 - 14);          // 12
	ip = ip | ((*block_64 & 0x1000000000000000) >> 60 - 15);        // 4

	ip = ip | ((*block_64 & 0x4) << 16 - 2);                         // 62
	ip = ip | ((*block_64 & 0x400) << 17 - 10);                      // 54
	ip = ip | ((*block_64 & 0x40000) >> 18 - 18);                    // 46
	ip = ip | ((*block_64 & 0x4000000) >> 26 - 19);                 // 38
	ip = ip | ((*block_64 & 0x400000000) >> 34 - 20);               // 30
	ip = ip | ((*block_64 & 0x40000000000) >> 42 - 21);             // 22
	ip = ip | ((*block_64 & 0x4000000000000) >> 50 - 22);            // 14
	ip = ip | ((*block_64 & 0x400000000000000) >> 58 - 23);          // 6

	ip = ip | ((*block_64 & 0x1) << 24);                         // 64
	ip = ip | ((*block_64 & 0x100) << 25 - 8);                       // 56
	ip = ip | ((*block_64 & 0x10000) << 26 - 16);                    // 48
	ip = ip | ((*block_64 & 0x1000000) << 27 - 24);                 // 40
	ip = ip | ((*block_64 & 0x100000000) >> 32 - 28);               // 32
	ip = ip | ((*block_64 & 0x10000000000) >> 40 - 29);             // 24
	ip = ip | ((*block_64 & 0x1000000000000) >> 48 - 30);            // 16
	ip = ip | ((*block_64 & 0x100000000000000) >> 56 - 31);         // 8

	ip = ip | ((*block_64 & 0x80) << 32 - 7);                        // 57
	ip = ip | ((*block_64 & 0x8000) << 33 - 15);                     // 49
	ip = ip | ((*block_64 & 0x800000) << 34 - 23);                   // 41
	ip = ip | ((*block_64 & 0x80000000) << 35 - 31);                // 33
	ip = ip | ((*block_64 & 0x8000000000) >> 39 - 36);              // 25
	ip = ip | ((*block_64 & 0x800000000000) >> 47 - 37);            // 17
	ip = ip | ((*block_64 & 0x80000000000000) >> 55 - 38);          // 9
	ip = ip | ((*block_64 & 0x8000000000000000) >> 63 - 39);        // 1

	ip = ip | ((*block_64 & 0x20) << 40 - 5);                        // 59
	ip = ip | ((*block_64 & 0x2000) << 41 - 13);                     // 51
	ip = ip | ((*block_64 & 0x200000) << 42 - 21);                   // 43
	ip = ip | ((*block_64 & 0x20000000) << 43 - 29);                // 35
	ip = ip | ((*block_64 & 0x2000000000) << 44 - 37);              // 27
	ip = ip | ((*block_64 & 0x200000000000) >> 45 - 45);            // 19
	ip = ip | ((*block_64 & 0x20000000000000) >> 53 - 46);          // 11
	ip = ip | ((*block_64 & 0x2000000000000000) >> 61 - 47);        // 3

	ip = ip | ((*block_64 & 0x8) << 48 - 3);                         // 61
	ip = ip | ((*block_64 & 0x800) << 49 - 11);                      // 53
	ip = ip | ((*block_64 & 0x80000) << 50 - 19);                    // 45
	ip = ip | ((*block_64 & 0x8000000) << 51 - 27);                 // 37
	ip = ip | ((*block_64 & 0x800000000) << 52 - 35);                // 29
	ip = ip | ((*block_64 & 0x80000000000) << 53 - 43);             // 21
	ip = ip | ((*block_64 & 0x8000000000000) << 54 - 51);            // 13
	ip = ip | ((*block_64 & 0x800000000000000) >> 59 - 55);          // 5

	ip = ip | ((*block_64 & 0x2) << 56 - 1);                         // 63
	ip = ip | ((*block_64 & 0x200) << 57 - 9);                       // 55
	ip = ip | ((*block_64 & 0x20000) << 58 - 17);                    // 47
	ip = ip | ((*block_64 & 0x2000000) << 59 - 25);                  // 39
	ip = ip | ((*block_64 & 0x200000000) << 60 - 33);               // 31
	ip = ip | ((*block_64 & 0x20000000000) << 61 - 41);             // 23
	ip = ip | ((*block_64 & 0x2000000000000) << 62 - 49);           // 15
	ip = ip | ((*block_64 & 0x200000000000000) << 63 - 57);         // 7

	return ip;
}

void split_ip(QWORD ip)
{
	// Преобразуем 32-битный h-буфер; отбрасываем последние 32 бита
	DWORD h = ip >> 32;


	// Преобразуем 32-битный l-буфер; отбрасываем первые 32 бита

	DWORD l = (ip << 32) >> 32;

}



void make_e(DWORD l)
{
	QWORD e = 0;
	QWORD tmp_l = 0;
	tmp_l = (tmp_l | l) << 32;

	e = e | ((tmp_l & 0x40) >> 6 - 0);											  // 58

	e = e | ((tmp_l & 0x100000000) >> 32 - 0);										 //32
	e = e | ((tmp_l & 0x8000000000000000) >> 63 - 1);                               //1
	e = e | ((tmp_l & 0x4000000000000000) >> 62 - 2);                               //2
	e = e | ((tmp_l & 0x2000000000000000) >> 61 - 3);                               //3
	e = e | ((tmp_l & 0x1000000000000000) >> 60 - 4);                               //4
	e = e | ((tmp_l & 0x800000000000000) >> 59 - 5);                                //5
	e = e | ((tmp_l & 0x1000000000000000) >> 60 - 6);                               //4
	e = e | ((tmp_l & 0x800000000000000) >> 59 - 7);                                //5
	e = e | ((tmp_l & 0x400000000000000) >> 58 - 8);                                //6
	e = e | ((tmp_l & 0x200000000000000) >> 57 - 9);                                //7
	e = e | ((tmp_l & 0x100000000000000) >> 56 - 10);                               //8
	e = e | ((tmp_l & 0x80000000000000) >> 55 - 11);                                //9
	e = e | ((tmp_l & 0x100000000000000) >> 56 - 12);                               //8
	e = e | ((tmp_l & 0x80000000000000) >> 55 - 13);                                //9
	e = e | ((tmp_l & 0x40000000000000) >> 54 - 14);                                //10
	e = e | ((tmp_l & 0x20000000000000) >> 53 - 15);                                //11
	e = e | ((tmp_l & 0x10000000000000) >> 52 - 16);                                //12
	e = e | ((tmp_l & 0x8000000000000) >> 51 - 17);									//13
	e = e | ((tmp_l & 0x10000000000000) >> 52 - 18);                                //12
	e = e | ((tmp_l & 0x8000000000000) >> 51 - 19);									  //13
	e = e | ((tmp_l & 0x4000000000000) >> 50 - 20);									 //14
	e = e | ((tmp_l & 0x2000000000000) >> 49 - 21);									 //15
	e = e | ((tmp_l & 0x1000000000000) >> 48 - 22);									  //16
	e = e | ((tmp_l & 0x800000000000) >> 47 - 23);									  //17
	e = e | ((tmp_l & 0x1000000000000) >> 48 - 24);									   //16
	e = e | ((tmp_l & 0x800000000000) >> 47 - 25);								   //17
	e = e | ((tmp_l & 0x400000000000) >> 46 - 26);                          //18
	e = e | ((tmp_l & 0x200000000000) >> 45 - 27);                          //19
	e = e | ((tmp_l & 0x100000000000) >> 44 - 28);                          //20
	e = e | ((tmp_l & 0x80000000000) >> 43 - 29);                           //21
	e = e | ((tmp_l & 0x100000000000) >> 44 - 30);                          //20
	e = e | ((tmp_l & 0x80000000000) >> 43 - 31);                           //21
	e = e | ((tmp_l & 0x40000000000) >> 42 - 32);                           //22
	e = e | ((tmp_l & 0x20000000000) >> 41 - 33);                           //23
	e = e | ((tmp_l & 0x10000000000) >> 40 - 34);                           //24
	e = e | ((tmp_l & 0x8000000000) >> 39 - 35);                            //25
	e = e | ((tmp_l & 0x10000000000) >> 40 - 36);                           //24
	e = e | ((tmp_l & 0x8000000000) >> 39 - 37);                            //25
	e = e | ((tmp_l & 0x4000000000) >> 38 - 38);                            //26
	e = e | ((tmp_l & 0x2000000000) << 39 - 37);                            //27
	e = e | ((tmp_l & 0x1000000000) << 40 - 36);                            //28
	e = e | ((tmp_l & 0x800000000) << 41 - 35);                             //29
	e = e | ((tmp_l & 0x1000000000) << 42 - 36);                            //28
	e = e | ((tmp_l & 0x800000000) << 43 - 35);                             //29
	e = e | ((tmp_l & 0x400000000) << 44 - 34);                             //30
	e = e | ((tmp_l & 0x200000000) << 45 - 33);                             //31
	e = e | ((tmp_l & 0x100000000) << 46 - 32);                             //32
	e = e | ((tmp_l & 0x8000000000000000) >> 63 - 47);                              //1
}

void make_f(DWORD l, QWORD k)
{
	make_e(l);
}

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

void make_h_dash(QWORD h)
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
	
	t1 = 0xf0;
	t2 = 0xf0;
	t3 = 0xf0;
	t4 = 0xf0;

	t5 = 0xf0;
	t6 = 0xf0;
	t7 = 0xf0;
	t8 = 0xf0;
	DWORD test = 0;
	test =  t1;
	test = (test << 24);
	test = test >> 8;
	//  Полученные восемь фрагментов tj вновь объединяются в 32-битовый блок H’.
	DWORD h_dash = 0;
	h_dash = h_dash | ((DWORD)t1 << 24);
	h_dash = h_dash | (((DWORD)t2 << 24) >> 4);
	h_dash = h_dash | (((DWORD)t3 << 24) >> 8);	// смещение не работает из за типа BYTE?
	h_dash = h_dash | (((DWORD)t4 << 24) >> 12);
	h_dash = h_dash | (((DWORD)t5 << 24) >> 16);
	h_dash = h_dash | (((DWORD)t6 << 24) >> 20);
	h_dash = h_dash | (((DWORD)t7 << 24) >> 24);
	h_dash = h_dash | (((DWORD)t8 << 24) >> 28);
}



void ecb_cipher(BYTE* plain_text)
{
	QWORD ip_test = 0xFFFFFFFFFFFFFFFF;
	make_ip(&ip_test);
	QWORD split_ip_test = 0xAAAAAAAABBBBBBBB;
	split_ip(split_ip_test);
	DWORD make_e_test = 0xFFFFFFFF;
	make_e(make_e_test);
	//QWORD H = x ^ k;
	QWORD h_dash_test = 0x3F0000;
	make_h_dash(h_dash_test);

}