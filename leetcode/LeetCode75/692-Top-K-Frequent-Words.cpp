#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
using Pair = pair<string, int>;

struct Comp
{
  bool operator()(const Pair &a, const Pair &b)
  {
    if (a.second != b.second)
      return a.second < b.second;
    return a.first > b.first;
  }
};

vector<string> topKFrequent(vector<string> &words, int k)
{
  vector<string> ans;
  unordered_map<string, int> mp;
  for (auto word : words)
    mp[word]++;

  priority_queue<Pair, vector<Pair>, Comp> q{mp.begin(), mp.end()};
  while (k--)
    ans.push_back(q.top().first), q.pop();
  return ans;
}

int main()
{
  vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
  int k = 2;
  vector<string> result = topKFrequent(words, k);

  for (int i = 0; i < result.size(); i++)
    cout << result[i];

  return 0;
}