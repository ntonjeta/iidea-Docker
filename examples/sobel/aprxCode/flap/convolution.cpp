/*
 * convolution.cpp
 * 
 * Created on: Sep 9, 2013
 * 			Author: Amir Yazdanbakhsh <a.yazdanbakhsh@gatech.edu>
 */

#include "convolution.hpp"
#include <cmath>
#include "fap.h"

int total = 0;
static float kx[][3] =
{
  { -1, -2, -1 },
  {  0,  0,  0 },
  {  1,  2,  1 }
} ;

static float ky[][3] =
{
  { -1, 0, 1 },
  { -2, 0, 2 },
  { -1, 0, 1 }
} ;

::fap::FloatPrecTy OP_1(8,8);
::fap::FloatPrecTy OP_0(8,6);
float convolve(float w[][3], float k[][3])
{
  float r ;
  r = 0.0 ;
  int j,i;
  for(j = 0 ; j < 3 ; j++ )
    for (i = 0 ; i < 3 ; i++ ) {
      r = (float)(::fap::FloatingPointType((float) r, OP_0)) + (float)(::fap::FloatingPointType((float) w[i][j], OP_1)) * (float)(::fap::FloatingPointType((float) k[j][i], OP_1)) ;
    }
  return r ;
}

::fap::FloatPrecTy OP_5(11,40);
::fap::FloatPrecTy OP_4(8,5);
::fap::FloatPrecTy OP_3(8,6);
::fap::FloatPrecTy OP_2(8,3);
float sobel(float w[][3])
{
  float sx ;
  float sy ;
  float s  ;

  float dataIn[9];

  dataIn[0] = w[0][0];
  dataIn[1] = w[0][1];
  dataIn[2] = w[0][2];
  dataIn[3] = w[1][0];
  dataIn[4] = w[1][1];
  dataIn[5] = w[1][2];
  dataIn[6] = w[2][0];
  dataIn[7] = w[2][1];
  dataIn[8] = w[2][2];

  //for(int i = 0 ; i < 3 ; i++)
    //for(int j = 0 ; j < 3 ; j++)
      //if(DEBUG) std::cout << "w_ " << i << j << ": " << w[i][j] << std::endl;

  sx = convolve(w, ky) ;

  //if(DEBUG) std::cout << "sx: " << sx << std::endl ;

  sy = convolve(w, kx) ;

  //if(DEBUG) std::cout << "sy: " << sy << std::endl ;

  s = (float)(::fap::FloatingPointType((float) (float)(::fap::FloatingPointType((float) sx, OP_3)) * (float)(::fap::FloatingPointType((float) sx, OP_2)), OP_3)) + (float)(::fap::FloatingPointType((float) (float)(::fap::FloatingPointType((float) sy, OP_4)) * (float)(::fap::FloatingPointType((float) sy, OP_2)), OP_4)) ;
  s =  sqrt(s);

  if (s >= (256 / sqrt(256 * 256 + 256 * 256)))
    s = (double)(::fap::FloatingPointType((double) 255, OP_5)) / (double)(::fap::FloatingPointType((double) sqrt(256 * 256 + 256 * 256), OP_5));

  return s ;
}

// BELLEROPHON FUNCTION

//char src_image_path[] = "/home/ntonjeta/Approximate/examples/sobel/image/original.rgb";
//char noaprx_image_path[] = "/home/ntonjeta/Approximate/examples/sobel/image/noaprx.rgb";
//char dst_image_path[] = "/home/ntonjeta/Approximate/examples/sobel/image/dst.rgb";


//double eDistance(boost::shared_ptr<Pixel> p, boost::shared_ptr<Pixel> q) {
  //float r;

  //r = 0;
  //double r_tmp;
  
  //r += (p->r - q->r) * (p->r - q->r);
  //r += (p->g - q->g) * (p->g - q->g);
  //r += (p->b - q->b) * (p->b - q->b);

  //r_tmp = sqrt(r);

  //return r_tmp;
//}


//extern "C" double BELLERO_getError() {
  //int x, y;
  //float s = 0;

  //// Source and destination image	
  //boost::shared_ptr<Image> srcImagePtr(new Image());
  //boost::shared_ptr<Image> dstImagePtr(new Image());

  //float w[][3] = {
    //{0, 0, 0},
    //{0, 0, 0},
    //{0, 0, 0}
  //};

  //srcImagePtr->loadRgbImage(src_image_path); // source image
  //dstImagePtr->loadRgbImage(dst_image_path); // destination image

  //srcImagePtr->makeGrayscale( ); // convert the source file to grayscale

  //y = 0 ;
  
  //// Apply sobel filter
  //// Start performing Sobel operation
  //for( x = 0 ; x < srcImagePtr->width ; x++ ) {
    //HALF_WINDOW(srcImagePtr, x, y, w) ;
    
    //s = sobel(w);

    //dstImagePtr->pixels[y][x]->r = s ;
    //dstImagePtr->pixels[y][x]->g = s ;
    //dstImagePtr->pixels[y][x]->b = s ;
  //}

  //for (y = 1 ; y < (srcImagePtr->height - 1) ; y++) {
    //x = 0 ;
    //HALF_WINDOW(srcImagePtr, x, y, w);

    //s = sobel(w);
      
    //dstImagePtr->pixels[y][x]->r = s ;
    //dstImagePtr->pixels[y][x]->g = s ;
    //dstImagePtr->pixels[y][x]->b = s ;

    //for( x = 1 ; x < srcImagePtr->width - 1 ; x++ ) {
      //WINDOW(srcImagePtr, x, y, w) ;
              
      //s = sobel(w);

      //dstImagePtr->pixels[y][x]->r = s ;
      //dstImagePtr->pixels[y][x]->g = s ;
      //dstImagePtr->pixels[y][x]->b = s ;

    //}

    //x = srcImagePtr->width - 1 ;
    //HALF_WINDOW(srcImagePtr, x, y, w) ;
              

    //s = sobel(w);

    //dstImagePtr->pixels[y][x]->r = s ;
    //dstImagePtr->pixels[y][x]->g = s ;
    //dstImagePtr->pixels[y][x]->b = s ;
  //}

  //y = srcImagePtr->height - 1;

  //for(x = 0 ; x < srcImagePtr->width ; x++) {
    //HALF_WINDOW(srcImagePtr, x, y, w) ;
            
    //s = sobel(w);

    //dstImagePtr->pixels[y][x]->r = s ;
    //dstImagePtr->pixels[y][x]->g = s ;
    //dstImagePtr->pixels[y][x]->b = s ;

  //}

  ////dstImagePtr->saveRgbImage("./dst.rgb", std::sqrt(256 * 256 + 256 * 256)) ;


  //// Open Golden Image and compute MSE
  //boost::shared_ptr<Image> noaprxPtr(new Image());
  //noaprxPtr->loadRgbImage(noaprx_image_path); // source image
  //dstImagePtr->makeGrayscale( ); // convert the source file to grayscale

  //// Calculate MSE 
  //int i,j;
  //double d = 0;
  
  //int wi = srcImagePtr->width;
  //int he = srcImagePtr->height;

  //for(i = 0; i<wi; i++) {
    //for( j = 0; j<he; j++){
      //d += eDistance(dstImagePtr->pixels[i][j],noaprxPtr->pixels[i][j]);
    //}
  //}
 
  //return d/(he*wi);
//}


////extern "C" double BELLERO_Reward()
////{
  ////double rew = 0;
  
//////  MantType mant;
  ////int grade[6];
  
  ////grade[0] = 23 - OP_0.mant_size;
  ////grade[1] = 23 - OP_1.mant_size;
  ////grade[2] = 23 - OP_2.mant_size;
  ////grade[3] = 23 - OP_3.mant_size;
  ////grade[4] = 23 - OP_4.mant_size;
  ////grade[5] = 23 - OP_5.mant_size;
 
  ////rew = [(2*grade[0]) + (2*grade[1]) + (2*grade[1])] + [ (2* grade[3] * grade[3] ) + (2* grade[4] * grade[4] ) + (2* grade[5] * grade[5])];
//////  FloatPrecTy prec = OP_1.getPrec();  
 
//////  cout << prec.mant_size; 

  ////return rew;
////}
