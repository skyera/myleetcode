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

string longestcommonprefix2(vector<string> &strs) {
    if (strs.empty()) return "";
    
    int right_most = strs[0].size() - 1;
    for (int i = 1; i < strs.size(); i++) {
        for (int j = 0; j <= right_most; j++) 
            if (strs[i][j] != strs[0][j])
                right_most = j - 1;
    }

    return strs[0].substr(0, right_most + 1);
}


int main()
{
    vector<string> strs;

    strs.push_back("abcdef");
    strs.push_back("abc");
    strs.push_back("abcf");

    string prefix = longestcommonprefix(strs);
    assert(prefix == "abc");
    
    prefix = longestcommonprefix2(strs);
    assert(prefix == "abc");
    return 0;
}
