#include <iostream>
#include <vector>
using namespace std;

int characterReplacement(string s, int k)
{
  int maxFreq = INT_MIN, length = 0;
  vector<int> charCount(26, 0);

  // expand window
  for (int start = 0, end = 0; end < s.size(); end++)
  {
    charCount[s[end] - 'A']++;
    maxFreq = max(maxFreq, charCount[s[end] - 'A']);

    // (end - start + 1 - maxFreq) means kotogulo character replace kora jay
    // shrink window from left
    if ((end - start) + 1 - maxFreq > k)
    {
      charCount[s[start] - 'A']--;
      start++;
    }

    length = max(length, (end - start) + 1);
  }
  return length;
}

int main()
{
  string s = "AABABBA";
  int k = 1;
  int result = characterReplacement(s, k);
  cout << result;
  return 0;
}