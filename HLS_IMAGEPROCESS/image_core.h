#ifndef _IMAGE_CORE_H_
#define _IMAGE_CORE_H_

#include"hls_video.h" //调用可以综合的视频库

//图像最大尺寸
#define MAX_WIDTH 800
#define MAX_HEIGHT 600

//定义图像处理核，要用到的结构体
typedef hls::stream<ap_axiu<24,1,1,1> > AXI_STREAM_IN;
typedef hls::stream<ap_axiu<24,1,1,1> > AXI_STREAM_OUT;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC3> RGB_IMAGE;

//硬件综合的顶层
void image_core(AXI_STREAM_IN& src_axi, AXI_STREAM_OUT& dst_axi, int rows, int cols);

#endif
