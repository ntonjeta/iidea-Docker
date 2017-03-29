/******************************************************************************
 * @file   rotate.cpp
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
Mat src;
char window_name[] = "Filter Demo 1";

//TODO progetta la funzione di errore.
//bisogna calcolare la differenza tra due immagini e dargli una stima numerica
//idea 1 bassarsi sul numero di punti che escono fuori come differenza
//idea 2 a occhio umano
//idea 3 differenza dall'istogramma ma non so quanto è valido

//extern "C" double IIDEAA_getError() {
  //double golden = 3690.56518554688;
  //return fabs(golden - somma(a, b, n));
//}


//TODO scrivere un semplice filtro da testare

// Function headers
int display_caption( char* caption );
int display_dst( int delay );

int main(int argc, char **argv) {

  namedWindow( window_name, CV_WINDOW_AUTOSIZE );
  if ( argc != 2 )
  {
     cout<<"usage: DisplayImage.out <Image_Path>\n";
      return -1;
  }
  Mat src = imread(argv[1],1);
  namedWindow("Image", WINDOW_AUTOSIZE );
  imshow("Image",src);
  waitKey(0);
  Mat dst(src.rows, src.cols, src.type());
  dst = Scalar(0,0,0);
  
  float angle = 90.0 * PIPI / 180.0;

  for(int r=0;r<src.rows;r++)
  {
    for(int c=0;c<src.cols;c++)
    {
      float new_px = c * cos(angle) - r * sin(angle);
      float new_py = c * sin(angle) + r * cos(angle);
      Point pt((int)-new_px, (int)new_py);
      //color image
      //assign color value at new location from original image
      dst.at<Vec3b>(pt) = src.at<Vec3b>(r,c);
      //gray scale image 
      //rotG.at<uchar>(pt) = img.at<uchar>(r,c);      
    }
  }

  namedWindow("Rotate", WINDOW_AUTOSIZE );
  imshow("Rotate",dst);
  ////imshow("gray",rotG);
  waitKey(0);
  return 0;
}
