// Next permutation
// 9/23/17
// M
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>

using namespace std;

template<typename BidiIt>
bool do_next_permutation(BidiIt first, BidiIt last) {
    const auto rfirst = reverse_iterator<BidiIt>(last);
    const auto rlast = reverse_iterator<BidiIt>(first);

    auto pivot = next(rfirst);
    while (pivot != rlast && *pivot >= *prev(pivot))
        ++pivot;

    if (pivot == rlast) {
        reverse(rfirst, rlast);
        return false;
    }

    auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));

    swap(*change, *pivot);
    reverse(rfirst, pivot);
    return true;
}

void next_permutation(vector<int> &nums) {
    do_next_permutation(nums.begin(), nums.end());
}

int main()
{
    return 0;
}
