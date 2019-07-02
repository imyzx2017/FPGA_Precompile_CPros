#include "image_core.h"
#include "opencv/cv.h"
#include "opencv/cxcore.h"
#include "opencv/highgui.h"
#include "hls_opencv.h"
#define INPUT_IMAGE "brain.jpg"

int main (int argc, char** argv) {
    IplImage* src = cvLoadImage(INPUT_IMAGE,0);//��ͼƬ�Ҷ�
    IplImage* dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
    AXI_STREAM_IN  src_axi;
    AXI_STREAM_OUT dst_axi;
    IplImage2AXIvideo(src, src_axi); //��ͼ��תΪ������
    image_core(src_axi, dst_axi, src->height, src->width);//���������������д������������
    AXIvideo2IplImage(dst_axi, dst); //�������ת��ͼƬ
    cvShowImage("src",src);
    cvShowImage("dst",dst);
    cvWaitKey(0);
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    return 0;
}
