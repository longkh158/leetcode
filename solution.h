#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#pragma once

class Solution
{
private:
    std::unordered_map<char, int> m_symbols{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(const std::string &) const;
    std::string longestCommonPrefix(const std::vector<std::string> &) const;
    int removeDuplicates(const vector<int> &) const;
};