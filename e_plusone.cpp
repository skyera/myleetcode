// 8/30/2017
// Easy
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void add(vector<int> &digits, int digit) {
    int carry = digit;

    for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it) {
        *it += carry;
        carry = *it / 10;
        *it %= 10;
    }

    if (carry)
        digits.insert(digits.begin(), carry);
}

vector<int> plusone(vector<int> &digits) {
    add(digits, 1);
    return digits;
}

int main()
{
    int A[] = {1, 2, 3, 4};
    vector<int> digits(A, A + 4);
    int B[] = {1, 2, 3, 5};
    vector<int> v(B, B + 4);

    vector<int> out = plusone(digits);
    assert(out == v);

    return 0;
}
