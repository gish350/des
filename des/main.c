#include <stdio.h>
#include "feistel.h"
int main()
{
	char input[8] = {0};
	
	gets(input);

	cipher(100, 200);
	uncipher(99, 203);
	
	return 0;
}