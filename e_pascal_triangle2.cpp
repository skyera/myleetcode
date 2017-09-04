// Pascal triangle II
// 9/4/2017
// Easy
#include <iostream>
#include <vector>

using namespace std;

vector<int> getrow(int rowindex) {
    vector<int> array;

    for (int i = 0; i <= rowindex; i++) {
        for (int j = i - 1; j > 0; j--) {
            array[j] = array[j-1] + array[j];
        }
        array.push_back(1);
    }

    return array;
}

int main()
{
    return 0;
}
