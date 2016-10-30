// remove duplicates from sorted array
// 10.29.2016
#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n == 0 || n == 1) return n;

        int index = 0;

        for (int i = 1; i < n; i++) {
            if (A[i] != A[index])
                A[++index] = A[i];
        }
        
        return index + 1;
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

int main()
{
    {
        int A[3] = {1,1,2};
        int B[2] = {1,2};

        test(A, 3, B, 2);
    }

    {
        int A[] = {};
        int B[] = {};

        test(A, 0, B, 0);
    }

    {
        int A[] = {1};
        int B[] = {1};

        test(A, 1, B, 1);
    }

    {
        int A[] = {1,2,3};
        int B[] = {1,2,3};

        test(A, 3, B, 3);
    }

    return 0;
}
