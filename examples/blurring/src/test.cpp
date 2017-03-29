
/******************************************************************************
 * @file   bluring.cpp
 * @author A. Tammaro
 * @date   12 dic 2016
 * @brief  A source file used to test simple mage manipulation filter with loop perforation
 ******************************************************************************/


#include <iostream>
#include <opencv2/opencv.hpp>
//#include <fap.h>
using namespace cv;

//double getMSE(std::vector<Pixel>*, std::vector<Pixel>*, int, int);

void convolution (cv::Mat dst,cv::Mat src)
{
  int y,x,k,j;
  float sum;;
 //define the kernel 
  float Kernel[6][6] = {
                         {1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0},
                         {1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0},
                         {1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0},
                         {1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0},
                         {1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0},
                         {1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0}
                       };

  //convolution operation 
  for(y = 1; y < src.rows - 1; y++){
    for(x = 1; x < src.cols - 1; x++){
      sum = 0.0;
      for(k = -1; k <= 1;k++){
        for(j = -1; j <=1; j++){
          sum = sum + Kernel[j+1][k+1]*src.at<uchar>(y - j, x - k);
        }
      }
      dst.at<uchar>(y,x) = sum;
    }
  }
}


double filter ()
{
  double error = 0;
  //Retrive the non approximate image blurring
   cv::Mat m1 = cv::imread("./noaprx.jpg",0);
  //  Retrive the original image
   cv::Mat src    = cv::imread("./lena.jpg",0);
  //  Apply "C"y filter with apprx
  cv::Mat m2(src.rows,src.cols,0);
  convolution(m2,src);
  
  int n = m1.rows;
  int m = m1.cols;

  int diff;
  double acc = 0;

  for(int j=0; j<n; ++j)
  { 
   for(int i=0; i<m; ++i)
    {
      //for(int k=0; k < 3; k++){
      u_char pix1 = m1.at<u_char>(i,j);//    (u_char) m1[3*(i*m+j)+k];
      u_char pix2 = m2.at<u_char>(i,j);//    (u_char) m2[3*(i*m+j)+k];
    
      diff = std::abs((int)(pix1-pix2));
      acc += (double) pow(diff, 2);
    }
  }
  return acc/(n*m);
}


extern "C" double BELLERO_getError() {
  // Error count in number of bifferent pixel
  return filter();
}

//@brief: Error function

extern "C" double IIDEAA_getError() {
  // Error count in number of bifferent pixel
  return filter();
}


extern "C" double IIDEAA_getTime() {
  double e =0;
  return e; 
}





int main(int argc, char **argv)
{
  cv::Mat src = cv::imread("./lena.jpg",0);
  //  Apply "C"y filter with apprx
  cv::Mat m2(src.rows,src.cols,0);
  convolution(m2,src);

  imwrite( "./aprx_Image.jpg", m2 );
  double a = IIDEAA_getError();
  ::std::cout<<" Error: "<< a << "\n"; 
  return 0;
}
