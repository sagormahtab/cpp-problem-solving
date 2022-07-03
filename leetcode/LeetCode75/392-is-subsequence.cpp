#include <iostream>
using namespace std;

bool isSubsequence(string s, string t) {
        int m=s.size(), n=t.size();
        int i=0,j=0;

        while(i<m && j<n){
            if(s[i]==t[j]) i++;
            j++;
        }
        return i==m ? 1 :0 ;
    }

int main(){
    string s = "abc";
    string t = "ahbgdc";
    cout << isSubsequence(s, t);
    return 0;
}
