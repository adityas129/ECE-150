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

#include <iostream>

using namespace std;

int greatestCommonDenominator(const int a, const int b);
int leastCommonMultiple(const int a, const int b);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

int greatestCommonDenominator(const int a, const int b) {
  if (a <=0 || b <=0){
    return -1;
  }
  int gcd = 0;
  int c = a;
  int d = b;
   while (d != 0){
     int t = d;
     d = c % d;
     c = t;
  }
   gcd = c;

  if (gcd < 0){
    return -1;
  }
  else{
    return gcd;
  }


}

int leastCommonMultiple (const int a, const int b) {
  if (a <=0 || b <=0){
    return -1;
  }
  int lcm = 0;

  int gcd =  greatestCommonDenominator( a,  b);

   lcm = a * (b/ gcd);


  if (lcm < 0){
    return -1;
  }
  else{
    return lcm;
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

  if (argc < 3) {
    cerr << "Error: Usage: " << argv[0] << "<num1> <num2>; exiting" << endl;
    return -1;
  }

  int gcd = greatestCommonDenominator(atoi(argv[1]),atoi(argv[2]));
  if (gcd < 0)
    cerr << "Unable to compute GCD(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "GCD(" << argv[1] << "," << argv[2] << ") = " << gcd << endl;

  int lcm = leastCommonMultiple(atoi(argv[1]),atoi(argv[2]));
  if (lcm < 0)
    cerr << "Unable to compute LCM(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "LCM(" << argv[1] << "," << argv[2] << ") = " << lcm << endl;


  return 0;
}

#endif
