#pragma once

#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(const std::string &s, const std::vector<std::string> &wordDict)
    {
        std::unordered_set<std::string> wordDictSet(wordDict.begin(), wordDict.end());

        std::string substring;
        for (size_t sIndex = 0; sIndex < s.size(); ++sIndex) {
            substring += s[sIndex];

        }
    }
};