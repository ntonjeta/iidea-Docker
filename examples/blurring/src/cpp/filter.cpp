/******************************************************************************
 * @file   test.cpp
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

using namespace std;
using namespace cv;

int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;

Mat src; Mat dst;
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

  /// Load the source image
  src = imread( "./lena.jpg", 1 );

  if( display_caption( "Original Image" ) != 0 ) { return 0; }

  dst = src.clone();
  if( display_dst( DELAY_CAPTION ) != 0 ) { return 0; }

  /// Applying Homogeneous blur

  if( display_caption( "Homogeneous Blur" ) != 0 ) { return 0; }

  for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 ){
    blur( src, dst, Size( i, i ), Point(-1,-1) );
    if( display_dst( DELAY_BLUR ) != 0 ) { return 0; }
  }
  /// Applying Gaussian blur
  if( display_caption( "Gaussian Blur" ) != 0 ) { return 0; }

  for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 ){
    GaussianBlur( src, dst, Size( i, i ), 0, 0 );
    if( display_dst( DELAY_BLUR ) != 0 ) { return 0; } 
  }

  /// Applying Median blur
  if( display_caption( "Median Blur" ) != 0 ) { return 0; }

  for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 ){
    medianBlur ( src, dst, i );
    if( display_dst( DELAY_BLUR ) != 0 ) { return 0; } 
  }

  /// Applying Bilateral Filter
  if( display_caption( "Bilateral Blur" ) != 0 ) { return 0; }
    
  for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 ){
    bilateralFilter ( src, dst, i, i*2, i/2 );
    if( display_dst( DELAY_BLUR ) != 0 ) { return 0; } 
  }

  /// Wait until user press a key
  display_caption( "End: Press a key!" );
    
  waitKey(0);
  return 0;
  
  //if ( argc != 2 )
  //{
      //printf("usage: DisplayImage.out <Image_Path>\n");
      //return -1;
  //}
  //Mat imgC = imread(argv[1],1);
  ////Mat img = imread("lena.jpg",0);//loading gray scale image
  ////Mat imgC = imread("lena.jpg",1);//loading color image
  ////namedWindow("Image", WINDOW_AUTOSIZE );
  ////imshow("Image",imgC);
////  waitKey(0);
  //Mat rotC(imgC.cols, imgC.rows, imgC.type());
  //rotC = Scalar(0,0,0);

  //namedWindow("Image", WINDOW_AUTOSIZE );
  //imshow("Image",imgC);
  //waitKey(0);
  ////Mat rotG(img.cols, img.rows, i
  ////mg.type());
  ////rotG = Scalar(0,0,0);

  //float angle = 90.0 * PIPI / 180.0;

  //for(int r=0;r<imgC.rows;r++)
  //{
    //for(int c=0;c<imgC.cols;c++)
    //{
      //float new_px = c * cos(angle) - r * sin(angle);
      //float new_py = c * sin(angle) + r * cos(angle);
      //Point pt((int)-new_px, (int)new_py);
      ////color image
      ////assign color value at new location from original image
      //rotC.at<Vec3b>(pt) = imgC.at<Vec3b>(r,c);
      ////gray scale image 
      ////rotG.at<uchar>(pt) = img.at<uchar>(r,c);      
    //}
  //}
  //namedWindow("Rotate", WINDOW_AUTOSIZE );
  //imshow("Rotate",rotC);
  ////imshow("gray",rotG);
  //waitKey(0);
         
  //return 0;
}

int display_caption( char* caption )
{
  dst = Mat::zeros( src.size(), src.type() );
  putText( dst, caption,
          Point( src.cols/4, src.rows/2),
          CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

  imshow( window_name, dst );
  int c = waitKey( DELAY_CAPTION );
  if( c >= 0 ) { return -1; }
  return 0;
}

int display_dst( int delay )
{
  imshow( window_name, dst );
  int c = waitKey ( delay );
  if( c >= 0 ) { return -1; }
  return 0;
}
