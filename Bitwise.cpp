#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main(const int argc, const char* argv[]){

  int n = atoi(argv[1]);
  int s = atoi(argv[2]);

  cout << "N: " << n << endl;
  cout << "S: " << s << endl;
  cout << "Left-shift of N by S bits is: " << (n<<s) << endl;
  cout << "Right-shift of N by S bits is: " << (n>>s) << endl;
  cout << "The equivalent math operation of left-shift N by S bits is: (n*(pow(2,s)))"<< endl;
  cout << "And the result of that operation is: " << (n<<s) << endl;
  cout << "The equivalent math operation of right-shift N by S bits is: (int(n/(pow(2,s)))" << endl;
  cout << "And the result of that operation is: " << (n>>s) << endl;

  return 0;

}
