#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n,countPrime=1,number,nthPosition,factors = 1;
  cin>>n;

  for(int i = 0; i < n; i++){
    cin>>nthPosition;
    number = 1;
    while(1){
      number++;
      for(int j = 1; j <= sqrt(number); j++){
        if(number % j == 0)
          factors++;
      }
      if(factors == 1)
        countPrime++;

      factors = 0;

      if(countPrime == nthPosition)
        break;
    }
    cout<<number<<endl;
    countPrime = 1;
    factors = 1;
  }
  return 0;
}
