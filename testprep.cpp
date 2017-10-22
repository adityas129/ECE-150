int prime(int a){

  int given = a;
  int max = 0;

  for (int i = given; i >= 2; i--){
    for (int j = 2; j < i; j++){
      if ( i % j != 0){
        int max = i;
      }
    }
    return max;
  }
  }


int main(){
  int answer = prime(32);
  return 0;
}
