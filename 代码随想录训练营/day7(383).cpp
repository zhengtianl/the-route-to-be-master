//
// Created by StarkLu on 2023/5/30.
//
#include "iostream"
#include "string"
#include "unordered_set"
#include "vector"
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();
        if (n > m) return false;
        vector<int> cnt(26);
        for (auto char1: magazine){
            cnt[char1 - 'a'] ++;
        }
        for(auto char2 : ransomNote){
            cnt[char2 - 'a'] --;
            if(cnt[char2 - 'a'] < 0){
                return false;
            }
        }
        return true;




    }
};