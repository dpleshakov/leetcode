#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if ((s.empty() && t.empty()) || s.empty()) {
            return true;
        }

        unsigned int sIndex1 = 0;
        unsigned int tIndex = 0;
        while (sIndex1 < s.length() && tIndex < t.length() && (s.length() - sIndex1 <= t.length() - tIndex)) {
            if (s.at(sIndex1) == t.at(tIndex)) {
                if (sIndex1 + 1 == s.length()) {
                    return true;
                }
                ++sIndex1;
            } else {
                if (tIndex + 1 == t.length()) {
                    return false;
                }
            }
            ++tIndex;
        }
        
        return false;
    }
};