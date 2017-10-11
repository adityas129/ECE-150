#include <iostream>
#include <stdlib.h>
#include <math.h>

#include <float.h>
#include <limits.h>

using namespace std;

float value = 0;




int main(const int argc, const char* const argv[]){
if (argc < 4){
cerr << "Error: Insufficient arguments; expecting three or more inputs" << endl;
return -1;
}

float alpha = atof(argv[1]);
int i = 4;
float Minimum = atof(argv[3]);
float Maximum = atof(argv[3]);
float EWMA = atof(argv[3]);
float countmin = 1;
float countmax = 1;
int y =1;



int age = atof(argv[2]);



if(alpha >= 1){
cerr << "Error: Unable to compute statistics over data set; alpha value wrong." << endl;
return -1;
}

else if(alpha <= 0){
cerr << "Error: Unable to compute statistics over data set; alpha value wrong." << endl;
return -1;
}

else if (age < 1){
cerr << "Error: age has to be posiitve." << endl;
return -1;
}


else{

cout << "Sample    value     Minimum     EWMA      Maximum "<< endl;
cout << y << "\t" << atof(argv[3])<< "\t" << Minimum << "\t"<< atof(argv[3]) << "\t"<< Maximum << "\t" << endl;




while (i  < argc ){


//find minimum
float value = atof(argv[i]);

if(countmin < 3){

if (value < Minimum){
Minimum = value;
countmin = 1;
}

else {
countmin++;

}
}
else {
Minimum = value;
countmin = 1;
}


if(countmax < 3){
if (value > Maximum){
Maximum = value;
countmax = 1;
}

else {
countmax++;

}
}
else{
Maximum = value;
countmax = 1;

}





float samplet = atof (argv[i]);


EWMA = alpha * samplet + (1-alpha) * EWMA ;

y++;
i++;
cout << y << "\t" << samplet<< "\t"  << Minimum  << "\t" << EWMA <<"\t" << Maximum << endl;

}
i++;

}
return 0;

}
