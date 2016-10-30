// 10.30.2016
// Search in rotated sorted array II
//Follow up for ”Search in Rotated Sorted Array”: What if duplicates are allowed?
// Would this affect the run-time complexity? How and why?
// Write a function to determine if a given target is in the array.
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int first = 0, last = n;
        while (first != last) {
            const int mid = first + (last - first) / 2;
            if (A[mid] == target) return true;
            if (A[mid] < A[mid]) {
                if (A[first] <= target && target < A[mid])
                    last = mid;
                else
                    first = mid + 1;
            } else if (A[first] > A[mid]) {
                if (A[mid] < target && target <= A[last-1])
                    first = mid + 1;
                else
                    last = mid;
            } else
                first++;
        }

        return false;
    }
};

void test(int A[], int n, int target, bool find)
{
    Solution s;

    bool flag = s.search(A, n, target);
    assert(flag == find);
    cout << "OK\n";
}

int main()
{
    {
        int A[] = {1,3,1,1,1};
        test(A, 5, 1, true);
    }

    return 0;
}
