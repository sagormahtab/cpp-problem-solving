#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
  unsigned long long int generateSequence[18];
  for(int i = 0; i < 18;i++ ){
    generateSequence[i] = pow(10,i);
    cout<<generateSequence[i];
  }
  return 0;
}
