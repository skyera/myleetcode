// Valid palindrome
// 8/31/2017
// Easy
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <cassert>

using namespace std;

bool ispalindrome(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    auto left = s.begin(), right = prev(s.end());

    while (left < right) {
        if (!isalnum(*left)) ++left;
        else if (!isalnum(*right)) --right;
        else if (*left != *right) return false;
        else {
            ++left;
            --right;
        }
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    bool ok = ispalindrome(s);
    assert(ok);

    return 0;
}
