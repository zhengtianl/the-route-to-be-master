//
// Created by 45807 on 2023/2/25.
//
#include "vector"
#include "stack"
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int index = s.top();
                ans[index] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
}; //stack存放下标，寻找个数就是寻找小下标的差值。