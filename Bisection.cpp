//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <limits>
#include <stdlib.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself
#include <iostream>
using namespace std;


// Sample function for which you need to find the root

float f(const float x) {
  return x;
}

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

float absol(float x){
  if (x < 0){
    return -x;
  }
  else{
    return x;
  }
}

float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize, int counter);
float bisection(const float left, const float right,
		const float precision, const float minIntervalSize);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//
// include case for left/right being zero
float bisectionHelper(const float left, const float right, const float precision, const float minIntervalSize, int counter){
            if (left > right || left == right || precision <= 0 || precision >= 1 || minIntervalSize <= 0 || isNaN(f(left))|| isNaN(f(right))|| f(left)*f(right) > 0){
              return std::numeric_limits<float>::quiet_NaN();
            }
            if (f(left) == 0 || f(right) == 0){
              return 0;
            }

            float midpoint = left + (right - left )/ 2;
            if (absol(f(midpoint))<= precision || (absol(right - left) < minIntervalSize)){
              return midpoint;
            }
            if (counter == 1000){
              return std::numeric_limits<float>::quiet_NaN();

            }

           if ((f(left)*f(midpoint))>0){
              counter ++;
              return bisectionHelper(midpoint, right, precision, minIntervalSize, counter);

            }
            else{
              counter ++;
              return bisectionHelper(left, midpoint, precision, minIntervalSize, counter);
            }
            return midpoint;
          }

float bisection(const float left, const float right,
		const float precision, const float minIntervalSize) {
      int counter = 1;
        return bisectionHelper(left, right, precision, minIntervalSize, counter);

      }


//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING


int main(const int argc, const char* const argv[]) {

  cout<< bisection(atof(argv[1]), atof(argv[2]),atof(argv[3]),atof(argv[4]))<<endl;

  // Some test driver code here ....

  return 0;
}

#endif
