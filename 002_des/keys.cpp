#include "keys.h"
#include <cstdint>
#include <iostream> // ������

extern BYTE* k_keys_buffer = nullptr;

// ��������� �����: ���������, ����� ����� ����� ������� ����� �����, 
// ������� �����������, ���� �������� (�������� ���������� ���).
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
		//7-�� ��� - �����������

		*(BYTE*)key = *(BYTE*)key | 0x1; // ����������� ��� - ������ 1

		if (!((_0 + _1 + _2 + _3 + _4 + _5 + _6 + 1) % 2)) // ���� ����� ����� ������:
		{
			*(BYTE*)key = *(BYTE*)key ^ 0x80; // ������ ������ ��� �� ���������������
		}
		key = (BYTE*)key + 1; // ��������� �� i-�� ���� �����
	}

	key = (BYTE*)key - 8; // ������� ��������� � ������
}

QWORD make_bit_permutation(LPVOID hSource, int perm_table[], int source_size, int table_size)
{
	LPVOID handle;
	QWORD mask;
	QWORD result = 0;
	int bitPos;
	int i = 0;
	if (table_size == 56 || table_size == 48 || table_size == 64)
	{
		QWORD qwordBuffer = 0; 
		qwordBuffer = *(QWORD*)hSource;

		if (source_size == 32)
		{
			qwordBuffer = qwordBuffer << 32;
		}

		while (i < table_size)
		{
			mask = 0;
			bitPos = perm_table[i] - 1;
			// ��������� �����
			// ���������� ���������� ���, �� ������� ����� �������� �����, ����� �������� 1
			int shiftCount = 63 - bitPos;

			mask |= (static_cast<QWORD>(1) << (63 - bitPos));

			// �������� �������, ��������� ���-�� ������� ���
			int shift = 63 - shiftCount - i;
			// ������ ������� �� i-� �������
			if (shift >= 0)
				result = result | ((qwordBuffer & mask) << shift);
			else
			{
				shift = -shift;
				result = result | ((qwordBuffer & mask) >> shift);
			}

			i++;
		}
	}
	else if (table_size == 32)
	{
		DWORD* dwordHandle = 0;
		dwordHandle = (DWORD*)hSource;

		while (i < table_size)
		{
			mask = 0;
			bitPos = perm_table[i] - 1;
			// ��������� �����
			// ���������� ���������� ���, �� ������� ����� �������� �����, ����� �������� 1
			int shiftCount = 31 - bitPos;

			mask |= (static_cast<QWORD>(1) << (31 - bitPos));

			// �������� �������, ��������� ���-�� ������� ���
			int shift = 31 - shiftCount - i;
			// ������ ������� �� i-� �������
			if (shift >= 0)
				result = result | ((*dwordHandle & mask) << shift);
			else
			{
				shift = -shift;
				result = result | ((*dwordHandle & mask) >> shift);
			}

			i++;
		}
	}
	
	return result;
}

QWORD make_pc1(QWORD* hKey)
{
	QWORD pc1_key = 0;
	int pc1_table[] = {57,	49,	41,	33,	25,	17,	9,
						1,	58,	50,	42,	34,	26,	18,
						10,	2,	59,	51,	43,	35,	27,
						19,	11,	3,	60,	52,	44,	36,
						63,	55,	47,	39,	31,	23,	15,
						7,	62,	54,	46,	38,	30,	22,
						14,	6,	61,	53,	45,	37,	29,
						21,	13,	5,	28,	20,	12,	4 };

	pc1_key = make_bit_permutation(hKey, pc1_table,56, 56);
	return pc1_key;
}

void split_pc1(QWORD* hPc1, DWORD& hH, DWORD& hL)
{

	// ����������� 32-������ h-�����; ����������� ��������� 32 + 4 ����
	DWORD _h = *hPc1 >> 32;
	_h = _h & 0xFFFFFFF0;
	hH = _h;

	// ����������� 32-������ l-�����; ����������� ������ 28 ���,
	// ����������� ��������� (64-56) 8 ���

	DWORD _l = DWORD((*hPc1 << 28) >> 32);
	hL = _l;
}
void make_shift(DWORD* hH, DWORD* hL, int i)
{
	if (i == 0 || i == 1 || i == 8 || i == 15)
	{
		*hH = *hH << 1;
		*hL = *hL << 1;
	}
	else
	{
		*hH = *hH << 2;
		*hL = *hL << 2;
	}
}


void make_k_key(DWORD h, DWORD l, int k)
{
	// ���������� h � l
	QWORD hlUnion = 0;
	hlUnion = h;
	hlUnion = hlUnion << 32;
	QWORD l_tmp = 0;
	l_tmp = l;
	l_tmp = l_tmp << 4;
	hlUnion = hlUnion | l_tmp;

	QWORD tmpBuffer = 0;
	int pc2_table[] = {
		14,	17,	11,	24,	1,	5,
		3,	28,	15,	6,	21,	10,
		23,	19,	12,	4,	26,	8,
		16,	7,	27,	20,	13,	2,
		41,	52,	31,	37,	47,	55,
		30,	40,	51,	45,	33,	48,
		44,	49,	39,	56,	34,	53,
		46,	42,	50,	36,	29,	32
	};
	tmpBuffer = make_bit_permutation(&hlUnion, pc2_table, 56, 48);

	memmove(k_keys_buffer + k, (BYTE*)&tmpBuffer, 8); // ������ - 6, �� ������ 8 ��� ��������
}


void make_k_keys(QWORD key)
{
	// ��������� �������� ��������� �� ����� K ���������� �� ������� �������-������������ ����� PC1,
	// ������� �������� 56 �� 64 ����� ����� � ����������� �� � ������ �������.
	// � ������� ����������� ����� ��������� ���������������� ����.
	QWORD pc1 = make_pc1(&key);
	//std::cout << "pc1: " << pc1 << std::endl;
	DWORD h = 0, l = 0; // 28 ������ ������, ��������� 32-28=4 ���� �� ����������
	//��������� �������-������������ K* ����������� �� ��� 28-������� ���������: ������� H1 � ������� L1
	split_pc1(&pc1, h, l);


	// 48 * 16 / 8 = 96 ���� (64 * 16 / 8 = 128 ��� ��������)- ��������� ������ ������ k1 
	k_keys_buffer = (BYTE*)GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, 128);

	int i = 0;
	int k = 0;
	//16 ��� ����������� ���������.
	while (i < 16)
	{
		// � ����������� �� ������ �������� ��� ��������� ���������� ���������� �� 1 ��� 2 ���� �����.
		make_shift(&h, &l, i);
		// ����� ������ ��������� ������������ � �� ��� � ������� �������-������������ PC2 ���������� 48 �����, 
		// ������� � ��������� ��������� �������� �������.
		make_k_key(h, l, k);
		k += 8; // 6 ���� (48 ���) ������ ������ k1 �������� (������ 8 ��� �������� ���������)
		i++;
	}
}