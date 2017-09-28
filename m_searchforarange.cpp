// Search for a range
// 9/28/17
// Medium
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> searchrange(vector<int> &nums, int target) {
    const int l = distance(nums.begin(),  lower_bound(nums.begin(), nums.end(), target));
    const int u = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
    if (nums[l] != target)
        return vector<int> {-1, -1};
    else
        return vector<int> {l, u};
}

int main()
{
    return 0;
}
