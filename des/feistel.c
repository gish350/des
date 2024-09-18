#include "feistel.h"



int f(int* l, int* k)
{
	int x= make_e();
	int h = make_h();
	int h_sp = split_h_8_4(h);

	return 0;
}

int* make_e(int* l)
{
	int e[48];

	e[0] = l[31];
	e[47] = l[0];
	int j = 0;
	for (int i = 1; i < 47; i++)
	{
		if (i % 6 == 0) 
		{
			j -= 2;
		}
		e[i] = l[j];
		j++;
	}
	return e;
}
int* make_h(int *x, int* k)
{
	int h[48] = { 0 };
	for (int i = 0; i < 48; i++)
	{
		h[i] = x[i] ^ h[i];
	}
	return h;
}

int* split_h_8_4(int *h)
{
	int h_slplit[8][6] = { 0 };
	int j = 0;
	int k = 0;
	for (int i = 0; i < 32; i++)
	{
		h_slplit[j][k] = h[i];
		if (i % 4)
		{
			j++;
			k = 0;
		}
		k++;
	}
	return h_slplit;
}

int bin2dec(int* bin)
{
	int res = 0;
	int pow_ = 0;
	int size = sizeof(bin);
	for (int i = size - 1; i > -1; --i)
	{
		res += bin[i] * pow(2, pow_);
		pow_ += 1;
	}
	return res;
}

int* dec2bin(int dec)
{
	if (dec = 0) return 0;
	if (dec = 1) return 1;

	int i = 0;
	int res[4];
	while (dec > 0)
	{
		res[i] = dec % 2;
		dec /= 2;
		i++;
	}
	
	return res;
}

int* h_to_t(int h_8_4[8][6])
{
	typedef int s[4][16];
	s* pS = 0;
	int t[32] = { 0 };
	int k = 0;
	for (int i = 0; i < 8; i++)
	{
		
		int b1b6[2] = { 0 };
		b1b6[0] = h_8_4[i][0];
		b1b6[1] = h_8_4[i][5];
		int b2b5[4] = { 0 };
		b2b5[0] = h_8_4[i][0];
		b2b5[1] = h_8_4[i][1];
		b2b5[2] = h_8_4[i][2];
		b2b5[3] = h_8_4[i][3];
		b2b5[4] = h_8_4[i][4];
		int row = bin2dec(b1b6);
		int col = bin2dec(b2b5);

		if (i == 0) pS = s1;
		else if (i == 1) pS = s2;
		else if (i == 2) pS = s3;
		else if (i == 3) pS = s4;
		else if (i == 4) pS = s5;
		else if (i == 5) pS = s6;
		else if (i == 6) pS = s7;
		else if (i == 7) pS = s8;

		int t_dec = pS[row][col];
		int* t_bin = dec2bin(t_dec);

		int m = 0;
		for (k; k % 4 != 0 ; k++, m++)
		{
			t[k] = t_bin[m];
		}
	}
	return t;
}

int* p_permutation(int* h)
{
	int l[32] = { 0 };

	l[0] = h[15];
	l[1] = h[6];
	l[2] = h[19];
	l[3] = h[20];
	l[4] = h[28];
	l[5] = h[11];
	l[6] = h[27];
	l[7] = h[16];
	l[8] = h[0];
	l[9] = h[14];
	l[10] = h[22];
	l[11] = h[25];
	l[12] = h[4];
	l[13] = h[17];
	l[14] = h[30];
	l[15] = h[9];
	l[16] = h[1];
	l[17] = h[7];
	l[18] = h[23];
	l[19] = h[13];
	l[20] = h[31];
	l[21] = h[26];
	l[22] = h[2];
	l[23] = h[8];
	l[24] = h[18];
	l[25] = h[12];
	l[26] = h[29];
	l[27] = h[5];
	l[28] = h[21];
	l[29] = h[10];
	l[30] = h[3];
	l[31] = h[24];
	
	return l;
}

int cipher(int* h, int* l)
{
	int k = 16;
	int res = 0;
	int tmp_l = 0;

	for (int n = 1; n < k + 1; n++)
	{
		tmp_l = h;
		res = f(h, n);
		h = res ^ l;
		l = tmp_l;
	}
	l = h;
	h = tmp_l;

	return 0;
}

int uncipher(int r, int l)
{
	int k = 3;
	int res = 0;
	int tmp_l = 0;

	for (int n = k; n > 0; n--)
	{
		tmp_l = l;
		res = f(l, n);
		l = res ^ r;
		r = tmp_l;
	}
	printf("L: %d R: %d", l, r);
	return 0;
}

void des_ecb()
{
	make_permutation();
}