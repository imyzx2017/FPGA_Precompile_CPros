#include "HH_header.h"
#include <stdio.h>

int main()
{
	float I[steps];
	for(int idx=0;idx<steps;idx++)
	{
		I[idx] = 10.0f;
	}
	float steptime = 0.01f;
	float V_result[steps] = {0.0f};
	HH_Test(I, steptime, V_result);
	for(int i=0;i<int(steps);i++)
	{
		printf("%f\n", V_result[i]);
	}
}

