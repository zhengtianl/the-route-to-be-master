//
// Created by 45807 on 2023/2/25.
//
#include "iostream"
#include "vector"
#include "stack"
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(auto aster:asteroids) {
            bool active = true;
            while(active && aster < 0 && !st.empty() && st.top() > 0) {
                active = st.top() < -aster;
                if (st.top() <= -aster) {
                    st.pop();
                }
            }
            if (active) {
                st.push(aster);
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



