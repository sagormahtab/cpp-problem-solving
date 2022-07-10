#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int start, int end, int target)
{
  if (start > end)
    return -1;
  else
  {
    int mid = (start + end) / 2;
    if (nums[mid] == target)
      return mid;
    else if (target > nums[mid])
      return binarySearch(nums, mid + 1, end, target);
    else
      return binarySearch(nums, start, mid - 1, target);
  }
}

int search(vector<int> &nums, int target)
{
  int start = 0;
  int end = nums.size() - 1;
  int resultIndex = binarySearch(nums, start, end, target);
  return resultIndex;
}

int main()
{
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 2;
  int resultIndex = search(nums, target);
  cout << resultIndex;
  return 0;
}