


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

void permutate(char pc1[])
{
	char pc_56[] = { 56 };


	int i = 0;
	int	j = 0;

	while (i < 64)
	{
		if ((i % 8) != 0)
		{
			pc_56[j] = pc1[i];
			j++;
		}
		i++;
	}

	for (i = 0; i < 28; i++)
	{
		pc_56[i] << 1;
	}


}