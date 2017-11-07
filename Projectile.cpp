//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <math.h>
#include <iostream>
using namespace std;
#endif

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY) {

                             if (h <= 0 || v < 0 || m <= 0 || w <= 0){
                               return false;
                             }
                             if (v > 0 || h > t || d > b || theta > 0 || theta < 90 ){
                               // when ball lands on top of the building
                             }
                             if (v > 0 || h > t || d > b || theta > 0 || theta < 90 ){
                               // when ball hits the building
                             }
                             if (v > 0 || h > t || d > b || theta > 0 || theta < 90 ){
                               // when the ball falls short
                             }
                             if (v > 0 || h > t || d > b || theta > 0 || theta < 90 ){
                               // when the ball goes the opposite way
                             }





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

  // Some test driver code here ....
//90 -180

// four courses for ball landing
  float h = 10;
  float v = 10;
  float m = 10;
  float theta = 45;        // Angle in degrees; will need to be converted by function
  float d = 100;
  float t = 5;
  float b = 97;
  float w = 5;

  float hitsAtX;
  float hitsAtY;

  if (projectileDestination(h,v,m,theta,d,t,b,w,hitsAtX,hitsAtY))
    cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" <<endl;
  else
    cout << "Unable to calculate where projectile hits." << endl;
  return 0;
}

#endif
