// Best time to buy and sell stock
// 9/3/2017
// Easy
#include <iostream>
#include <vector>

using namespace std;

int maxprofit(vector<int> &prices) {
    if (prices.size() < 2) return 0;

    int profit = 0;
    int cur_min = prices[0];

    for (int i = 1; i < prices.size(); i++) {
        profit = max(profit, prices[i] - cur_min);
        cur_min = min(cur_min, prices[i]);
    }

    return profit;
}

int main()
{
    return 0;
}
