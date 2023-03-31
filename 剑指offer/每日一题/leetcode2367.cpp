//
// Created by StarkLu on 2023/3/31.
//
#include "iostream"
#include "vector"
#include "unordered_set"
using namespace std;
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int res = 0;
        unordered_set<int> set;
        for(int num : nums){
            set.insert(num);
        }
        for(int num : nums){
            if(set.count(num+diff) && set.count(num - diff)){
                res += 1;
            }
        }
        return res;
    }
};

