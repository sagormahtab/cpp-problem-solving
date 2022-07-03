#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
  unordered_map<int, int> umap;
  bool isFound = false;
  for (size_t i = 0; i < nums.size(); i++) {
    umap.insert(make_pair(nums[i], i));

    unordered_map<int, int>::iterator got = umap.find(nums[i]);
    if(got != umap.end() && got -> second != i) {
      isFound = true;
      break;
    }
  }

  return isFound;
}

int main() {
  vector<int> v{1,1,1,3,3,4,3,2,4,2};
  bool res = containsDuplicate(v);

  cout << res;
  return 0;
}