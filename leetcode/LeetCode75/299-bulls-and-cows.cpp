#include <iostream>
#include <vector>
using namespace std;

string getHint(string secret, string guess)
{
  string result;
  vector<int> stat(10, 0);
  int bulls = 0, cows = 0;

  for (int i = 0; i < secret.size(); i++)
  {
    if (secret[i] == guess[i])
      bulls++;
    else
      stat[secret[i] - '0']++;
  }

  for (int i = 0; i < guess.size(); i++)
  {
    if (secret[i] != guess[i] && stat[guess[i] - '0']-- > 0)
      cows++;
  }

  result = to_string(bulls) + "A" + to_string(cows) + "B";
  return result;
}

int main()
{
  string secret = "1123", guess = "0111";
  string result = getHint(secret, guess);
  cout << result;
  return 0;
}