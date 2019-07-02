#include<math.h>
#include "HH_Header.h"
#include<stdio.h>

//float Neuron_parameters[10] = {-65.0, 0.2236, 0.0, 0.0582, 50.0, -77.0, -54.4, 120.0, 36.0, 0.3};

//void detect_spiketime(int current_t, float V_result[steps], int spike_time[spiketime_num])
//{
//	//int index = 0;
////	for (int i = 0; i < current_t; i++)
////	{
//	if ((current_t == 0) | (current_t==1) | (V_result[current_t] <=0 ));
//	else
//	{
//		if((V_result[current_t - 1] >= V_result[current_t - 2])&(V_result[current_t - 1] >= V_result[current_t]))
//		{
//			//printf("%d\n", (i - 1));
//			spike_time[index] = current_t-1;
//			index += 1;
//		}
//
//	}
////	}
//
//}


void sending_PSP(neuron &post_neuron, int stat, int t, int PreNeuron_spiketime[spiketime_num])  //加&号引用该类，不然会复制一个新类来执行这个函数，不会对目标类的属性进行改变
{
	int spikenum = 0;
	post_neuron.I_AMPA = 0.0f;
	for (int j = 0; j < spiketime_num; j++)
	{
		if (PreNeuron_spiketime[j] == 0);
		else
		{
			spikenum += 1;
		}
	}
	// sending EPSP
	if (stat == 0)
	{

		for (int i = 0; i < spikenum; i++)
		{
			//printf("%.5f\n", 0.08f * expf((float)(preneuron_spike_time[i] - t) / 200.0f);

			post_neuron.I_AMPA += 0.08f * expf((float)(PreNeuron_spiketime[i] - t) / 200.0f) * (0.0f - post_neuron.current_V);
			//printf("%.5f\n", post_neuron.I_AMPA);
		}
		//printf("%.5f\n", post_neuron.I_AMPA);
	}
	else if(stat == 1)
	{
		for (int i = 0; i < spikenum; i++)
		{
			post_neuron.I_NMDA = post_neuron.I_NMDA + 0.1f * (float)(t - PreNeuron_spiketime[i]) / 500.0f * expf(-(float)(t - PreNeuron_spiketime[i]) / 500.0f) * (1.0f / (1.0f + 0.28f * expf(-0.062 * post_neuron.current_V)));

		}
	}
	else
	{
		for (int i = 0; i < spikenum; i++)
		{
			post_neuron.I_AMPA = post_neuron.I_AMPA + 0.8f * expf(-(float)(t - PreNeuron_spiketime[i]) / 200.0f);
			post_neuron.I_NMDA = post_neuron.I_NMDA + 0.1f * (float)(t - PreNeuron_spiketime[i]) / 500.0f * expf(-(float)(t - PreNeuron_spiketime[i]) / 500.0f) * (1.0f / (1.0f + 0.28f * expf(-0.062 * post_neuron.current_V)));
		}
	}
}


int PreNeuron_spiketime[spiketime_num] = {0};
int index=0;
void HH_SynTest(float I1, float I2, float steptime, float neuron1_V_result[steps], float neuron2_V_result[steps])
{

#pragma HLS INTERFACE bram port=neuron1_V_result
#pragma HLS INTERFACE bram port=neuron2_V_result
//#pragma HLS INTERFACE bram port=spike_time
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=steptime bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=I2 bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=I1 bundle=CRTL_BUS

	//#pragma HLS INTERFACE bram port=PSP
	//#pragma HLS INTERFACE bram port=V_result
	//#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
	//#pragma HLS INTERFACE s_axilite port=steptime bundle=CRTL_BUS
	//#pragma HLS INTERFACE bram port=I
	//int spike_time[num_neurons][spiketime_num] = {0};
	neuron neuron1;
	neuron neuron2;



	for (int idx = 0; idx<steps; idx++)
	{

		//		V_result[0][idx] = neuron1.updating(I1, steptime);
		//		V_result[1][idx] = neuron2.updating(I2, steptime);

		neuron1_V_result[idx] = neuron1.updating(I1, steptime);
		neuron2_V_result[idx] = neuron2.updating(I2, steptime);
		//int temp = 0;
		if ((idx == 0) | (idx==1) | (neuron1_V_result[idx] <=0 ));
		else
		{

			//PreNeuron_spiketime[index] = (neuron1_V_result[idx - 1] >= neuron1_V_result[idx - 2])&(neuron1_V_result[idx - 1] >= neuron1_V_result[idx])*(idx - 1);
//			index +=1*(neuron1_V_result[idx - 1] >= neuron1_V_result[idx - 2])&(neuron1_V_result[idx - 1] >= neuron1_V_result[idx]);
			if((neuron1_V_result[idx - 1] >= neuron1_V_result[idx - 2])&(neuron1_V_result[idx - 1] >= neuron1_V_result[idx]))
			{
//				//printf("%d\n", (i - 1));
				PreNeuron_spiketime[index] = idx-1;
				index +=1;
//				int temp=0;
			}
			else;

			//PreNeuron_spiketime[index - 1] = temp;
//			index+=1;
		}

		//detect_spiketime(idx, neuron1_V_result, PreNeuron_spiketime);
		//detect_spiketime(neuron2_V_result, spike_time[1]);

		//sending_PSP(neuron1, neuron2, 0, idx);

		sending_PSP(neuron2, 0, idx, PreNeuron_spiketime);
		//printf("%.5f\n", neuron2.I_AMPA);
		//printf("%.5f\n", V_result[0][idx]);
	}

	for (int k=0;k<spiketime_num;k++)
	{
		printf("%d\n", PreNeuron_spiketime[k]);
	}

//	int spikenum = 0;
//	for (int j = 0; j < spiketime_num; j++)
//	{
//		if (spike_time[0][j] == 0);
//		else
//		{
//			spikenum += 1;
//			printf("%d\n", spike_time[0][j]);
//		}
//	}


}




