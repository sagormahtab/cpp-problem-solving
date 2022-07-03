#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;
vector<int> transform_string(string s) {
    unordered_map<char, int> indexMapping;
    // used vector instead of string. because string operations were too time consuming
    vector<int> result;
    for(int i = 0; i < s.size(); i++) {
        if(indexMapping.find(s[i]) == indexMapping.end()) {
            indexMapping[s[i]] = i;
        }
        result.push_back(indexMapping.find(s[i]) -> second);
    }
    return result;
}

bool isIsomorphic(string s, string t) {
    if(transform_string(s) == transform_string(t)) {
        return true;
    }
    return false;
}

int main(){
    string s = "egg";
    string t = "add";
    bool result;
    result = isIsomorphic(s, t);
    cout << result << endl;
    return 0;
}
