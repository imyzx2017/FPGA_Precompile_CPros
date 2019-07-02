#include <hls_math.h>
void crazyfunction(float x[100], float y, float res[100])
{
#pragma HLS INTERFACE bram port=res
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=y bundle=CRTL_BUS
#pragma HLS INTERFACE bram port=x


	for(int idx=0;idx<100;idx++)
	{
		res[idx] = (hls::sin(x[idx]) + hls::sqrtf(hls::expf(y)) ) / 2;
	}
}
