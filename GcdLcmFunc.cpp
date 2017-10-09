#include <iostream>
#include <stdlib.h>




using namespace std;

int main(const int argc, const char* const argv[]){
  if (argc < 3 ){
     cerr <<"Error: Unable to compute GCD and/or LCM because of insufficient arguments." << endl;
     return -1;
  }
  if (argc > 3 ){
     cerr <<"Warning: Expecting two command-line arguments; received"<< argc-1<< ", ignoring extraneous arguments."<< endl;
  }


   int a  = atoi(argv[1]);
   int b  = atoi(argv[2]);
   int c = a;
   int d = b;



   if (a <=0 || b <=0){
     cerr<< "Error: Unable to compute GCD and/or LCM because of Invalid Input." << endl;
     return -1;
   }

   while (d != 0){
      int t = d;
      d = c % d;
      c = t;
   }



   int gcd = c;
   int lcm = a * (b/ c);



   cout << "GCD( " << a << ", "<< b<< ") = "<< gcd << endl;
   cout << "LCM( " << a << ", "<< b<< ") = "<< lcm << endl;






return 0;
}
