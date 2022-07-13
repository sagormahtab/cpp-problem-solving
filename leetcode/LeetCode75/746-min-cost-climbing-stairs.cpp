#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
  cost.push_back(0);
  for (int i = 2; i < cost.size(); i++)
  {
    cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
  }
  return cost[cost.size() - 1];

  // THIS IS W/O MODIFYING THE ORIGINAL ARRAY
  // vector<int> dp(cost.size() + 1);

  // for (int i = 2; i <= cost.size(); i++)
  // {
  //   dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
  //   cout << dp[i] << " ";
  // }
  // return dp.back();
}

int main()
{
  vector<int> cost = {10, 15, 20};
  int result = minCostClimbingStairs(cost);
  cout << result << endl;
  return 0;
}