#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "../src/rgbimage.h"
#include "../src/segmentation.h"
#include "../src/distance.h"
//paths to the input image and output of approximate version

// BELLEROPHON FUNCTION

char golden_image_path[] = "/home/ntonjeta/Approximate/examples/kmeans/images/original.rgb";
char noaprx_image_path[] = "/home/ntonjeta/Approximate/examples/kmeans/images/noaprx.rgb";


double eDistance(RgbPixel p, RgbPixel q) {
  float r;

  r = 0;
  double r_tmp;
  
  r += (p.r - q.r) * (p.r - q.r);
  r += (p.g - q.g) * (p.g - q.g);
  r += (p.b - q.b) * (p.b - q.b);

  r_tmp = sqrt(r);

  return r_tmp;
}


extern "C" double BELLERO_getError() {
   double error = 0;
  RgbImage noaprx;
  RgbImage srcImage;
  Clusters clusters;
  // Read no approximated image
  initRgbImage(&noaprx);
  loadRgbImage(noaprx_image_path, &noaprx,256);
  // Read Golden image 
  initRgbImage(&srcImage);
  loadRgbImage(golden_image_path, &srcImage,256);
  // Apply kmeans with aprx code
  initClusters(&clusters, 6, 1);
  segmentImage(&srcImage, &clusters, 1);
  
  // Calculate MSE 
  int i,j;
  double d = 0;

  int w = srcImage.w;
  int h = srcImage.h;

  for(i = 0; i<w; i++) {
    for( j = 0; j<h; j++){
      d += eDistance(srcImage.pixels[i][j],noaprx.pixels[i][j]);
    }
  }
 
  return d/(h*w);
}
