/******************************************************************************
 * @file   test.cpp
 * @author Antonio Tammaro
 * @date   15 nov 2016
 * @brief  A source file used to test Loop Perforation Operator
 ******************************************************************************/

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#include <sched.h>

#define max(a,b) (((a)>(b))?(a):(b))

/// \brief Returns something
/// @param a
/// @param b
/// \param n
/// @return


std::chrono::time_point<std::chrono::system_clock> start, end;

float pow_custom(float x, int n);
int stride1 = 1;
float taylor_log(float x, int points) {
  float val = 0.0;
  int i;
  for(i=1; i<=points; i = i + stride1)
	val += pow(-1, i-1)/i*pow_custom(x, i);
  return val;
}

int stride2 = 1;
float pow_custom(float x, int n){
 float r = (n==0 ? 0 : 1);
 int i;
 for(i=0; i<n; i = i + stride2){
   r*=x;
 }
return r;
}

extern "C" double IIDEAA_getTime() {
  start = std::chrono::system_clock::now();
  max(fabs(0.182321563363075 - taylor_log(0.2, 100)), fabs(0.641853749752045 - taylor_log(0.9, 200)));
  end = std::chrono::system_clock::now();
  //std::chrono::duration<microseconds> elapsed = end-start;
  std::chrono::nanoseconds elapsed = end-start;
  return elapsed.count();  
}
extern "C" double IIDEAA_getError() {
  return max(fabs(0.182321563363075 - taylor_log(0.2, 100)), fabs(0.641853749752045 - taylor_log(0.9, 200)));
}

int main(int argc, char **argv) {
struct sched_param schedp;
  schedp.sched_priority = 1;
  sched_setscheduler(0, SCHED_FIFO, &schedp);
  ::std::cout << "Result: " << taylor_log(0.2, 100) <<" " <<taylor_log(0.9, 200)
              << "\n"; // 332.002685546875

  IIDEAA_getError();
  ::std::cout << "Time: "<< IIDEAA_getTime()<<"\n";
  return 0;
}
