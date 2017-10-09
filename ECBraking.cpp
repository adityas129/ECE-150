

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(const int argc, const char* argv[]){
if(argc < 4){
cerr << "Error: Insufficient arguments; expecting more." << endl;
}
if(argc > 4){
cerr << "Warning: Expecting three command-line arguments; received four; ignoring extraneous arguments." << endl;
}


float velocity = atof(argv [1]);
float distance = atof(argv [2]);
float max_a = atof(argv [3]);
float velocity_final = sqrt((velocity *velocity) + (2*max_a*distance));
float time1 = (velocity_final-velocity)/max_a;



if (velocity == 0){
cout << "There is no possibility of collision because the velocity of the car is zero." << endl;
return -1;
}
else if (velocity < 0 & distance > 0){
cout << "There is no possibility of collision because the velocity opposite way" << endl;
return -1;
}
else if (velocity > 0 & distance < 0){
cout << "There is no possibility of collision because the velocity opposite way" << endl;
return -1;
}
else if (distance == 0){
cout << "There is no possibility of collision because  the distance between the cars is zero." << endl;
return -1;
}
else if (max_a == 0){
cout << "There is no possibility of collision because the vehicle will always crash." << endl;
}

else if (velocity < 0 & distance < 0 ){

float deceleration = (-(velocity*velocity)/(2 * distance));

if (deceleration <= max_a){

cout << "Initial car velocity: " << atof(argv [1])<<"m/s"<< endl;
cout << "Distance to obstacle: "<< atof(argv [2])<<"m"<< endl;
cout << "Minimum deceleration: "<< deceleration <<"m/s/s"<< endl;
cout << "Maximum stopping time: "<< (-velocity)/deceleration  <<"s"<< endl;
}
else {



//cout << "Initial car velocity: " << atof(argv [1])<<"m/s"<< endl;
//cout << "Distance to obstacle: "<< atof(argv [2])<<"m"<< endl;
cout << "Crash will occur in "<< time1 << " seconds at velocity " <<  -velocity_final << " m/s; deploying airbags." << endl;

}


}

else if (velocity > 0 & distance > 0 ){
float deceleration11 = ((velocity*velocity)/(2 * distance));

if (deceleration11 <= max_a){

cout << "Initial car velocity: " << atof(argv [1])<<"m/s"<< endl;
cout << "Distance to obstacle: "<< atof(argv [2])<<"m"<< endl;
cout << "Minimum deceleration: "<< deceleration11 <<"m/s/s"<< endl;
cout << "Maximum stopping time: "<< (velocity)/deceleration11  <<"s"<< endl;
}
else {

time1 = (velocity_final-velocity)/-max_a;

float velocity_final1 = sqrt((velocity *velocity) - (2*max_a*distance));


//cout << "Initial car velocity: " << atof(argv [1])<<"m/s"<< endl;
//cout << "Distance to obstacle: "<< atof(argv [2])<<"m"<< endl;
cout << "Crash will occur in "<< time1 << " seconds at velocity " <<  velocity_final1 << " m/s; deploying airbags." << endl;

}

return 0;
}
}
