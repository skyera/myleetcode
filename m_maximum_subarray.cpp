// Maximum subarray
// Medium

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxsubarray(vector<int> &nums) {
    int result = INT_MIN;
    int f = 0;

    for (int i = 0; i < nums.size(); i++) {
        f = max(f + nums[i], nums[i]);
        result = max(result, f);
    }

    return result;
}

int main()
{
    return 0;
}
