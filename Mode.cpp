//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <limits.h>
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
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

int range(const int dataset[], const int size);
int mode(const int dataset[], const int size, int mode[]);
bool sort(int dataset[], const int size);
void selection(int dataset[], int start, int end, const int size);
//////////////////////////////////////////////////////////////
//
// Your code here ...
//  Return -1 if there there are any problems with the dataset.
//

int range(const int dataset[], const int size){
  if (size <= 0){
    return -1;
  }
  int min = INT_MAX;
  int max = INT_MIN;
  int difference = 0;
  for (int i = 0; i < size; i++){
    if (min > dataset[i]){
      min = dataset[i];
    }
    if (max < dataset[i]){
      max = dataset[i];
    }
  }
  difference = max - min;
  if (difference < 0){
    return -1;
  }
  return difference;

}
void selection(int dataset[], int start, int end){
  if ( start >= end )
        return;
    int minIndex = start;
    for ( int index = start + 1; index <= end; index++ )
    {
        if (dataset[index] < dataset[minIndex] )
            minIndex = index;
    }
    int temp = dataset[start];
    dataset[start] = dataset[minIndex];
    dataset[minIndex]= temp;
    selection(dataset, start + 1, end);
}
int mode(const int dataset[], const int size, int mode[]){
  if (size <= 0){
    return -1;
  }
  if (size ==1){
    return dataset[0];
  }

  int dataset2[size];

  for (int w = 0; w < size; w++){
    dataset2[w]= dataset[w];
  }

  sort(dataset2, size);

  int count = 1;




    int modenumber[size];
    for (int z = 0; z < size; z++){
      modenumber[z]= 0;
    }
    for (int j = 0; j<size; j++){
      for (int i = 0; i < size; i++){
          if (dataset2[i]==dataset2[j]){
            modenumber[j] = modenumber[j] + 1 ;
          }
        }
    }
    int max = INT_MIN;
    for (int i = 0; i < size; i++){

      if (max < modenumber[i]){
        max = modenumber[i];
      }
    }
    int number_of_modes = 0;
    for (int w = 0; w < size; w++){
      if (modenumber[w]== max){
        if (number_of_modes == 0){
          mode[number_of_modes]= dataset2[w];
          number_of_modes++;
        }
        if (number_of_modes != 0 && mode[number_of_modes - 1]!= dataset2[w]){
          mode[number_of_modes] = dataset2[w];
          number_of_modes++;
        }
      }
    }
    return number_of_modes;
  }


bool sort(int dataset[], const int size){
  if (size < 1){
    return false;
  }
  selection( dataset, 0, size-1);
  return true;
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
  int data[] = {7,5,2,5,7,0,4,2,7,0,5,9,2};
  int size = 13;
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
