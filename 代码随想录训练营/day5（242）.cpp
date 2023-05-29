//
// Created by StarkLu on 2023/5/29.
//
#include "iostream"
#include "string"
#include "unordered_map"
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> tcount;
        for(auto s1:s){
            tcount[s1] ++;
        }
        for(auto s2: t) {
            if (tcount.find(s2) == tcount.end()) {
                return false;
            }
            tcount[s2]--;
        }
            for(auto [key,value]: tcount){
                if (value != 0){
                    return false;
                }
            }

        return true;

    }
};