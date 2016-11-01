// remove duplicates from sorted array
// Given a sorted array, remove the duplicates in place such that each element appear only once
// and return the new length.
// Do not allocate extra space for another array, you must do this in place with constant memory.
// For example, Given input array A = [1,1,2],
// Your function should return length = 2, and A is now [1,2].
// 10.29.2016
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n <= 1) return n;

        int index = 0;

        for (int i = 1; i < n; i++) {
            if (A[i] != A[index])
                A[++index] = A[i];
        }
        
        return index + 1;
    }

    int removeDuplicates1(int A[], int n) {
        return distance(A, unique(A, A + n));       
    }

    int removeDuplicates2(int A[], int n) {
        return removeDuplicates(A, A + n, A) - A;
    }
    
    template<typename InIt, typename OutIt>
    OutIt removeDuplicates(InIt first, InIt last, OutIt output) {
        while (first != last) {
            *output++ = *first;
            first = upper_bound(first, last, *first);
        }
        return output;
    }
};

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void test(int A[], int n, int B[], int size)
{
    static int counter = 0;
    cout << "test:" << ++counter << endl;
    print(A, n);
    Solution s;

    int len = s.removeDuplicates(A, n);
    print(A, len);
    assert(len == size);
    
    for (int i = 0; i < len; i++)
        assert(A[i] == B[i]);
    cout << "OK\n";
}

void test1(int A[], int n, int B[], int size)
{
    static int counter = 0;
    cout << "test:" << ++counter << endl;
    print(A, n);
    Solution s;

    int len = s.removeDuplicates1(A, n);
    print(A, len);
    assert(len == size);
    
    for (int i = 0; i < len; i++)
        assert(A[i] == B[i]);
    cout << "OK\n";
}

void test2(int A[], int n, int B[], int size)
{
    static int counter = 0;
    cout << "test:" << ++counter << endl;
    print(A, n);
    Solution s;

    int len = s.removeDuplicates1(A, n);
    print(A, len);
    assert(len == size);
    
    for (int i = 0; i < len; i++)
        assert(A[i] == B[i]);
    cout << "OK\n";
}

int main()
{
    {
        int A[3] = {1,1,2};
        int B[2] = {1,2};

        test(A, 3, B, 2);
        test1(A, 3, B, 2);
        test2(A, 3, B, 2);
    }

    {
        int A[] = {};
        int B[] = {};

        test(A, 0, B, 0);
        test1(A, 0, B, 0);
        test2(A, 0, B, 0);
    }

    {
        int A[] = {1};
        int B[] = {1};

        test(A, 1, B, 1);
        test1(A, 1, B, 1);
        test2(A, 1, B, 1);
    }

    {
        int A[] = {1,2,3};
        int B[] = {1,2,3};

        test(A, 3, B, 3);
        test1(A, 3, B, 3);
        test2(A, 3, B, 3);
    }

    return 0;
}
