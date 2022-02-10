#include <iostream>
#include <iomanip>
#include <cmath>
#define pi 2*acos(0.0)
using namespace std;
int main(){
  int T;
  double r, d, cArea, sArea, result;
  cin>>T;
  for(int i = 0; i < T; i++){
    cin>>r;
    d = r * 2;
    cArea = pi*r*r;
    sArea = d*d;
    result = sArea - cArea;
    cout<<"Case "<<i+1<<": "<<fixed<<setprecision(2)<<result<<endl;
  }
  return 0;
}
