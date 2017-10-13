//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING



using namespace std;

bool statistics(const float dataset[], const int size,
                float& min, float& avg, float& max,
	        float& popSD, float& smplSD, float& mdn);

float minimum(const float dataset[], const int size);
float average(const float dataset[], const int size);
float maximum(const float dataset[], const int size);
float popStdDev(const float dataset[], const int size);
float smplStdDev(const float dataset[], const int size);
float median(const float dataset[], const int size);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

float pow(float a, float b){
  float multiple = 1;
  for ( int i = 0; i < b; i ++){
    multiple = a * multiple;
  }
    return multiple;
}

bool statistics(const float dataset[], const int size,
	   float& min, float& avg, float& max,
	   float& popSD, float& smplSD, float& mdn) {
       int statisticcs = 1;
    if (minimum(dataset[], size) == NaN || average( dataset[],  size) == NaN || maximum( dataset[], size) == NaN || popStdDev( dataset[],  size) == NaN || smplStdDev( dataset[], size) == NaN || median( dataset[], size)== NaN || size <= 0){
      statisticcs = 0;
    }
  return statisticcs;
}

float minimum(const float dataset[], const int size) {

  for (int i = 0; i < size; i++){
    float min = INT_MAX;
    float value = dataset[i];
    if (value < min){
     min = value;
    }
  }
    return min;
}

float average(const float dataset[], const int size) {
  float sum = 0;
  float avg = 0;
  for (int i = 0; i < size; i++){

    sum = dataset[i] + sum;
  }
  avg = sum/ size;
  return avg;
}

float maximum(const float dataset[], const int size) {
  for (int i = 0; i < size; i++){
    float max = INT_MIN;
    float value = dataset[i];
    if (value > max){
     max = value;
    }
  }
    return max;
}

float popStdDev(const float dataset[], const int size) {
  float popStdDev = 0;
  float sum = 0;
  float avg = 0;
  for (int i = 0; i < size; i++){
    sum = dataset[i] + sum;
  }
  avg = sum/ size;

  float sigma = 0;
  for (int j = 0; j < size; j++){
    float sigma = pow((dataset[j] - avg), 2) + sigma;
  }
  popStDev = sqrt((sigma / size));
  return popStDev;
}

float smplStdDev(const float dataset[], const int size) {
  float smplStDev = 0;
  float sum = 0;
  float avg = 0;
  for (int i = 0; i < size; i++){
    sum = dataset[i] + sum;
  }
  avg = sum/ size;

  float sigma = 0;
  for (int j = 0; j < size; j++){
    float sigma = pow((dataset[j] - avg), 2) + sigma;
  }
  smplStDev = sqrt(sigma / (size-1));
  return smplStDev;

}

float median(const float dataset[], const int size) {
  for (int n=0; n<size-1; n++)
  {
    for (int k=0; k<size-n-1; k++)
    {
      if (dataset[k]>dataset[k+1])
      {
        int temp = dataset[k+1];
        dataset[k+1] = dataset[k];

        dataset[k] = temp;
      }
    }
    float mdn = 0;
  	if (size % 2 == 0){
  		 mdn = ( (float)dataset[size/2-1] + (float)dataset[size/2] ) / 2;
  	}
    else{
      mdn = dataset[size/2];
    }
    return mdn;

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
  int size = 5;
  float dataset[] = {1, 2, 3, 4, 5};
  float min;
  float avg;
  float max;
  float popStDev;
  float smplStDev;
  float median;

  if (statistics(dataset, size, min, avg, max, popStDev, smplStDev, median)) {
    cout << "Minimum: " << min << endl
	 << "Average: " << avg << endl
	 << "Median:  " << median << endl
	 << "Maximum: " << max << endl
	 << "Population Standard Deviation: " << popStDev << endl
	 << "Sample Standard Deviation:     " << smplStDev << endl;
  }
  else
    cout << "Error: unable to compute statistics" << endl;

  return 0;
}

#endif
