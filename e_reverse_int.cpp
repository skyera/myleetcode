// Reverse integer
// 9/3/2017
// Easy
#include <iostream>

using namespace std;

int reverse(int x) {
    long long r = 0;
    long long t = x;

    t = t > 0 ? t: -t;
    for (; t; t /= 10)
        r = r * 10 + t % 10;

    bool sign = x > 0 ? false: true;
    if (!sign && r > INT_MAX || (sign && r > INT_MAX + 1)) return 0;
    else {
        if (sign) return -r;
        else return r;
    }
}

int main()
{
    return 0;
}
