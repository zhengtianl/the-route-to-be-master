//
// Created by StarkLu on 2023/6/1.
//
#include "iostream"
#include "string"
#include "vector"
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size(),0);
        getNext(next, s);
        int len = s.size();
        if(next[len - 1] != 0 && len % (len - (next[len - 1])) == 0){
            return true;
        }
        return false;
    }

    void getNext(vector<int> &next, string &s) {
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < s.size(); i++) {
            while (s[i] != s[j] && j > 0) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
};