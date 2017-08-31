// 8.30.2017
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
using namespace std;

int removedup(vector<int> &nums)
{
    if (nums.empty()) return 0;

    int index = 0;
    for (int i = 1; i < nums.size(); i++)
        if (nums[i] != nums[index])
            nums[++index] = nums[i];

    return index + 1;
}

int removedup2(vector<int> &nums) {
    return distance(nums.begin(), unique(nums.begin(), nums.end()));
}

template<typename InIt, typename OutIt>
OutIt removedupx(InIt first, InIt last, OutIt out) {
    while (first != last) {
        *out++ = *first;
        first = upper_bound(first, last, *first);
    }

    return out;
}
int removedup3(vector<int> &nums) {
    //return distance(nums.begin(), removedup3(nums.begin(), nums.end(), nums.begin()));
    vector<int>::iterator first = nums.begin(), last = nums.end();

    return distance(nums.begin(), removedupx(first, last, first));
}


int main()
{
    {
        int A[] = {1, 1, 2};
        vector<int> nums(A, A + 3);

        int len = removedup(nums);
        assert(len == 2);
    }
    
    {
        int A[] = {1, 1, 2};
        vector<int> nums(A, A + 3);

        int len = removedup2(nums);
        assert(len == 2);
    }
    {
        int A[] = {1, 1, 2};
        vector<int> nums(A, A + 3);

        int len = removedup3(nums);
        assert(len == 2);
    }

    return 0;
}

