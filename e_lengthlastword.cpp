// Length of last word
// 9/2/2017
// Easy
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <cassert>

using namespace std;

int lengthoflastword(const string &s) {
    auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
    auto last = find_if_not(first, s.rend(), ::isalpha);
    return distance(first, last);
}

int lengthoflastword2(const string &s) {
    int i = s.size() - 1;

    while (i >= 0) {
        if (::isalpha(s[i])) break;
        --i;
    }

    if (i < 0) return 0;

    int end = i;

    while (i >= 0) {
        if (!::isalpha(s[i])) break;
        --i;
    }

    return end - i;
}

int lengthoflastword3(const char *s) {
    int len = 0;

    while (*s) {
        if (*s++ != ' ')
            ++len;
        else if (*s && *s != ' ') {
            len = 0;
        }
    }
    return len;
}

int lengthoflastword4(const char *s) {
    int len = 0;

    while (*s) {
        if (*s != ' ') {
            ++len;
        }
        else {// is space
            len = 0;
        }
        ++s;
    }

    return len;
}


int main()
{
    string s("Hello World ");

    int len = lengthoflastword(s);
    assert(len == 5);

    len = lengthoflastword3(s.c_str());
    assert(len == 5);
    
    char s1[] = "hello world";
    len = lengthoflastword4(s1);
    assert(len == 5);

    len = lengthoflastword2(s);
    assert(len == 5);

    s = "hello";
    len = lengthoflastword2(s);
    assert(len == 5);
    
    s = "   hello   ";
    len = lengthoflastword2(s);
    assert(len == 5);
    return 0;
}
