#include <iostream>

using namespace std;
  int main(){

  int num_ints_created = 0;
  while (num_ints_created < 20 * 1000 * 1000){
    int * my_new_int = NULL;
    cout << my_new_int << " ";
    my_new_int = new int;
    cout << *my_new_int << " ";
    cout << &my_new_int << " ";
    delete my_new_int;
    my_new_int = NULL;
    cout << num_ints_created << endl;
    num_ints_created ++;
  }
  return 0;
  }

  /*  big ideas so far in this course:
  1) variables: we can store any info in our computer, as long as we have an ecnoding foramt (data type)
  2) progrma execution
    - sequence (line by line)
    - branch *conditional jump forward, if statement)
    -loop (conditional jump backward)
  3)function: unit / block of code that can be executed independently; compose a program out of smaller sub-programs.
  4)

*/
