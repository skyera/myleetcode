// 8/31/2017
// Easy
#include <iostream>

using namespace std;

int climbstairs(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int prev = 0;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        int tmp = cur;
        cur += prev;
        prev = tmp;
    }

    return cur;
}

int main()
{
    for (int i = 1; i < 10; i++) {
        int f = climbstairs(i);
        cout << f << " ";
    }
    cout << endl;

    return 0;
}
