//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <limits>

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
// #defines, enum, and function declarations; do not remove
//

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself
#define NaN std::numeric_limits<float>::quiet_NaN() // (comes from <limits>)

enum sortType { ASCENDING, DESCENDING, UNKNOWN, UNSORTED };

bool isSorted(const float data[], const int currentDataItem, const sortType typeOfSort);
bool sorted(const float data[]);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
//

bool isSorted(const float data[], int currentDataItem, sortType type)
 {
   if (data[currentDataItem]==NaN){
     return true;
                      // if it reaches the end of the input when it encounters NaN, it means that it is true.
   }
  // if (dataset[0]==NaN){
    //return true;
                      // if it reaches the end of the input when it encounters NaN, it means that it is true.
//   }
   switch (type) {
     case ASCENDING:
       if ((data[currentDataItem] > data[currentDataItem -1])){
         return isSorted(data, currentDataItem+1, ASCENDING);
       }
       else{
         //...
       }
       break;
     case DESCENDING:
     if ((data[currentDataItem] < data[currentDataItem -1])){
       return isSorted(data, currentDataItem+1, DESCENDING);
     }
     else{
      // ...
     }
     break;
     defaut:
     return false;


  }
  currentDataItem ++;
//  ...
}

bool sorted(const float data[]) {
  if (isSorted(data, 0, ASCENDING)){
    return true;
  }
  else if (isSorted(data, 0, DESCENDING)){
    return true;
  }
  else if (isSorted(data, 0, UNKNOWN)){
    return false;
  }
  else if(isSorted(data, 0, UNSORTED)){
    return false;
  }
  else{
    return false;
  }
  // ...
}

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
  float data[] = {1, 2, 4, 5, 9, NaN};

  if (sorted(data))
    cout << "Data is sorted" << endl;
  else
    cout << "Data is not sorted" << endl;

  return 0;
}

#endif
