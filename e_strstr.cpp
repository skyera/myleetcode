// implement strstr()
// 8/31/2017
// Easy
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int strstr(const string &haystack, const string &needle) {
    if (needle.empty()) return 0;

    int n = haystack.size() - needle.size() + 1;

    for (int i = 0; i < n; i++) {
        int j = i;
        int k = 0;
        
        while (j < haystack.size() && k < needle.size() && haystack[j] == needle[k]) {
            j++;
            k++;
        }

        if (k == needle.size()) return i;
    }

    return -1;
}

int main()
{
    string haystack = "abcd";
    string needle = "bc";

    int pos = strstr(haystack, needle);
    assert(pos == 1);

    return 0;
}
