// Roman to integer
// 9/2/2017
// Easy
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int maps(const char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int  romantoint(string s) {
    int result = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && maps(s[i]) > maps(s[i-1]))
            result += maps(s[i]) - 2 * maps(s[i-1]);
        else
            result += maps(s[i]);
    }
    return result;
}

// reference https://discuss.leetcode.com/topic/6127/my-easy-to-understand-c-solutions
int romantoint2(string s) {
    int result = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && maps(s[i]) < maps(s[i+1]))
            result -= maps(s[i]);
        else
            result += maps(s[i]);
    }

    return result;
}

int main()
{
    string s = "IV";

    int x = romantoint(s);
    assert(x == 4);
    
    x = romantoint2(s);
    assert(x == 4);
    return 0;
}
