//
// Created by StarkLu on 2023/3/24.
//
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string &s) {
        int dp0 = 0, dp1 = 0;
        for (char c: s) {
            int dp0New = dp0, dp1New = min(dp0, dp1);
            if (c == '1') {
                dp0New++;
            } else {
                dp1New++;
            }
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return min(dp0, dp1);
    }
};

