#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int T, m, n;
  double result;
  cin>>T;
  for(int i = 0; i < T; i++){
    cin>>m>>n;
    //If row or column is 1 then just multiply row(m) & column(n)
    if(m == 1 || n == 1)
      result = m*n;
    //Else if any number is dividable with 2 then =>
    else if(m == 2 || n == 2){
      //If any number is odd then just add 1 with the big number
      if(m%2==1 || n%2 == 1){
        if(m>2)
          result = m+1;
        else
          result = n+1;
      }
      //If any number is dividable with 2 and the divide result is odd then just add the numbers
      else if((m>2 && (m/2)%2==1) || (n>2 && (n/2)%2==1))
        result = m+n;
      //If a number is 2 and another number is even then the big number is the result
      else if((m>2 && m%2==0) || (n>2 && n%2==0)){
        if(m>2)
          result = m;
        else if(n>2)
          result = n;
      }
      //If row and column both are 2 then just add them
      else
        result = m+n;
    }
    //Else just add the numbers and divide them with 2 and take the ceiling of the number
    else{
      result = (m*n)/2.0;
      result = ceil(result);
    }
    cout<<"Case "<<i+1<<": "<<result<<endl;
  }
  return 0;
}
