

//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//


#include <stdlib.h>
#include <limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;




float NthRoot(const float S, const int N, const float precision);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...


//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the Nth root of S with
// precision.
//

float pow(float a, float b){
  float multiple = 1;
  for ( int i = 0; i < b; i ++){
    multiple = a * multiple;
  }
    return multiple;
}

float absol(float B){
  if(B < 0){
    B = -B;
  }
  return B;
}

float NthRoot(const float S, const int N, const float precision){


  if (S < 0 && N%2 == 0|| precision < 0 || precision > 1 || N <=1||precision <= 0){
    return std::numeric_limits<float>::quiet_NaN();
  }


  float precision_test = 1;
  float result = 1;
  float prev_result = 0;


  while (absol(result - prev_result) > 1e-7 && precision_test > precision){
        prev_result = result;



       result = ((N - 1)*result/N )+ (S/(N * pow(result, N - 1)));

       precision_test = ((S - pow(result,N))/S);
       precision_test = absol(precision_test);
    }



    return result;

}

float precisionfunc(const float number, const int B, const float result){
  float precision1 = absol((number - pow(result, B))/number);
  return precision1;
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

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {

  if (argc < 4) {
    cerr << "Error: Usage: " << argv[0] << " <number> <root> <precision>; exiting" << endl;
    return -1;
  }
  int root = atoi(argv[2]);
  if (isNaN(root)){
    cerr << "Unable to compute " << argv[2] << "th root of " << argv[1] << " with precision " << argv[3] << endl;
  }
  else{

    float answer = NthRoot(atof(argv[1]), atof(argv[2]), atof(argv[3]));
    float answer2 = precisionfunc(atof(argv[1]),atoi(argv[2]),answer);
    cout << "Root(" << argv[1] << "," << argv[2] << ") = " << answer << endl;
	 cout << "(with precision " << answer2 << ")" << endl;
 }
  return 0;
}

#endif
