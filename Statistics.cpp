#include <iostream>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

using namespace std;

int main(const int argc, const char* const argv[]){

if (argc < 3 ){
cerr << "Unable to compute statistics over data set because not enough inputs arguments were given." << endl;
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

while(i < argc){
float value = atof(argv[i]);
//find minimum
if (value < min){
min = value;
}

if (value > max){
max = value;
}

sum = sum + atof(argv[i]);

i++;

}
cout << "Number of floating-point numbers: " << numFloats << endl;

cout << "Minimum floating-point number: " << min << endl;
cout << "Average floating-point number: " <<  sum/numFloats << endl;
cout << "Maximum floating-point number: " << max << endl;



return 0;

}
