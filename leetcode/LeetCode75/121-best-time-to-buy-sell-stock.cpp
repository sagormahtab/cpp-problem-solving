#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
  int maxProfit = 0;
  int minPrice = INT_MAX;
  for (int i = 0; i < prices.size(); i++)
  {
    if (minPrice > prices[i])
    {
      minPrice = prices[i];
    }
    else if (prices[i] - minPrice > maxProfit)
    {
      maxProfit = prices[i] - minPrice;
    }
  }
  return maxProfit;
}

int main()
{
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  int profit = maxProfit(prices);
  cout << profit << endl;
  return 0;
}