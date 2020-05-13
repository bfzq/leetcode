#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
  vector<int>::iterator price = prices.begin();
  if (price == prices.end())
    return 0;
  int low_price = *price;
  int high_price = low_price;
  int profit = 0;
  while (price != prices.end())
  {
    if (*price < high_price)
    {
      profit += (high_price - low_price);
      low_price = *price;
    }
    high_price = *price;
    price++;
  }
  profit += (high_price - low_price);
  return profit;
}

int main()
{
  vector<int> prices{1, 1, 1, 2, 2, 3, 3, 4, 5, 5};
  cout << maxProfit(prices) << endl;
  return 0;
}
