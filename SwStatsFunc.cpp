//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <float.h>


//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

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

}

int SWMinimum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& minimum) {
                float array1[size + windowSize -1];
                int cap = currentSample + 1 - windowSize;
                for(int j = 0; i < windowSize - 1; i++ ){
                  array1[j]= dataset[0];
                }
                for(int i = windowSize-1, j = 0; j  < size; i++, j++){
                  array1[i]= dataset[j];
                }
                float minimum = FLT_MAX;
                for(int k = currentSample + (windowSize - 1 ); k > currentSample - 1 ; k -- ){
                  if(array[k] < min){
                    minimum = array[k];
                  }

                }
                return 0;
}

int SWAverage(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& average) {
}


int SWMaximum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float& maximum) {

}

int SWSmplStdDev(const float dataset[], const int size,
                 const int currentSample, const int windowSize,
                 float& smplStdDev) {
}

int SWMedian(const float dataset[], const int size,
             const int currentSample, const int windowSize,
             float& median) {
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
    int windowSize = 2;
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
