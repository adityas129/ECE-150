#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(const int argc, const char* argv[]){
  if(argc < 4){
  cerr << "Error: Insufficient arguments; expecting more arguments" << endl;
  }
  if(argc > 4){
  cerr << "Warning: Expecting three command-line arguments; received four; ignoring extraneous arguments." << endl;
  }


  float velocity = atof(argv [1]);
  float distance = atof(argv [2]);
  float maxacptdec = atof(argv [3]);
  float vfinal= sqrt((velocity *velocity) + (2*maxacptdec*distance));
  float time1= (vfinal-velocity)/maxacptdec;


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
    cout << "There is no possibility of collision because because the distance between the cars is zero." << endl;
    return -1;
  }
  else if (maxacptdec = 0){
    cout << ""
  }



  else if (velocity < 0 & distance < 0 ){

    float deceleration1 = (-(velocity * velocity)/(2*d));



    if (deceleration1 < maxacptdec){
      cout << "Initial car velocity: " << atof(argv [1])<<"m/s"<< endl;
      cout << "Distance to obstacle: "<< atof(argv [2])<<"m"<< endl;
      cout << "Minimum deceleration: "<< deceleration1 <<"m/s/s"<< endl;
      cout << "Maximum stopping time: "<< time <<"s"<< endl;
    }
    else{
      cout << "Initial car velocity: " << argv [1]<<"m/s"<< endl;
      cout << "Distance to obstacle: "<< argv [2]<<"m"<< endl;
      cout << "Minimum deceleration: "<< deceleration1 <<"m/s/s"<< endl;
      cout << "Maximum stopping time: "<< time <<"s"<< endl;
    }

    }

    }






    else{                    //velocity is greater than one and distance is greater than one.

    }
    }




    float deceleration = ((0-(velocity*velocity))/(2*distance));
    float time = (-velocity)/deceleration ;

    if (deceleration < maxacptdec){
      cout << "Initial car velocity: " << argv [1]<<"m/s"<< endl;
      cout << "Distance to obstacle: "<< argv [2]<<"m"<< endl;
      cout << "Minimum deceleration: "<< deceleration <<"m/s/s"<< endl;
      cout << "Maximum stopping time: "<< time <<"s"<< endl;
    }
    else {
      vfinal= sqrt((velocity *velocity) + (2*maxacptdec*distance));
      cout << "Crash will occur in " << time1 << " seconds at velocity "<< vfinal << "; deploying airbags." << endl;
    }

    return 0;

  }
