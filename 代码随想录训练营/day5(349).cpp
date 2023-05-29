//
// Created by StarkLu on 2023/5/29.
//
#include "iostream"
#include "unordered_set"
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_set<int> us{ nums1.begin(), nums1.end() };
        for(auto& iter: nums2){
            if(us.find(iter) != us.end()){
                us.erase(iter);
                res.emplace_back(iter);
            }
        }
        return res;
    }
};

