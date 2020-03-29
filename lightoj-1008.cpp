#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int T, quadrantX,quadrantY, distance;
  long long int num, sqrtNum, middleNum;
  cin>>T;
  for(int i = 0; i < T; i++)
  {
    cin>>num;
    sqrtNum = ceil(sqrt(num));
    quadrantX = sqrtNum;
    quadrantY = sqrtNum;
    middleNum = pow(sqrtNum,2) - (sqrtNum - 1);
    //checking for perfect square
    if(sqrt(num) == sqrtNum){
      if(num % 2){
        quadrantX = 1;
        quadrantY = sqrt(num);
      }
      else{
        quadrantX = sqrt(num);
        quadrantY = 1;
      }
    }
    //if not perfect square
    else if((sqrtNum%2==0  && num<middleNum) || (sqrtNum%2==1  && num>middleNum)){
      distance = fabs(num - middleNum);
      quadrantX -= distance;
    }
    else{
      distance = fabs(num - middleNum);
      quadrantY -= distance;
    }
    cout<<"Case "<<i+1<<": "<<quadrantX<<" "<<quadrantY<<endl;
  }
  return 0;
}
