// Longest common prefix
// 9/2/2017
// Easy
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

string longestcommonprefix(vector<string> &strs) {
    if (strs.empty()) return "";

    for (int i = 0; i < strs[0].size(); i++) {
        for (int j = 1; j < strs.size(); j++) {
            if (strs[0][i] != strs[j][i])
                return strs[0].substr(0, i);
        }
    }

    return strs[0];
}


int main()
{
    vector<string> strs;

    strs.push_back("abcdef");
    strs.push_back("abc");
    strs.push_back("abcf");

    string prefix = longestcommonprefix(strs);
    assert(prefix == "abc");
    
    return 0;
}
