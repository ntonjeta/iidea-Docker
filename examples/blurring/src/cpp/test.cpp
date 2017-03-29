
/******************************************************************************
 * @file   bluring.cpp
 * @author A. Tammaro
 * @date   12 dic 2016
 * @brief  A source file used to test simple mage manipulation filter with loop perforation
 ******************************************************************************/


#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;

int stride4 = 2;
int stride3 = 4;
int stride2 = 2;
int stride1 = 2;
void convolution (cv::Mat dst,cv::Mat src)
{
  int y,x,k,j;
  float sum;;

  //define the kernel 
  float Kernel[3][3] = {
                         {1/9.0, 1/9.0, 1/9.0},
                         {1/9.0, 1/9.0, 1/9.0},
                         {1/9.0, 1/9.0, 1/9.0}
                       };
  //convolution operation 
  for(y = 1; y < src.rows - 1; y = y + stride1){
    for(x = 1; x < src.cols - 1; x = x + stride2){
      sum = 0.0;
      for(k = -1; k <= 1;k = k + stride3){
        for(j = -1; j <=1; j = j + stride4){
          sum = sum + Kernel[j+1][k+1]*src.at<uchar>(y - j, x - k);
        }
      }
      dst.at<uchar>(y,x) = sum;
    }
  }
}
//@brief: Error function

extern "C" double IIDEAA_getError() {
  // Error count in number of bifferent pixel
  double error = 0;
  // Retrive the non approximate image blurring
  cv::Mat noaprx = cv::imread("noaprx.jpg",0);
  // Retrive the original image
  cv::Mat src    = cv::imread("lena.jpg",0);
  // Apply filter with apprx
  cv::Mat aprx(src.rows,src.cols,0);
  convolution(aprx,src);
  // Compute the difference 
  cv::Mat diffImage;
  absdiff(noaprx,aprx, diffImage);
  // Apply threshold
  cv::Mat foregroundMask = cv::Mat::zeros(diffImage.rows, diffImage.cols, CV_8UC1);

  float threshold = 30.0f;
  float dist;

  for(int j=0; j<diffImage.rows; ++j)
    for(int i=0; i<diffImage.cols; ++i)
    {
        uchar pix = diffImage.at<uchar>(j,i);

        dist = (pix*pix);
        dist = sqrt(dist);

        if(dist>threshold)
        {
          foregroundMask.at<unsigned char>(j,i) = 255;
          error++;  
        }
    }
  return error;
}



int main(int argc, char **argv)
{
  double a = IIDEAA_getError();
  ::std::cout<<" Error: "<< a << "\n"; 
  return 0;
}
