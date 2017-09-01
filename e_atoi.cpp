// string to integer (atoi)
// 9/1/2017
// Easy
#include <iostream>
#include <string>
#include <climits>
#include <cassert>

using namespace std;

int myatoi(const string &str) {
    int num = 0;
    int i = 0;
    int n = str.size();
    int sign = 1;

    while (i < n && str[i] == ' ')
        i++;

    if (str[i] == '+')
        i++;
    else if (str[i] == '-') {
        i++;
        sign = -1;
    }

    for (; i < n; i++) {
        if (str[i] < '0' || str[i] > '9') break;

        if (num > INT_MAX / 10 || 
            (num == INT_MAX/10 && (str[i] - '0') > INT_MAX%10)) 
            return sign ? INT_MAX:INT_MIN;
        num = num * 10 + str[i] - '0';
    }

    return num * sign;
}

int main()
{
    string s = "123";

    int v = myatoi(s);
    assert(v == 123);
    
    s = "   123xxx";
    v = myatoi(s);
    assert(v == 123);

    s = "   -123";
    v = myatoi(s);
    assert(v == -123);

    return 0;
}
