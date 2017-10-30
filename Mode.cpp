//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
#include <limits.h>
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
int msort( int dataset[], const int size);
bool sort(int dataset[], const int size);
void merge(int dataset[], const int size);

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

int mode(const int dataset[], const int size, int mode[]){
  if (size <= 0){
    return -1;
  }
  if (size ==1){
    return dataset[0];
  }
  else{

    int modenumber[size];
    for (int z = 0; z < size; z++){
      modenumber[z]= 0;
    }
    for (int j = 0; j<size; j++){
      for (int i = 0; i < size; i++){
          if (dataset[j]==dataset[i]){
            modenumber[j] = modenumber[j] + 1 ;
          }
        }
    }
    merge
  }

}
void merge(int dataset[],int left[],int leftCount,int right[],int rightCount){
  int i,j,k;
  i = 0; j = 0; k =0;


  while(i<leftCount && j < rightCount) {
		if(left[i]  < right[j]) {
      dataset[k] = left[i];
      k++;
      i++;

    }
		else {
      dataset[k] = right[j];
      k++;
      j++;
    }
  }

}

int msort( int dataset[], int size){
  if (size == 1){
    return -1;
  }

  int mid = 0;
  mid = size/2;
  int left[mid], right[size - mid];
  for(int i = 0;i<mid;i++) {
    left[i] = dataset[i];                          // creating left subarray
  }
  for(int i = mid;i<size;i++){
    right[i-mid] = dataset[i];                         // creating right subarray
  }
  msort(left,mid);  // sorting the left subarray
  msort(right,size-mid);  // sorting the right subarray
  merge(dataset,left,mid,right,size-mid);  // Merging L and R into A as sorted list.

  return dataset;

}

bool sort(int dataset[], const int size){

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
