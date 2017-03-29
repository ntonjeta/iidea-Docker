#include <iostream>
#include <cmath>
#include "rgb_image.hpp"
#include "convolution.hpp"

// BELLEROPHON FUNCTION

char src_image_path[] = "/home/ntonjeta/Approximate/examples/sobel/image/original.rgb";
char noaprx_image_path[] = "/home/ntonjeta/Approximate/examples/sobel/image/noaprx.rgb";


double eDistance(boost::shared_ptr<Pixel> p, boost::shared_ptr<Pixel> q) {
  float r;

  r = 0;
  double r_tmp;
  
  r += (p->r - q->r) * (p->r - q->r);
  r += (p->g - q->g) * (p->g - q->g);
  r += (p->b - q->b) * (p->b - q->b);

  r_tmp = sqrt(r);

  return r_tmp;
}


extern "C" double BELLERO_getError() {
  int x, y;
  float s = 0;

  // Source and destination image	
  boost::shared_ptr<Image> srcImagePtr(new Image());
  boost::shared_ptr<Image> dstImagePtr(new Image());

  float w[][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };

  srcImagePtr->loadRgbImage(src_image_path); // source image
  dstImagePtr->loadRgbImage("./dst.rgb" ); // destination image

  srcImagePtr->makeGrayscale( ); // convert the source file to grayscale

  y = 0 ;
  
  // Apply sobel filter
  // Start performing Sobel operation
  for( x = 0 ; x < srcImagePtr->width ; x++ ) {
    HALF_WINDOW(srcImagePtr, x, y, w) ;
    
    s = sobel(w);

    dstImagePtr->pixels[y][x]->r = s ;
    dstImagePtr->pixels[y][x]->g = s ;
    dstImagePtr->pixels[y][x]->b = s ;
  }

  for (y = 1 ; y < (srcImagePtr->height - 1) ; y++) {
    x = 0 ;
    HALF_WINDOW(srcImagePtr, x, y, w);

    s = sobel(w);
      
    dstImagePtr->pixels[y][x]->r = s ;
    dstImagePtr->pixels[y][x]->g = s ;
    dstImagePtr->pixels[y][x]->b = s ;

    for( x = 1 ; x < srcImagePtr->width - 1 ; x++ ) {
      WINDOW(srcImagePtr, x, y, w) ;
              
      s = sobel(w);

      dstImagePtr->pixels[y][x]->r = s ;
      dstImagePtr->pixels[y][x]->g = s ;
      dstImagePtr->pixels[y][x]->b = s ;

    }

    x = srcImagePtr->width - 1 ;
    HALF_WINDOW(srcImagePtr, x, y, w) ;
              

    s = sobel(w);

    dstImagePtr->pixels[y][x]->r = s ;
    dstImagePtr->pixels[y][x]->g = s ;
    dstImagePtr->pixels[y][x]->b = s ;
  }

  y = srcImagePtr->height - 1;

  for(x = 0 ; x < srcImagePtr->width ; x++) {
    HALF_WINDOW(srcImagePtr, x, y, w) ;
            
    s = sobel(w);

    dstImagePtr->pixels[y][x]->r = s ;
    dstImagePtr->pixels[y][x]->g = s ;
    dstImagePtr->pixels[y][x]->b = s ;

  }

  //dstImagePtr->saveRgbImage("./dst.rgb", std::sqrt(256 * 256 + 256 * 256)) ;


  // Open Golden Image and compute MSE
  boost::shared_ptr<Image> noaprxPtr(new Image());
  noaprxPtr->loadRgbImage(noaprx_image_path); // source image
  noaprxPtr->makeGrayscale( ); // convert the source file to grayscale
  // Calculate MSE 
  int i,j;
  double d = 0;
  double error = 0;
  
  int wi = srcImagePtr->width;
  int he = srcImagePtr->height;

  for(i = 0; i<wi; i++) {
    for( j = 0; j<he; j++){
      d += eDistance(srcImagePtr->pixels[i][j],noaprxPtr->pixels[i][j]);
    }
  }
 
  return d/(he*wi);
}


//extern "C" double BELLERO_Reward()
//{
  //double rew = 0;
  
////  MantType mant;
  //int grade[6];
  
  //grade[0] = 23 - OP_0.mant_size;
  //grade[1] = 23 - OP_1.mant_size;
  //grade[2] = 23 - OP_2.mant_size;
  //grade[3] = 23 - OP_3.mant_size;
  //grade[4] = 23 - OP_4.mant_size;
  //grade[5] = 23 - OP_5.mant_size;
 
  //rew = [(2*grade[0]) + (2*grade[1]) + (2*grade[1])] + [ (2* grade[3] * grade[3] ) + (2* grade[4] * grade[4] ) + (2* grade[5] * grade[5])];
////  FloatPrecTy prec = OP_1.getPrec();  
 
////  cout << prec.mant_size; 

  //return rew;
//}
