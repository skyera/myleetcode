// 8.30.2017
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

int removedup(vector<int> &nums) {
    if (nums.size() <= 2) return nums.size();

    int index = 2;
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] != nums[index - 2])
            nums[index++] = nums[i];
    }

    return index;
}

int main()
{
    int A[] = {1, 1, 1, 2, 2, 3};
    vector<int> nums(A, A + 6);

    int len = removedup(nums);
    assert(len == 5);
    return 0;
}

