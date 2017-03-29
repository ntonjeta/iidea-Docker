
/******************************************************************************
 * @file   bluring.cpp
 * @author A. Tammaro
 * @date   12 dic 2016
 * @brief  A source file used to test simple mage manipulation filter with loop perforation
 ******************************************************************************/


#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>
#include "opencv/highgui.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

#define PIPI 3.14156

using namespace std;
using namespace cv;

/// Global Variables
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;
char window_name[] = "Filter Demo 1";


//define the kernel 
float Kernel[3][3] = {
                       {1/9.0, 1/9.0, 1/9.0},
                       {1/9.0, 1/9.0, 1/9.0},
                       {1/9.0, 1/9.0, 1/9.0}
                     };

void convolution (Mat dst,Mat src)
{
  int y,x,k,j;
  float sum;;

 
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
//@brief: Error function

extern "C" double IIDEAA_getError() {
  // Error count in number of bifferent pixel
  double error = 0;
  // Retrive the non approximate image blurring
  Mat noaprx = imread("noaprx.jpg",0);
  // Retrive the original image
  Mat src    = imread("lena.jpg");
  // Apply filter with apprx
  Mat aprx;
  convolution(aprx,src);
  // Compute the difference 
  Mat diffImage;
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
  Mat dst;
  namedWindow( window_name, CV_WINDOW_AUTOSIZE );
  
  if ( argc != 2 )
  {
     cout<<"usage: DisplayImage.out <Image_Path>\n";
      return -1;
  }
  Mat src = imread(argv[1],0);
  if( !src.data ){ return -1; }
  dst = src.clone();

  // for index 
  int y;
  int x;
  
  for(y = 0; y < src.rows; y++)
    for(x = 0; x < src.cols; x++)
      dst.at<uchar>(y,x) = 0.0;
  
  convolution(dst,src);

  namedWindow("initial");
  imshow("initial", src);
  waitKey(0);
  //imwrite("noaprx.jpg",dst);
  namedWindow("final");
  imshow("final", dst);
  waitKey(0);
  double a = IIDEAA_getError(); 
  cout<<"Error: "<< a <<endl;
  return 0;

}
