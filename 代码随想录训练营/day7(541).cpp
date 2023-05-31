//
// Created by StarkLu on 2023/5/31.
//
#include "iostream"
using namespace std;
class Solution{
public:
    string reverseStr(string s, int k){
        int n = s.length();
        //走2k格
        for(int i = 0; i <n; i+=2*k){
            //如果i+k <= s.size()不能越界
            if(i + k <= s.size()){
                reverse(s.begin() + i, s.begin() + i + k);
            }else{
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
