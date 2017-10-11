#include <iostream>
#include <float.h>
#include <limits.h>
#include <stdlib.h>
#include <iomanip>


using namespace std;

int main(const int argc, const char* const argv[]){
  if (argc < 3 ){
    cerr << "Error: Unable to compute statistics over data set because not enough inputs arguments were given." << endl;
    return -1;
  }

  int size = argc -2;
  float array[size];
  float min = FLT_MAX;
  float max = -FLT_MAX;
  float avg = 0;
  float sum = 0;
  int window_size = atoi(argv[1]);
  int input_number = size;
  int count = 0;


  if (window_size > input_number){
    cerr << "Warning: Unable to compute statistics over data set because not enough inputs arguments were given." << endl;
    return -1;
  }
  if (window_size == 1){
    cerr << "Warning: Unable to compute statistics over data set because window is too small." << endl;
    return -1;
  }

  if (window_size < 1){
    cerr << "Error: Unable to compute statistics over data set because window is too small." << endl;
    return -1;
  }
  for (int i = 0; i < size; i++){
    array[i]= atof(argv[i+2]);
  }
  cout << "Window Size: "<< atof(argv[1])<< endl;
  cout << setw(10) <<"Sample" << setw(10) <<"Value"<< setw(10)<<  "SWMinimum" << setw(10)<<"SWAverage"<<  setw(10)<<"SWMaximum" << endl;

  int n= 0; int m=0;
  while(m < (size)){
    float array1[window_size];

    for(int k = 0; k < window_size; k++){       //

       array1[k] = array[k+m];
    }


    while(n < window_size){

      if (min > array1[m]){
      min = array1[m];

      }
      if (max < array[m]){
        max = array [m];

      }
      sum = sum + array1[m];


      n++;
  }
  n=0;


  cout << setw(10)<< m << setw(10) << array[m]<<setw(10) << min  << setw(10)<< (sum/window_size) <<setw(10)<< max << endl;
  m++;
  sum = 0;
  //}



}
}
