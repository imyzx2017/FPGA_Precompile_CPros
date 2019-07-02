//float v0 = -65.0f;
//float dt;
//float m0 = 0.0f; // 0.1*(v0+40)/(1 - exp(-(v0 + 40) / 10));
//float h0 = 0.0f;
//float n0 = 0.0f; //0.01*(v0+55)/(1-exp(-(v0+55)/10));
//float E_Na = 120.0f;
//float E_K = 36.0f;
//float E_L = -54.4f; //Cl的平衡电位 - 54.4mV
//float g_Na = 120.0f; //Na的电导120mS
//float g_K = 36.0f; //K的电导36mS
//float g_L = 0.3f; //Cl的电导0.3mS
//float alpha_m;
//float beta_m;
//float alpha_h;
//float beta_h;
//float alpha_n;
//float beta_n;
//float delta_m;
//float delta_h;
//float delta_n;
//float delta_V;
#define steps 10000

void HH_Test(float I[steps], float steptime, float V_result[steps]);
