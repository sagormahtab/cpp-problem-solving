#include <iostream>

using namespace std;
int main()
{
    int N,i,sum=0;
    cin>>N;
    if(N < 1){
      while (N<=1) {
        sum = sum + N;
        N++;
      }
    }
    else{
      while (N>=1) {
        sum = sum + N;
        N--;
      }
    }
    cout<<sum<<endl;
    return 0;
}
