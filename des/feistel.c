#include "feistel.h"

int f(int* l, int* k)
{
	int x= make_e();
	int h = make_h();

	return 0;
}

void make_e(int* l)
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
}
void make_h(int *x, int* k)
{
	int h[48] = { 0 };
	for (int i = 0; i < 48; i++)
	{
		h[i] = x[i] ^ h[i];
	}

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