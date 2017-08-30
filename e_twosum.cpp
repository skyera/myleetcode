// 8.30.2017
//
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> twosum(vector<int> &nums, int target) {
    vector<int> result;
    unordered_map<int, int> mapping;

    for (int i = 0; i < nums.size(); i++) 
        mapping[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++) {
        int gap = target - nums[i];
        if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
            result.push_back(i + 1);
            result.push_back(mapping[gap] + 1);
            break;
        }
    }

    return result;
}

void test(vector<int> &nums, int target, const vector<int> &out)
{
    vector<int> result = twosum(nums, target);
    bool ok = result == out;
    assert(ok);
}

int main()
{
    int A[] = {2, 7, 11, 15};
    vector<int> nums(A, A + 4);
    int target = 9;

    vector<int> out;
    out.push_back(1);
    out.push_back(2);

    test(nums, target, out);

    return 0;
}

