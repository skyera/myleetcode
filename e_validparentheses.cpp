// Valid parentheses
// 9/2/2017
// Easy
#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

bool isvalid(const string &s) {
    string left("([{");
    string right(")]}");
    stack<char> stk;

    for (int i = 0; i < s.size(); i++) {
        if (left.find(s[i]) != string::npos)
            stk.push(s[i]);
        else {
            if (stk.empty() || left[right.find(s[i])] != stk.top())
                return false;
            stk.pop();
        }
    }

    return stk.empty();
}

int main()
{
    string s = "()";
    bool ok = isvalid(s);
    assert(ok);

    s = "(]";
    ok = isvalid(s);
    assert(!ok);

    s = "([)]";
    ok = isvalid(s);
    assert(!ok);
    
    return 0;
}
