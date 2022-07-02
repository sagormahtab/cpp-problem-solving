#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int index = -1;
    int leftSum = 0;
    int rightSum = 0;

    for(int i = 0; i < nums.size(); i++) {
        rightSum += nums[i];
    }
    for(int i = 0; i < nums.size(); i++) {
        if (i != 0) {
            leftSum += nums[i-1];
        }
        rightSum -= nums[i];
        if(leftSum == rightSum) {
            index = i;
            break;
        }
    }
    return index;
}

int main() {
    int index;
    vector<int> nums = {1,7,3,6,5,6};
    index = pivotIndex(nums);
    cout << index <<endl;
    return 0;
}
