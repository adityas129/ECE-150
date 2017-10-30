//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//


//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

int range(const int dataset[], const int size);
int mode(const int dataset[], const int size, int mode[]);
bool sort(int dataset[], const int size);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  Return -1 if there there are any problems with the dataset.
//

int range(const int dataset[], const int size){}
int mode(const int dataset[], const int size, int mode[]){}
bool sort(int dataset[], const int size){}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....
  int data[] = {1,1,2,3,4,5};
  int size = 6;
  //change this to however many modes you expect to find
  int modeArray[100]={0};
  int rng = range(data, size);
  int modes = mode(data, size, modeArray);
  cout << "range: " << rng << " number of Modes: " << modes << " Modes are this: ";
  for(int i = 0; i<modes;i++){
  	cout<< modeArray[i];
  	if(i<modes-1){
  		cout << ", ";
  	}
  }
  cout<<endl;
  return 0;
}

#endif
