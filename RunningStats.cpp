#include <iostream>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

using namespace std;


float Minimum = FLT_MAX;
float Maximum = FLT_MIN;
float average;
float sum;


int main(const int argc, const char* const argv[]){

if (argc < 2){
cerr << "Unable to compute statistics over data set because not enough inputs were given." << endl;
return -1;
}
int numFloats = argc - 1;

cout << "Sample    Value     Minimum     Average     Maximum" << endl;
int i = 1;
while (i < argc ){
float value = atof(argv[i]);
//find minimum
if (value < atof(argv[i])){
Minimum = value;
}

if (value > atof(argv[i])){
Maximum = value;
}

sum = sum + atof(argv[i]);

float average = sum/i ;

cout << i << "     " << atof(argv[i])<< "     " << Minimum  << "     "<< (sum/i) <<"     "<< Maximum << endl;
i++;
}








return 0;





}
