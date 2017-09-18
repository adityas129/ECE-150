#include <iostream>
#include <stdlib.h>

using namespace std;

int main(const int argc, const char* argv[]){

float velocity = atof(argv [1]);
float distance = atof(argv [2]);
float deceleration = ((0-(velocity*velocity))/(2*distance));
float time = (-velocity)/deceleration ;
cout << "Initial car velocity: " << argv [1]<<"m/s"<< endl;
cout << "Distance to obstacle: "<< argv [2]<<"m"<< endl;
cout << "Minimum deceleration: "<< deceleration <<"m/s/s"<< endl;
cout << "Maximum stopping time: "<< time <<"s"<< endl;

return 0;

}
