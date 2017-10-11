#include <iostream>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <math.h>

using namespace std;

int main(const int argc, const char* const argv[]){

  if (argc < 2 ){
    cerr << "Error: Unable to compute statistics over data set because not enough inputs arguments were given." << endl;
    return 0;
  }
  int numFloats = argc - 1;

  // find min

  //output number of floating points nmbers

  float min = FLT_MAX;
  float max = FLT_MIN;
  float average;
  float sum;
  int i = 1;
  int j = 0;
  float array[argc-1];
  float loc_pop_std = 0;
  float sample_std = 0;
  float sum1 = 0;


  while (j < numFloats){
   array[j] = atof(argv[j+1]);
   j++;
  }


  while(i < argc){
    float value = atof(argv[i]);
    //find minimum
    if (value < min){
      min = value;
    }

    if (value > max){
      max = value;
    }

    sum = sum + value;

    i++;

  }

  average = sum/numFloats ;
//  cout << "average"<< average << endl;

  for (int k = 0; k < numFloats; k++){
    sum1 = (array[k]- average)*(array[k]- average) + sum1;
  //  cout << sum1 << endl;
  }
  if ( argc - 2 == 0){
    cout << "Number of floating-point numbers: " << numFloats << endl;
    cout << "Minimum floating-point number: " << min << endl;
    cout << "Average floating-point number: " <<  sum/numFloats << endl;
    cout << "Maximum floating-point number: " << max << endl;
    cout << "Population standard deviation: "<< sqrt(sum1/(argc-1))<<endl;
    cout << "Sample standard deviation: "<< "Infinity"<<endl;


  }

  cout << "Number of floating-point numbers: " << numFloats << endl;
  cout << "Minimum floating-point number: " << min << endl;
  cout << "Average floating-point number: " <<  sum/numFloats << endl;
  cout << "Maximum floating-point number: " << max << endl;
  cout << "Population standard deviation: "<< sqrt(sum1/(argc-1))<<endl;
  cout << "Sample standard deviation: "<<sqrt(sum1/(argc-2)) <<endl;


  return 0;

}
