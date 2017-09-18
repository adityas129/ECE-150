#include <iostream>
#include <stdlib.h>
using namespace std;

int main(const int argc, const char* argv[]){

int x = atoi(argv[1]);
int y = atoi(argv[2]);

int addition = x+y;
int multiplier = x*y;
cout << "The sum of the two numbers is " << addition << "and the product is " << multiplier << endl;

return 0;

}
