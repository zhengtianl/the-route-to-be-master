//
// Created by StarkLu on 2023/3/12.
//
#include "vector"
#include "functional"
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;  // answer vector to store all valid combinations
        vector<int> temp(k);  // temporary vector to store the current combination

        // helper function to recursively construct all possible combinations of size k
        function<void(int, int)> dfs = [&](int cur, int count) {
            // base case: if the combination is complete, add it to the answer vector
            if (count == k) {
                ans.push_back(temp);
                return;
            }
            // early return: not enough numbers remaining to complete the combination
            if (n - cur + 1 < k - count) {
                return;
            }
            // recursive case 1: include the current number in the combination
            temp[count] = cur;
            dfs(cur + 1, count + 1);
            // recursive case 2: skip the current number and move on to the next
            dfs(cur + 1, count);
        };

        dfs(1, 0);  // start the recursive function at the first number with an empty combination
        return ans;
    }
};
