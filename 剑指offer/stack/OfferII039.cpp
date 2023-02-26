//
// Created by 45807 on 2023/2/26.
//
#include "iostream"
#include "vector"
#include "stack"
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> index;
        index.emplace(-1);
        int n = heights.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = index.top();
            while(j != -1 && heights[i] < heights[j]){
                index.pop();
                int left = index.top();
                ans = max(ans, (i - left - 1) * heights[j]);
                j = left;
            }

            index.emplace(i);
        }
        return ans;
    }
};

int main(){

    Solution s;
    vector<int> height = {2,4};
    s.largestRectangleArea(height);

}