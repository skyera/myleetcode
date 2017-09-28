// Search insert position
// medium
#include <iostream>
#include <vector>

using namespace std;

template<typename ForwardIterator, typename T>
ForwardIterator mylower_bound(ForwardIterator first, 
                              ForwardIterator last,
                              T value)
{
    while (first != last) {
        auto mid = next(first, distance(first, last) / 2);
        if (value > *mid) first = ++mid;
        else last = mid;
    }
    return first;
}

int searchinsert(vector<int> &nums, int target) {
    return distance(nums.begin(), mylower_bound(nums.begin(), nums.end(), target)); 
}

int main()
{
    return 0;
}

