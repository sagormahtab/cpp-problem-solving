#include <iostream>
#include <cstring>

using namespace std;
int main(){
  int number, length, multiplyWith;
  char k[20];
  cin>>number>>k;
  multiplyWith = number;

  length = strlen(k);

  while (1) {
    multiplyWith = multiplyWith - length;
    if(multiplyWith < 1)
      break;
    number = number * multiplyWith;
  }
  cout<<number<<endl;
  return 0;
}
