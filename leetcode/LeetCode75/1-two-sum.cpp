#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
  vector<int> res;
  unordered_map<int, int> m;
  for (int i = 0; i < nums.size(); i++)
  {
    auto got = m.find(target - nums[i]);
    // fancy way to insert multiple items to a vector in one line
    if (got != m.end())
      res.insert(res.end(), {got->second, i});
    m[nums[i]] = i;
  }
  return res;
}

int main()
{
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  vector<int> result = twoSum(nums, target);
  for (int elm : result)
    cout << elm << " ";

  return 0;
}