#include<stdio.h>
#include<math.h>
#include "test_core.h"

int main()
{
	printf("Testing gravity for mass m1=10 m2=20 \n");
	float errorAcc = 0;
	for(int idx = 0; idx<10; idx++)
	{
		float force = gravity(10, 20, idx);

		float errorCalc = fabsf(force - goldRef[idx]);
		errorAcc += errorCalc;

		if(errorAcc > 1)
		{
			printf("Test Failed!\n");
			return 1;
		}
	}
	printf("Test Pass!\n");
	return 0;
}
