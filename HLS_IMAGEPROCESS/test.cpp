#include "image_core.h"
#include "opencv/cv.h"
#include "opencv/cxcore.h"
#include "opencv/highgui.h"
#include "hls_opencv.h"
#define INPUT_IMAGE "brain.jpg"

int main (int argc, char** argv) {
    IplImage* src = cvLoadImage(INPUT_IMAGE,0);//读图片灰度
    IplImage* dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
    AXI_STREAM_IN  src_axi;
    AXI_STREAM_OUT dst_axi;
    IplImage2AXIvideo(src, src_axi); //将图像转为数据流
    image_core(src_axi, dst_axi, src->height, src->width);//输入数据流，进行处理，输出数据流
    AXIvideo2IplImage(dst_axi, dst); //将输出流转回图片
    cvShowImage("src",src);
    cvShowImage("dst",dst);
    cvWaitKey(0);
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    return 0;
}
