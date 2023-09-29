#include <stdio.h>
#include <windows.h>
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
	for (int i = 0; i < 32; i++)
	{
		initial[i] = 1;
	}
	for (int i = 32; i < 64; i++)
	{
		initial[i] = 0;
	}
	

	/*int initital_arr[64] = { 0 };
	int ip[64] = { 0 };
	int pc1[56] = { 0 };
	int* pIp = make_ip(initial);
	memcpy(ip, pIp, 256);
	int* pPc1 = make_pc1(ip);
	memcpy(pc1, pPc1, 224);

	int* outH = GlobalAlloc(0x0000 | 0x0040, 112);
	int* outL = GlobalAlloc(0x0000 | 0x0040, 112);
	split_pc1(pc1, outH, outL);*/
	make_permutation(initial);
	return 0;
}