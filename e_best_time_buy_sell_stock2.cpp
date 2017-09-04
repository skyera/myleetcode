// Best time to buy and sell stock II
// 9/3/2017
// Easy
#include <iostream>
#include <vector>

using namespace std;

int maxprofit(vector<int> &prices) {
    int sum = 0;
    for (int i = 1; i < prices.size(); i++) {
        int diff = prices[i] - prices[i-1];
        if (diff > 0) sum += diff;
    }

    return sum;
}

int main()
{
    return 0;
}

