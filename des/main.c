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

	int new_arr[64] = { 0 };
	new_arr[0] = make_ip(initial);
	
	return 0;
}