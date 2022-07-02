#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> outputArr;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        outputArr.push_back(sum);
    }
    return outputArr;
}

int main () {
    vector<int> nums = {1000000,1000000,1000000,1000000,1000000};
    vector<int> resultArr;
    resultArr = runningSum(nums);
    cout << resultArr.size();
    for(int i = 0; i < resultArr.size(); i++) {
        cout << resultArr[i] << endl;
    }
    return 0;
}
