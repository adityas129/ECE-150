#include <iostream>
#include <stdlib.h>

using namespace std;
int main (){
int x;
unsigned int y;



cout <<"The value of x is " << x << endl;
cout <<"The value of y is " << y << endl;

cout << "The most significant bit of x is " << (x >> 31) << endl;
cout << "The most significant bit of y is " << (y >> 31) << endl;

return 0;
}
