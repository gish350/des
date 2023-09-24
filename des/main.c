#include <stdio.h>
#include "feistel.h"
#include "permutation.h"
int main()
{
	//char input[8] = {0};
	//
	//gets(input);

	//cipher(100, 200);
	//uncipher(99, 203);

	int initial[64] = { 0 };
	for (int i = 0; i < 64; i++)
	{
		initial[i] = i + 1;
	}

	int initital_arr[64] = { 0 };
	int ip[64] = { 0 };
	int pc1[56] = { 0 };
	int* pIp = make_ip(initial);
	memcpy(ip, pIp, 256);
	int* pPc1 = make_pc1(ip);
	memcpy(pc1, pPc1, 224);
	return 0;
}