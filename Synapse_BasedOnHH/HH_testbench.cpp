#include "HH_header.h"
#include <stdio.h>

int main()
{
	float I1 = 10.0f;
	float I2 = 0.0f;
	float steptime = 0.01f;
	float neuron1_V_result[steps] = { 0.0f };
	float neuron2_V_result[steps] = { 0.0f };
//	int preNeuron_spiketime[spiketime_num] = {0};
//	int spike_time[num_neurons][spiketime_num] = { 0 };
//	HH_SynTest(I1, I2, steptime, spike_time, V_result);
	HH_SynTest(I1, I2, steptime, neuron1_V_result, neuron2_V_result);

//	for (int i = 0; i < steps; i++)
//	{
//		printf("%.5f\n", neuron2_V_result[i]);
//	}


}
