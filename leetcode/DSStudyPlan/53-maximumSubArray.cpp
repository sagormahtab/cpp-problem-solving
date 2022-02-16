#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

int maxSubArray(vector<int> &nums)
{
  int maxSum = INT_MIN, maxSoFar = 0;
  for (size_t i = 0; i < nums.size(); i++)
  {
    maxSoFar += nums[i];
    if (maxSoFar > maxSum)
    {
      maxSum = maxSoFar;
    }
    if (maxSoFar < 0)
    {
      maxSoFar = 0;
    }
  }

  return maxSum;
};

int main()
{
  vector<int> v{5, 4, -1, 7, 8};
  int maxSum = maxSubArray(v);
  cout << maxSum;
  return 0;
}