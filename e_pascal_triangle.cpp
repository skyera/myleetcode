// Pascal's triangle
// 9/4/2017
// Easy
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<vector<int> > generate(int numrows) {
    vector<vector<int> > result;
    if (numrows == 0) return result;

    result.push_back(vector<int>(1, 1));

    for (int i = 2; i < numrows; ++i) {
        vector<int> current(i, 1);
        vector<int> &prev = result[i - 2];

        for (int j = 1; j < numrows; ++j)
            current[j] = prev[j-1] + prev[j];
        result.push_back(current);
    }

    return result;
}

vector<vector<int> > generate2(int numrows) {
    vector<vector<int> > result;
    vector<int> array;

    for (int i = 1; i <= numrows; i++) {
        for (int j = i - 2; j > 0; j--) {
            array[j] = array[j-1] + array[j];
        }
        array.push_back(1);
        result.push_back(array);
    }
    return result;
}

int main()
{
    int numrows = 2;
    vector<vector<int> > result;

    result = generate2(numrows);
    assert(result.size() == 2);

    return 0;
}

