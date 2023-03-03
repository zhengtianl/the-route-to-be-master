//
// Created by StarkLu on 2023/3/3.
//
#include "vector"
#include "unordered_map"
#include "string"
using namespace std;

class Solution {
public:
    string addSuffix(string name, int k)
    {
        return name + "(" + to_string(k) +")";
    }
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        unordered_map<string, int> cnt;
        for(auto str1: names)
        {
            if(cnt.count(str1) == 0)
            {
                ans.push_back(str1);
                cnt[str1] = 1;
            }
            else
            {
                int k  = cnt[str1];
                while(cnt.count(addSuffix(str1,k))){
                    k++;
                }
                ans.push_back(addSuffix(str1,k));
                cnt[str1] = k + 1;
                cnt[addSuffix(str1,k)] = 1;
            }

        }
        return ans;
    }
};

