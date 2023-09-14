#include "feistel.h"

int f(int l, int n) 
{
	return (l + n) % 256;
}

int cipher(int l, int r)
{
	int k = 3;
	int res = 0;
	int tmp_l = 0;
	
	for (int n = 1; n < k + 1; n++)
	{
		tmp_l = l;
		res = f(l, n);
		l = res ^ r;
		r = tmp_l;
	}
	r = l;
	l = tmp_l;
	
	printf("L: %d R: %d \n", l, r);
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