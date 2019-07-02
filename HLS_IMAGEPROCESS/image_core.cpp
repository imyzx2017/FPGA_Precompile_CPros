#include "image_core.h"

void image_core(AXI_STREAM_IN& input, AXI_STREAM_OUT& output, int rows, int cols){
    #pragma HLS RESOURCE variable=input core=AXI4Stream metadata="-bus_bundle INPUT_STREAM"
    #pragma HLS RESOURCE variable=output core=AXI4Stream metadata="-bus_bundle OUTPUT_STREAM"
    #pragma HLS INTERFACE ap_none port=cols
    #pragma HLS INTERFACE ap_none port=rows
    #pragma HLS interface ap_ctrl_none port=return

    RGB_IMAGE img_0(rows, cols);
    RGB_IMAGE img_1(rows, cols);
    #pragma HLS DATAFLOW              // must use data flow to stream the data
    hls::AXIvideo2Mat(input, img_0);  //读输入到img_0
    hls::Sobel<1,0,3>(img_0, img_1);  //Sobel算子，边缘提取
    hls::Mat2AXIvideo(img_1, output); //img_1写到输出
}
