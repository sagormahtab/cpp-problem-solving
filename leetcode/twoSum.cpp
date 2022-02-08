#include <iostream>
#include <iterator>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
  vector<int>::iterator ptr, ptr2;
  vector<int> result;

  for (ptr = nums.begin(); ptr < nums.end(); ptr++)
  {
    for (ptr2 = nums.begin(); ptr2 < nums.end(); ptr2++)
    {
      if (ptr == ptr2)
      {
        continue;
      }

      int index1 = ptr - nums.begin();
      int index2 = ptr2 - nums.begin();
      int addition = nums[index1] + nums[index2];

      if (addition == target)
      {
        // HIGHLIGHT: technique for string concatenation
        // stringstream ss;
        // ss << "[" << index1 << "," << index2 << "]";
        // string result = ss.str();

        result.push_back(index1);
        result.push_back(index2);

        return result;
      }
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
