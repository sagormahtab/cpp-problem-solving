#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int leftSum = 0;
    int rightSum = 0;

    rightSum = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
        rightSum -= nums[i];
        if (leftSum == rightSum)
        {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}

int main()
{
    int index;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    index = pivotIndex(nums);
    cout << index << endl;
    return 0;
}
