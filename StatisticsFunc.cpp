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
       bool statisticcs = true;
       if (size < 1){
         statisticcs = false;
       }
       min = minimum(dataset, size);
       avg = average(dataset, size);
       max = maximum(dataset, size);
       popSD = popStdDev(dataset, size);
       smplSD = smplStdDev(dataset, size);
       mdn = median(dataset, size);


       return statisticcs;

    }


float minimum(const float dataset[], const int size) {
  float min = INT_MAX;

  for (int i = 0; i < size; i++){
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
  float max = INT_MIN;

  for (int i = 0; i < size; i++){
    float value = dataset[i];
    if (value > max){
     max = value;
    }
  }
    return max;
}

float popStdDev(const float dataset[], const int size) {
  float popStDev = 0;
  float sum = 0;
  float avg = 0;
  for (int i = 0; i < size; i++){
    sum = dataset[i] + sum;
  }
  avg = sum/ size;

  float sigma = 0;
  for (int j = 0; j < size; j++){
     sigma = pow((dataset[j] - avg), 2) + sigma;
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
     sigma = pow((dataset[j] - avg), 2) + sigma;
  }
  smplStDev = sqrt(sigma / (size-1));

  return smplStDev;

}

float median(const float dataset[], const int size) {
  float mdn = 0;
  float array[size];
  for (int i=0; i < size; i++){
     array[i] = dataset[i];
  }
  for (int n=0; n<size-1; n++)
  {
    for (int k=0; k<size-n-1; k++)
    {
      if (array[k]>array[k+1])
      {
        float temp = array[k+1];
        array[k+1] = array[k];

        array[k] = temp;
      }
    }
  	if (size % 2 == 0){
  		 mdn = ( array[size/2-1] + array[size/2] ) / 2;
  	}
    else{
      mdn = array[size/2];
    }
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
  int size = 15;
  float dataset[] = {17.6028 , 10.9157,  16.7465 , 16.9766 ,18.6747, 7.96327 ,10.0283 ,16.5234 ,9.16662, 13.3095 ,12.161 ,14.4331 ,10.4718, 12.701 ,19.2834};
  float min;
  float avg;
  float max;
  float popStDev;
  float smplStDev;
  float median;
  cout << "smaple stdev"<< smplStdDev(dataset, size);

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
