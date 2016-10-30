// 10.29.2016
// Search in rotated sorted array
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.

#include <iostream>
#include <cassert>
using namespace std;

class Solution
{
public:
    int search(int A[], int n, int target) {
        int first = 0, last = n;
        while (first != last) {
            int mid = first + (last - first) / 2;
            if (A[mid] == target) return mid;

            if (A[first] <= A[mid]) {
                if (A[first] <= target && target < A[mid])
                    last = mid;
                else
                    first = mid + 1;
            } else {
                if (A[mid] < target && target <= A[last-1])
                    first = mid + 1;
                else
                    last = mid;
            }
        }

        return -1;
    }
};

void test(int A[], int n, int target, int index)
{
    Solution s;

    int pos = s.search(A, n, target);
    assert(pos == index);
    cout << "OK\n";    
}

int main()
{
    {
        int A[] = {4,5,6,7,0,1,2};

        test(A, 7, 5, 1);
    }

    {
        int A[] = {6,7,0,1,2,4,5};
        test(A, 7, 7, 1);
    }

    {
        int A[] = {4,5,6,7,0,1,2};
        test(A, 7, 3, -1);
    }

    return 0;
}
