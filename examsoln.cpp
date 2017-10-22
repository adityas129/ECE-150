#include <iostream>

using namespace std;


int main(){

int a = 13;int b = a++;
int c = ++a;
cout << "2c - (a+b) = " << (2*c - (a+b)) << endl;
}
