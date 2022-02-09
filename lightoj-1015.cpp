#include <iostream>
using namespace std;
int main(){
  int T, N, num[1000], sum = 0;
  cin>>T;
  for(int i = 0; i < T; i++){
    cin>>N;
    for(int j = 0; j < N; j++){
      cin>>num[j];
      if(num[j] < 0)
        continue;
      sum += num[j];
    }
    cout<<"Case "<<i+1<<": "<<sum<<endl;
    sum = 0;
  }
  return 0;
}
