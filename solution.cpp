#include <iostream>

#include "solution.h"

using namespace std;

int Solution::romanToInt(const string &s) const
{
    vector<pair<char, int>> components;

    for (auto it = s.rbegin(); it != s.rend(); ++it)
    {
        cout << "next symbol: " << *it << "\n";
        const auto found = m_symbols.find(*it);
        if (found != m_symbols.end())
        {
            char symbol{found->first};
            int value{found->second};
            cout << "symbol: " << symbol << ", "
                 << "value: " << value << "; ";
            // Handle case subtraction
            if (!components.empty())
            {
                auto pair = components.rbegin();
                cout << "components { " << pair->first << ", " << pair->second << " }\n";
                switch (pair->first)
                {
                case 'V':
                case 'X':
                {
                    if (symbol == 'I')
                    {
                        const auto newPair = make_pair(pair->first, pair->second - 1);
                        *pair = newPair;
                    }
                    else
                    {
                        components.emplace_back(symbol, value);
                    }
                    break;
                }
                case 'L':
                case 'C':
                    if (symbol == 'X')
                    {
                        const auto newPair = make_pair(pair->first, pair->second - 10);
                        *pair = newPair;
                    }
                    else
                    {
                        components.emplace_back(symbol, value);
                    }
                    break;
                case 'D':
                case 'M':
                {
                    if (symbol == 'C')
                    {
                        const auto newPair = make_pair(pair->first, pair->second - 100);
                        *pair = newPair;
                    }
                    else
                    {
                        components.emplace_back(symbol, value);
                    }
                    break;
                }
                default:
                    components.emplace_back(symbol, value);
                }
            }
            else
            {
                components.emplace_back(symbol, value);
                cout << "\n";
            }
        }
    }

    // Calculate
    int result{0};

    for (const auto &p : components)
    {
        result += p.second;
    }

    return result;
}

string Solution::longestCommonPrefix(const vector<string> &strs) const
{
    if (strs.empty())
    {
        return "";
    }

    string result;
    unordered_map<char, size_t> chars;

    for (auto idx = 0; idx < strs[0].size(); ++idx)
    {
        const auto c = strs[0][idx];
        size_t flag{0};
        for (const auto &str : strs)
        {
            if (str.size() == idx)
            {
                return result;
            }
            else if (str[idx] == c)
            {
                ++flag;
            }
        }

        if (flag == strs.size())
        {
            result.push_back(c);
        }
        else
        {
            return result;
        }
    }

    return result;
}
