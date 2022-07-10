#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int version)
{
  vector<bool> v = {NULL, false, false, false, true, true};
  return v[version];
}

int firstBadVersion(int n)
{
  long long int start = 1;
  long long int end = n;
  while (start <= end)
  {
    long long int mid = (start + end) / 2;
    if (isBadVersion(mid))
    {
      if (mid == 1 || !isBadVersion(mid - 1))
        return mid;
      else
        end = mid - 1;
    }
    else if (isBadVersion(mid - 1) && mid != 1)
      end = mid - 1;
    else
      start = mid + 1;
  }

  return -1;
}

int main()
{
  int n = 5;
  int result = firstBadVersion(n);
  cout << result;
  return 0;
}