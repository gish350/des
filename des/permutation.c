


int* make_ip(int initial_64[])
{
	int first = 57;
	int cur = first;
	static int ip[64] = { 0 };
	for (int i = 0; i < 64; i++)
	{
		if (i % 8 == 0 && i != 0)
		{
			first += 2;
			cur = first;
		}
		if (i == 32)
		{
			first -= 9;
			cur = first;
		}
		ip[i] = initial_64[cur];
		cur -= 8;
		
		
	}
	return ip;
}

int* make_pc1(int ip_64[])
{
	static int pc1[56];
	int j = 0;
	for (int i = 0; i < 56 && j < 64; i++)
	{
		if (j % 7 != 0 || j == 0)	pc1[i] = ip_64[j];
		else i--;
		j++;
	}
	return pc1;
}

void split_pc1(int pc1[], int* outH, int* outL)
{
	int j = 0;
	for (int i = 0; i < 28; i++) 
	{
		outH[i] = pc1[j];
		j++;
	}
	for (int i = 0; i < 28; i++)
	{
		outL[i] = pc1[j];
		j++;
	}
}

int* get_pc2(int h[], int l[])
{
	static int pc2[48] = { 0 };

	int k = 0;
	for (int i = 0; i < 28; i++)
	{
		if (i != 7 && i != 17 && i != 21 && i != 24 && i != 34 && i != 37 && i != 42 && i != 53)
		{
			pc2[k] = h[i];
			k++;
		}
	}
	for (int i = 0; i < 28; i++)
	{
		if (i != 7 && i != 17 && i != 21 && i != 24 && i != 34 && i != 37 && i != 42 && i != 53)
		{
			pc2[k] = l[i];
			k++;
		}
	}
	return pc2;
}

void get_key_elements(int iteration, int* h, int* l)
{
	int sl = 0;
	if (iteration < 3 || iteration == 9 || iteration == 16) sl = 1;
	else sl = 2;

	int shH[28] = { 0 };
	int shL[28] = { 0 };

	for (int i = 27; i > -1; --i)
	{
		if (sl == 2 && i > 1 || sl == 1 && i > 0)
		{
			shH[i - sl] = h[i];
			shL[i - sl] = l[i];
		}
	}
}

void make_permutation(int initial_64[])
{
	int ip[64] = { 0 };
	int pc1[56] = { 0 };
	int h[28] = { 0 };
	int l[28] = { 0 };
	int* pIp = make_ip(initial_64);
	memcpy(ip, pIp, 256);
	int* pPc1 = make_pc1(ip);
	memcpy(pc1, pPc1, 224);
	split_pc1(pc1, h, l);


	int pc2_table[16][48] = { 0 };
	int* basePc2 = *pc2_table;

	int j = 0;
	for (int i = 1; i < 17; i++)
	{
		get_key_elements(i, h, l);
		int *pPc2 = get_pc2(h, l);

		int* curLoc = basePc2 + j;
		memcpy(curLoc, pPc2, 192);
		j += 48;
	}
	
}