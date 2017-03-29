/******************************************************************************
 * @file   test.cpp
 * @author Mario Barbareschi
 * @date   09 apr 2016
 * @brief  A source file used to test FLAP Operator
 ******************************************************************************/

#include <iostream>
#include <math.h>

/// \brief Returns something
/// @param a
/// @param b
/// \param n
/// @return
int stride1 = 1;
float cavalieri_simpson(float (*func)(float), float a, float b, int n) {
  float p = 0;
  float h = (b-a)/n;
  p = func(a)+func(b);
  for (int i = 1; i < n-1; i = i + stride1) {
    p += 4*func(a+i*h);
    p +=2*func(a+(i+1)*h);
  }
  return p/3*h;
}

static float a = 0;
static float b = 1;
static int n = 100;

float funct(float x){
	return sqrt(1+9/4*x);
}

extern "C" double IIDEAA_getError() {
  double golden = 10086.7333984375;
  return fabs(golden - cavalieri_simpson(funct, a, b, n));
}

int main(int argc, char **argv) {
  return 0;
}
