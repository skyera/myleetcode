// Palindrome number
// 9/3/2017
// Easy
#include <iostream>

using namespace std;

bool ispalindrome(int x) {
    if (x < 0) return false;

    int d = 1;
    while (x /d >= 10) d *= 10;

    while (x > 0) {
        int q = x / d;
        int r = x % 10;
        if (q != r) return false;

        x = x % d / 10;
        d /= 100;
    }

    return true;
}

int main()
{
    return 0;
}
