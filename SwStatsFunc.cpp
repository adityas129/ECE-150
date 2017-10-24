//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <float.h>
#include <math.h>


//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

float pow(float a, float b){
  float multiple = 1;
  for ( int i = 0; i < b; i ++){
    multiple = a * multiple;
  }
    return multiple;
}

int SWStats(const float dataset[], const int size,
            const int currentSample, const int windowSize,
            float& min, float& avg, float& max,
            float& smplSD, float& mdn);

int SWMinimum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& minimum);
int SWAverage(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& average);
int SWMaximum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& maximum);
int SWSmplStdDev(const float dataset[], const int size,
                 const int currentSample, const int windowSize,
                 float& smplStdDev);
int SWMedian(const float dataset[], const int size,
             const int currentSample, const int windowSize,
             float& median);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

int SWStats(const float dataset[], const int size,
            const int currentSample, const int windowSize,
            float& min, float& avg, float& max,
            float& smplSD, float& mdn) {
          if (windowSize < 0){
            return -2;
          }
          if (windowSize == 0){
            return -1;
          }
              SWMinimum(dataset, size, currentSample, windowSize, min);
              SWAverage(dataset, size, currentSample, windowSize, avg);
              SWMaximum(dataset, size, currentSample, windowSize, max);
              SWSmplStdDev(dataset, size, currentSample, windowSize, smplSD);
              SWMedian(dataset, size, currentSample, windowSize, mdn);

          if (windowSize >= size){
            return 1;
          }
          if (windowSize == 1){
            return 2;
          }



          return 0;
}

int SWMinimum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& minimum) {
                float array1[size + windowSize -1];
                for(int j = 0; j < windowSize - 1; j++ ){
                  array1[j]= dataset[0];
                }
                for(int i = windowSize-1, j = 0; j  < size; i++, j++){
                  array1[i]= dataset[j];
                }
                 minimum = FLT_MAX;
                for(int k = currentSample + (windowSize - 1 ); k >= currentSample ; k -- ){
                  if(array1[k] < minimum){
                    minimum = array1[k];
                  }

                }
                return 0;
}

int SWAverage(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& average) {

                float array1[size + windowSize -1];
                int cap = currentSample + 1 - windowSize;
                for(int j = 0; j < windowSize - 1; j++ ){
                  array1[j]= dataset[0];
                }
                for(int i = windowSize-1, j = 0; j  < size; i++, j++){
                  array1[i]= dataset[j];
                }
                float sum = 0;
                for(int k = currentSample + (windowSize - 1 ); k >= currentSample ; k -- ){
                  sum = sum + array1[k];

                }
                average = sum / windowSize;
                return 0;
}


int SWMaximum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& maximum) {
                float array1[size + windowSize -1];
                int cap = currentSample + 1 - windowSize;
                for(int j = 0; j < windowSize - 1; j++ ){
                  array1[j]= dataset[0];
                }
                for(int i = windowSize-1, j = 0; j  < size; i++, j++){
                  array1[i]= dataset[j];
                }
                 maximum = FLT_MIN;
                for(int k = currentSample + (windowSize - 1 ); k >= currentSample ; k -- ){
                  if(array1[k] > maximum){
                    maximum = array1[k];
                  }

                }
                return 0;

}

int SWSmplStdDev(const float dataset[], const int size,
                 const int currentSample, const int windowSize,
                 float& smplStdDev) {
                   float array1[size + windowSize -1];
                   int cap = currentSample + 1 - windowSize;
                   for(int j = 0; j < windowSize - 1; j++ ){
                     array1[j]= dataset[0];
                   }
                   for(int i = windowSize-1, j = 0; j  < size; i++, j++){
                     array1[i]= dataset[j];
                   }
                   float sum = 0;
                   for(int k = currentSample + (windowSize - 1 ); k >= currentSample ; k -- ){
                     sum = sum + array1[k];

                   }
                   float average = sum / windowSize;
                   float sigma = 0;


                   for (int l = currentSample + (windowSize - 1 ); l >= currentSample ; l -- ){
                      sigma = ((array1[l] - average)* (array1[l] - average)) + sigma;
                   }
                   smplStdDev = sqrt(sigma/(windowSize-1));

                   return 0;

}

int SWMedian(const float dataset[], const int size,
             const int currentSample, const int windowSize,
             float& median)
               {
                 float array2[windowSize-1];

                 float array1[size + windowSize -1];
                 int cap = currentSample + 1 - windowSize;
                 for(int j = 0; j < windowSize - 1; j++ ){
                   array1[j]= dataset[0];
                 }
                 for(int i = windowSize-1, j = 0; j  < size; i++, j++){
                   array1[i]= dataset[j];
                 }
                 for (int i = currentSample + windowSize - 1, j = 0; i >= currentSample; i --, j++){
                   array2[j]=array1[i];

                 }

                 for (int n=0; n<windowSize; n++)
                 {
                   for (int k=0; k<windowSize-n-1; k++)
                   {
                     if (array2[k]>array2[k+1])
                     {
                       float temp = array2[k+1];
                       array2[k+1] = array2[k];

                       array2[k] = temp;
                     }
                   }
                  if (size % 2 == 0){
                     median = ( array2[size/2-1] + array2[size/2] ) / 2;
                  }
                   else{
                     median = array2[size/2];
                   }
                 }

                return 0;
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
    int size = 1;
    float dataset[] = {17.6028};
    int windowSize = 4;
    int currentSample = 0;
    float min;
    float avg;
    float max;
    float smplSD;
    float median;

    cout << "Sample \t Minimum \t Average \t Median \t Maximum \t Sample Standard Deviation" << endl;

    while (currentSample < size) {
        int retCode = SWStats(dataset, size, currentSample, windowSize, min, avg, max, smplSD, median);
        if (retCode >= 0) {
            cout << currentSample << "\t " << min << "\t " << avg << "\t " << max << "\t " << median << "\t " << smplSD << endl;
            if (retCode > 0)
                cerr << "Warning: something weird happened, but we computed stats anyway ... YMMV" << endl;
        }
        else {
            cerr << "Error: unable to compute sliding-window statistics; exiting" << endl;
            return(-1);
        }
        ++currentSample;
    }
    return 0;
}

#endif
