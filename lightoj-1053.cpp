#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double a,b,c,A,B,C,doaCosA,doaCosB,doaCosC,PI;
  int T;
  cin>>T;

  PI = acos(-1.);
  for(int i = 0; i < T; i++)
  {
    cin>>a>>b>>c;
    doaCosA = ((pow(b,2) + pow(c,2)) - pow(a,2))/(2*b*c);
    doaCosB = ((pow(c,2) + pow(a,2)) - pow(b,2))/(2*c*a);
    doaCosC = ((pow(a,2) + pow(b,2)) - pow(c,2))/(2*a*b);

    A = acos(doaCosA)*180/PI ;
    B = acos(doaCosB)*180/PI;
    C = acos(doaCosC)*180/PI;

    if((90 <= A && A < 90.1) || (90 <= B && B < 90.1) || (90 <= C && C < 90.1))
      cout<<"Case "<<i+1<<": yes"<<endl;
    else
      cout<<"Case "<<i+1<<": no"<<endl;
}
  return 0;
}
