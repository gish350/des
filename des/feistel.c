

int f(int l, int n) 
{
	return (l + n) % 256;
}

int cipher(int l, int r)
{
	int k = 16;
	int res = 0;
	int tmp_l = 0;
	
	for (int n = 1; n < k + 1; n++)
	{
		tmp_l = l;
		res = f(l, n);
		l = res ^ r;
		r = tmp_l;
	}
	return 0;
}

int uncipher(int r, int l)
{
	int k = 16;
	int res = 0;
	int tmp_l = 0;

	for (int n = k; n > 0; n--) 
	{
		tmp_l = l;
		res = f(l, n);
		l = res ^ r;
		r = tmp_l;
	}
	return 0;
}