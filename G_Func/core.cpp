float gravity(float m1, float m2, float dist)
{
#pragma HLS INTERFACE s_axilite port=dist bundle=CRTLS
#pragma HLS INTERFACE s_axilite port=m2 bundle=CRTLS
#pragma HLS INTERFACE s_axilite port=m1 bundle=CRTLS
#pragma HLS INTERFACE s_axilite port=return bundle=CRTLS
	float force = 0;
	float distSquare = 0;
	if(dist==0)
	{
		distSquare = 0.000001f;
	}
	else distSquare = (dist*dist);

	force = 10.0f*(m1*m2)/distSquare;
	return force;
}
