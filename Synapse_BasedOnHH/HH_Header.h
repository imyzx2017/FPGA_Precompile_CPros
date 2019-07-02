#define num_neurons 2
#define steps 10000
#define spiketime_num 20
#include<math.h>

class neuron {
public:
	float v0 = -65.0f;
	//float dt;
	float m0 = 0.05f; // 0.1*(v0+40)/(1 - exp(-(v0 + 40) / 10));
	float h0 = 0.59f;
	float n0 = 0.31f; //0.01*(v0+55)/(1-exp(-(v0+55)/10));
	float E_Na = 50.0f;
	float E_K = -77.0f;
	float E_L = -54.4f; //Cl的平衡电位 - 54.4mV
	float g_Na = 120.0f; //Na的电导120mS
	float g_K = 36.0f; //K的电导36mS
	float g_L = 0.3f;
	float I_AMPA = 0.0f;
	float I_NMDA = 0.0f;

	float current_V = v0;
	float alpha_m;
	float beta_m;
	float alpha_h;
	float beta_h;
	float alpha_n;
	float beta_n;
	float delta_m;
	float delta_h;
	float delta_n;
	float delta_V;
	int spike_time[spiketime_num] = {0};


	float updating(float stimu_I, float steptime)
	{

		alpha_m = 0.1f * (current_V + 40.0f) / (1 - expf(-(current_V + 40.0f) / 10.0f));
		beta_m = 4.0f * expf(-(current_V + 65.0f) / 18.0f);
		alpha_h = 0.07f*expf(-(current_V + 65.0f) / 20.0f);
		beta_h = 1.0f / (expf(-(current_V + 35.0f) / 10.0f) + 1.0f);
		alpha_n = 0.01f*(current_V + 55.0f) / (1 - expf(-(current_V + 55.0f) / 10.0f));
		beta_n = 0.125f*expf(-(current_V + 65.0f) / 80.0f);

		delta_m = alpha_m*(1 - m0) - beta_m*m0;
		delta_h = alpha_h*(1 - h0) - beta_h*h0;
		delta_n = alpha_n*(1 - n0) - beta_n*n0;

		m0 = m0 + steptime*delta_m;
		h0 = h0 + steptime*delta_h;
		n0 = n0 + steptime*delta_n;
		delta_V = (-g_L*(current_V - E_L) - g_Na*m0*m0*m0*h0*(current_V - E_Na) - g_K*n0*n0*n0*n0*(current_V - E_K)) + stimu_I + I_AMPA + I_NMDA;
		current_V = current_V + delta_V*steptime;
		return current_V;

	}
};
//void HH_SynTest(float I1, float I2, float steptime, float V_result[num_neurons][steps]);
//void HH_SynTest(float I1, float I2, float steptime, int spike_time[num_neurons][spiketime_num], float V_result[num_neurons][steps]);
void HH_SynTest(float I1, float I2, float steptime, float neuron1_V_result[steps], float neuron2_V_result[steps]);
//void detect_spiketime(float V_result[steps], int spike_time[spiketime_num]);
//void sending_PSP(neuron &pre_neuron, neuron &post_neuron, int stat, int t);
