// Add binary: given two binary, return their sum (also a binary string)
// 9/1/2017
// Easy
#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

string addbinary(string a, string b) {
    string result;
    const size_t n = a.size() > b.size() ? a.size(): b.size();
    int carry = 0;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        int ai = i < a.size() ? a[i] - '0': 0;
        int bi = i < b.size() ? b[i] - '0': 0;
        int val = (ai + bi + carry);
        carry = val / 2;
        val %= 2;
        result.insert(result.begin(), val + '0');
    }

    if (carry) result.insert(result.begin(), '1');

    return result;
}

int main()
{
    string a = "11", b = "1";
    string c = addbinary(a, b);
    assert(c == "100");

    return 0;
}

