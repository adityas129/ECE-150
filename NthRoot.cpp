#include <iostream>
#include <stdlib.h>

using namespace std;

int multiple = 1;
float pow(float a, float b){
  for ( int i = 0; i < b; i ++){
    multiple = a * multiple;
    return multiple;

  }
}

int main(const int argc, const char* const argv[]){

  if (argc < 4 ){
     cerr <<"Error: Unable to compute Nth root because of insufficient arguments." << endl;
     return -1;
  }



  float number  = atof(argv[1]);
  int root  = atoi(argv[2]);
  float precision  = atof(argv[3]);
  float result = number / 2;
  int p = 0;
  int x =0;
  float initial_guess = number/2;
  float precision_test = 1;

  if (argc > 4 ){
     cerr <<"Warning: Expecting three command-line arguments; received"<< argc-1<< ", ignoring extraneous arguments."<< endl;
  }
  if (number < 0){
    cerr << "Error: Unable to compute Nth root because of wrong arguments." << endl;

    return -1;
  }



   if (root != 2){
     cerr<< "Error: Unable to compute Nth root because of wrong arguments." << endl;
     return -1;
   }

   if (precision <= 0 ){
     cerr<< "Error: Unable to compute Nth root because of wrong arguments." << endl;
     return -1;
   }

   if (number == 0){
     cout << "Root( " << number << ", "<< root << ") = "<< result << endl;
     cout << "(with precision " << argv[3] << ")" << endl;
     return 0;
   }




   cout << "Root( " << number << ", "<< root << ") = "<< result << endl;


   cout << "(with precision " << p << ")" << endl;






return 0;

}

/*

#include <iostream>
#include <stdlib.h>

using namespace std;
int answer = 0;
float pow(float a, float b){


  for(int z=0; z< b; z ++ ){
    answer =
  }
}

int main(const int argc, const char* const argv[]){
  float number  = atof(argv[1]);
  int root  = atoi(argv[2]);
  float precision  = atof(argv[3]);
  float result = 0;
  int p = 0;
  int x =0;
  float initial_guess = 1;
  float precision_test = 1;


  if (argc < 4 ){
     cerr <<"Error: Unable to compute Nth root because of insufficient arguments." << endl;
     return -1;
  }
  if (argc > 4 ){
     cerr <<"Warning: Expecting three command-line arguments; received"<< argc-1<< ", ignoring extraneous arguments."<< endl;
  }

  if (root < 2){
     cerr<< "Error: Unable to compute Nth root because of wrong arguments."<< endl;
     return -1;
   }

   if (precision <= 0){
     cerr<< "Error: Unable to compute Nth root because of wrong arguments." << endl;
     return -1;
   }

   if (number == 0){
     cout << "Root( " << number << ", "<< root << ") = "<< result << endl;
     cout << "(with precision " << argv[3] << ")" << endl;
     return 0;
   }

   while (precision_test > precision){

     result = (root - 1)*initial_guess/root + number/(root * (initial_guess));
     precision_test = (number - result * result )/number;
     if (precision_test < 0){
       precision_test = -precision_test;
   }




 }
 cout << "Root( " << number << ", "<< root << ") = "<< result << endl;
 cout << "(with precision " << p << ")" << endl;





return 0;
}
*/
