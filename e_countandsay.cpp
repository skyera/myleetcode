// Count and say
// 9/2/2017
// Easy
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cassert>
#include <sstream>

using namespace std;


string getnext(const string &s) {
    stringstream ss;

    for (auto i = s.begin(); i != s.end();) {
        auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
        ss << distance(i, j) << *i;
        i = j;
    }
    return ss.str();
}

string countandsay(int n) {
    string s("1");

    while(--n) 
        s = getnext(s);

    return s;
}

int main()
{
    string s = countandsay(1);
    assert(s == "1");

    s = countandsay(2);
    assert(s == "11");

    s = countandsay(5);
    assert(s == "111221");
    return 0;
}
