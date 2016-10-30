// 10.29.2016
// Remove duplicates from sorted array II
//Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice?
// For example, Given sorted array A = [1,1,1,2,2,3],
// Your function should return length = 5, and A is now [1,1,2,2,3]
#include <iostream>
#include <cassert>
using namespace std;

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

class Solution
{
public:
    int removeDuplicates(int A[], int n) 
    {
        if (n <= 2) return n;

        int index = 2;
        for (int i = 2; i < n; i++) {
            if (A[i] != A[index-2]) {
                A[index++] = A[i];
            } 
        }

        return index;
    }
};


void test(int A[], int n, int B[], int size)
{
    cout << "test\n";
    print(A, n);
    Solution s;

    int len = s.removeDuplicates(A, n);
    print(A, len);
    assert(len == size);

    for (int i = 0; i < len; i++)
        assert(A[i] == B[i]);
    
    cout << "OK\n";
}


int main()
{
    {
        int A[] = {1,1,1,2,2,3};
        int B[] = {1,1,2,2,3};

        test(A, 6, B, 5);
    }

    {
        int A[] = {1,1,2,2};
        int B[] = {1,1,2,2};

        test(A, 4, B, 4);
    }
}
