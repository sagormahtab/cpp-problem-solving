#include <iostream>
using namespace std;
int main(){
  unsigned long long int n;
  cin>>n;
  if(n%10==0)
  {
      cout<<n/10<<endl;
      cout<<"Stay at Home"<<endl;
  }
  else
  {
      cout<<n<<endl;
      cout<<"Stay at Home"<<endl;
  }
  return 0;
}
