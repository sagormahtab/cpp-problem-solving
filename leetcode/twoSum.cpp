#include <iostream>
#include <iterator>
#include <cstring>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <utility>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
  unordered_map<int, int> hashMap;
  vector<int> result;

  for (size_t i = 0; i < nums.size(); i++)
  {
    hashMap.insert(make_pair(nums[i], i));
  }

  for (size_t i = 0; i < nums.size(); i++)
  {
    int complement = target - nums[i];
    if (hashMap.find(complement) != hashMap.end() && hashMap.find(complement)->second != i)
    {
      result.push_back(i);
      result.push_back(hashMap.find(complement)->second);
      return result;
    }
  }

  return result;
}

int main()
{
  vector<int> ar = {3, 2, 4};
  int target = 6;

  vector<int> result = twoSum(ar, target);

  // HIGHLIGHT: converting int vector to string
  stringstream ss;
  copy(result.begin(), result.end(), ostream_iterator<int>(ss, ","));
  string s = ss.str();
  s = s.substr(0, s.length() - 1); // get rid of the trailing space

  cout << "[" << s << "]";
  return 0;
}
