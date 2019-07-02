#include<iostream>
#include<cmath>
#include "PSPgenerator.h"



void PSP(float w, float spike_time, float result[1])
{
	result[0] = w * (exp(-spike_time/4.0) - exp(-spike_time/2.0));
}

