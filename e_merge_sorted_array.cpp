// Merge sorted array
// 9/3/2017
// Easy
#include <iostream>
#include <cassert>

using namespace std;

void merge(int A[], int m, int B[], int n) {
    int ia = m - 1, ib = n - 1, icur = m + n - 1;
    
    while (ia >= 0 && ib >= 0) {
        A[icur--] = A[ia] >= B[ib] ? A[ia--]:B[ib--];
    }

    while (ib >= 0)
        A[icur--] = B[ib--];
}

int main()
{
    int A[] = {1, 2, 3, 0, 0};
    int B[] = {4, 5};
    int C[] = {1, 2, 3, 4, 5};
    
    merge(A, 3, B, 2);

    for (int i = 0; i < 5; i++)
        assert(A[i] == C[i]);

    return 0;
}
