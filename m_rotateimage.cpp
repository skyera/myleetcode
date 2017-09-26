// Rotate image
// 9/26/17
// Medium
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int> > & matrix) {
    const int n = matrix.size();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - 1; ++j)
            swap(matrix[i][j], matrix[n-1-j][n-1-i]);

    for (int i = 0; i < n / 2; ++i)
        for (int j = 0; j < n; ++j)
            swap(matrix[i][j], matrix[n-1-i][j]);
}

int main()
{
    return 0;
}
