// 8.30.2017
// Easy
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int removeelement(vector<int> &nums, int target) {
    int index = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != target)
            nums[index++] = nums[i];
    }

    return index;
}

int removeelement2(vector<int> &nums, int target) {
    return distance(nums.begin(), remove(nums.begin(), nums.end(), target));
}


int main()
{
    {
        int A[] = {1, 2, 3, 4, 3, 5};
        vector<int> nums(A, A + 6);
        int target = 3;

        int len = removeelement(nums, target);
        assert(len == 4);
    }
    {
        int A[] = {1, 2, 3, 4, 3, 5};
        vector<int> nums(A, A + 6);
        int target = 3;

        int len = removeelement2(nums, target);
        assert(len == 4);
    }
    return 0;
}

