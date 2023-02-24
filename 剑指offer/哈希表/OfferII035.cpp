//
// Created by 45807 on 2023/2/24.
//

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints)
    {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();
        int ans = INT_MAX;
        int t0Minutes = getMinutes(timePoints[0]);
        int preMinutes = t0Minutes;
        for(int i  = 1; i < n; i++){
            int minutes = getMinutes(timePoints[i]);
            ans = min(ans, minutes - preMinutes); // 相邻时间的时间差
            preMinutes = minutes;
        }
        ans = min(ans, t0Minutes + 1440 - preMinutes);
        return ans;
    }
    int getMinutes(string s)
    {
       return( (int(s[0] - '0')* 10 + int(s[1] - '0')) * 60 + int(s[3] - '0') * 10 + int(s[4] - '0'));
    }
};
int main()
{
    Solution s;
    vector<string> timepoints = {"23:59","00:00"};
    int ans = s.findMinDifference(timepoints);
    cout << ans << endl;
}