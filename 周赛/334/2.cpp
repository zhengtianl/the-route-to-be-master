//
// Created by 45807 on 2023/2/26.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long x = 0;
        vector<int> ans;
        for(auto c: word){
            x = (x*10 + int(c - '0'))  % m;
            if (x == 0){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};