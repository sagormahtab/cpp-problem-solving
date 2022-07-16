#include <iostream>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
  if (s.size() < p.size())
    return {};

  vector<int> pHash(26, 0);
  vector<int> sHash(26, 0);
  vector<int> result;

  for (int i = 0; i < p.size(); i++)
  {
    pHash[p[i] - 'a']++;
    sHash[s[i] - 'a']++;
  }

  if (pHash == sHash)
    result.push_back(0);

  for (int i = p.size(); i < s.size(); i++)
  {
    sHash[s[i] - 'a']++;
    sHash[s[i - p.size()] - 'a']--;
    if (sHash == pHash)
      result.push_back(i + 1 - p.size());
  }

  return result;
}

int main()
{
  string s = "cbaebabacd", p = "abc";
  vector<int> result = findAnagrams(s, p);
  for (int elm : result)
    cout << elm;
  return 0;
}