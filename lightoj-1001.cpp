#include <iostream>
using namespace std;
int main(){
  int T, item;
  cin>>T;
  for(int i = 0; i < T; i++){
    cin>>item;
    if(item <= 10)
      cout<<"0"<<" "<<item<<endl;
    else
      cout<<item-10<<" "<<"10"<<endl;
  }
  return 0;
}
