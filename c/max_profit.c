#include <stdio.h>

int maxProfit(int* prices, int pricesSize)
{
  int profit = 0;
  if (pricesSize < 2)
    return 0;
  int front = 0, current = 1;
  for (;current < pricesSize; current++)
  {
    if (prices[front] < prices[current])
    {
      profit += (prices[current] - prices[front]);
    }
    front = current;
  }
  return profit;
}
int main()
{
  int prices[] = {7,1,5,3,6,4};
  int profit = maxProfit(prices, 6);
  printf("%d", profit);
  return 0;
}
