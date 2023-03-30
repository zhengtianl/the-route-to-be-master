//
// Created by StarkLu on 2023/3/30.
//
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int res = 0;
        sort(points.begin(), points.end());
        int n = points.size();
        for(int i = 1; i < n; i++)
        {
            res = max(points[i][0] - points[i-1][0], res);
        }
        return res;
    }
};

