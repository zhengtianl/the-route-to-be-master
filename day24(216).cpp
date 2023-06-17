//
// Created by StarkLu on 2023/6/17.
//
#include "iostream"
#include "vector"
using namespace std;


class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(int targetSum, int k, int sum, int startIndex){
        if(sum > targetSum){
            return;
        }
        if(path.size() == k){
            if(sum == targetSum) result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++){
            sum += i;
            path.push_back(i);
            backTracking(targetSum, k, sum, i+1);
            sum -= i;
            path.pop_back();
        }

}

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(n, k, 0, 1);
        return result;

    }
};