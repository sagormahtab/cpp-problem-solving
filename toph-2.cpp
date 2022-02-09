#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int n,x,p,q;
  cin>>n;
  char a[n][n];
  gets(a[0]);
  for(int i = 0; i < n; i++){
      gets(a[i]);
  }
  cin>>x;
  int y[x],willAffected[n*n],willAffectedCounter=-1;
  bool isAffected = false;
  for(int i = 0; i < x; i++)
    cin>>y[i];
  for(int i = 0; i < x; i++){
      if(y[i]%n == 0){
          p = y[i]/n - 1;
          q = x - 1;
      }
      else{
          p = y[i]/n;
          q = (y[i] - n*p) - 1;
      }
      if(a[p][q] == 'c' && isAffected == false)
        isAffected = true;
      if(isAffected == true){
          if(a[p][q] == 'c')
            continue;
          else{
              willAffectedCounter++;
              willAffected[willAffectedCounter] = y[i];
              willAffected[willAffectedCounter+1] = -1;
          }
      }
  }

  if(!isAffected)
    cout<<"NO";
  else{
      cout<<"YES"<<endl;
      if(willAffectedCounter == -1)
        exit(1);
      for(int i = 0; willAffected[i] != -1; i++)
        cout<<willAffected[i]<<" ";
  }
  cout<<endl;
  return 0;
}
