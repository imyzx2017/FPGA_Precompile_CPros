#include<stdio.h>
#include<hls_math.h>

void crazyfunction(float x[100], float y, float res[100]);

int main()
{
	float x[100];
	float result[100];
	for(int i=0;i<100;i++)
	{
		x[i] = i;
	}
	crazyfunction(x, 0.01f, result);
	for(int j=0;j<100;j++)
		{
			printf("Result[%d]=%f\n", j, result[j]);
		}
	return 0;
}
