#include <iostream>
#include <vector>
#include <string>

#include "solution.h"

using namespace std;

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.longestCommonPrefix({"flower", "flow", "flight"}) << endl;
    cout << s.longestCommonPrefix({"dog", "racecar", "car"}) << endl;
}
