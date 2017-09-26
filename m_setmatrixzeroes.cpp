// Set matrix zeros
// 9/26/17
// Medium
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setzeros(vector<vector<int> > &matrix) {
    const size_t m = matrix.size();
    const size_t n = matrix[0].size();
    vector<bool> row(m, false);
    vector<bool> col(n, false);

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                row[i] = col[j] = true;
            }
        }
    }

    for (size_t i = 0; i < m; ++i) {
        if (row[i])
            fill(&matrix[i][0], &matrix[i][0] + n, 0);
    }
    
    for (size_t j = 0; j < n; ++j) {
        if (col[j]) {
            for (size_t i = 0; i < m; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    return 0;
}
