#ifndef _IMAGE_CORE_H_
#define _IMAGE_CORE_H_

#include"hls_video.h" //���ÿ����ۺϵ���Ƶ��

//ͼ�����ߴ�
#define MAX_WIDTH 800
#define MAX_HEIGHT 600

//����ͼ����ˣ�Ҫ�õ��Ľṹ��
typedef hls::stream<ap_axiu<24,1,1,1> > AXI_STREAM_IN;
typedef hls::stream<ap_axiu<24,1,1,1> > AXI_STREAM_OUT;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC3> RGB_IMAGE;

//Ӳ���ۺϵĶ���
void image_core(AXI_STREAM_IN& src_axi, AXI_STREAM_OUT& dst_axi, int rows, int cols);

#endif
