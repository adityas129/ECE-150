#include <iostream>

using namespace std;

int main(){
const int arraySize = 8;
int array[arraySize] = {35, 117, 6, -9, 100, -7762, 130, 6};
int input;
cin >> input;
for(int i = 0; i <=(input % arraySize); i++){
cout << "Element "<< (i + 1) << ": "<< array[i] << endl;
}
}
