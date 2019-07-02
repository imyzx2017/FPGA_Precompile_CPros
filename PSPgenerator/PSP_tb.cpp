#include<iostream>
#include "PSPgenerator.h"

using namespace std;


int main()
{
	float w = 1.0;
	float spike_time = 5.0;
	float result[1] = { 0.0 };
	float Ref_result = 1.0*(exp(-5.0 / 4.0) - exp(-5.0 / 2.0));
	PSP(w, spike_time, result);
	cout << result[0] <<","<<Ref_result<< endl;
	if (result[0] == Ref_result)
	{
		cout << "Test Pass" << endl;
	}
	else
	{
		cout << "Test failed" << endl;
	}
}
