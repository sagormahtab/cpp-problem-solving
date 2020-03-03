#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n,number=0,nthPosition,factors = 1,k=0;
  cin>>n;
  int primeNumbers[15000];

  while(1){
      number++;
      for(int j = 1; j <= sqrt(number); j++){
        if(number % j == 0)
          factors++;
      }
      if(factors == 1){
        primeNumbers[k] = number;
        k++;
      }

      factors = 0;

      if(number > 163841)
        break;
    }

  for(int i = 0; i < n; i++){
    cin>>nthPosition;
    cout<<primeNumbers[nthPosition-1]<<endl;
  }
  return 0;
}
