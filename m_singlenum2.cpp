// Single number II
// 9/26/17
// Medium
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int singlenumber(vector<int> &nums) {
    const int W = sizeof(int) * 8;
    int count[W];
    fill_n(&count[0], W, 0);

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < W; j++) {
            count[j] += (nums[i] >> j) & 1;
            count[j] %= 3;
        }
    }
    int result = 0;
    for (int i = 0; i < W; i++) {
        result += (count[i] << i);
    }
    return result;
}

int main()
{
    return 0;
}
