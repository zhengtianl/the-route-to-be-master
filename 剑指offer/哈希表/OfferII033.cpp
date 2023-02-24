//
// Created by 45807 on 2023/2/24.
//
#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        for(auto str: strs){
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it ++)
        {
            ans.emplace_back(it -> second);
        }
        return ans;
    }
};