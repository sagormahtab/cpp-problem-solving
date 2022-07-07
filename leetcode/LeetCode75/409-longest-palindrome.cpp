#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// A palindrome consists of letters with equal partners, plus possibly a unique center (without a partner). The letter i from the left has its partner i from the right.
// For example in 'abcba', 'aa' and 'bb' are partners, and 'c' is a unique center. Imagine we built our palindrome.
// It consists of as many partnered letters as possible, plus a unique center if possible. This motivates a greedy approach.

// ALTERNATE SOLUTION: finding odds by using bitwise operator &
// int longestPalindrome(string s)
// {
//   int odds = 0;
//   for (char c = 'A'; c <= 'z'; c++)
//     odds += count(s.begin(), s.end(), c) & 1;
//   return s.size() - odds + (odds > 0);
// }

int longestPalindrome(string s)
{
  unordered_map<char, int> m;
  int res = 0;
  bool center = false;
  for (char c : s)
    m[c]++;
  for (auto it : m)
  {
    res += it.second;
    if (it.second % 2 == 1)
    {
      res -= 1;
      center = true;
    }
  }

  return center ? res += 1 : res;
}

int main()
{
  string s = "abccccdd";
  int result = longestPalindrome(s);
  cout << result;
  return 0;
}