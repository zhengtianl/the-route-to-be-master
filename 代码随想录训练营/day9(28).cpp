//
// Created by StarkLu on 2023/6/1.
//
#include "iostream"
#include "string"
#include "vector"
using namespace std;

class Solution{
public:
    int strStr(string haystack, string needle){
        //当needle长度为0时直接返回0
        if(needle.length() == 0) return 0;
        int j = 0;
        vector<int> next(needle.size(), 0);
        getNext(next, needle);
        for(int i = 0; i < haystack.length(); i++){
            //当遇到不相等的字符
            while(haystack[i] != needle[j] && j > 0){
                j = next[j - 1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == needle.size()){
                return i - needle.size() + 1 ;
            }
        }
        return -1;
    }


    void getNext(vector<int>& next, string& s){
        //初始化next节点；
        next[0];
        //j指向前缀
        int j = 0;
        for(int i = 1; i < s.size(); i++){
            //当遇到不相同的字符
            while(s[i] != s[j] && j > 0){
                j = next[j-1];
            }
            //当遇到相同字符
            if(s[i] == s[j]){
                j ++;
            }
            //导入next数组
            next[i] = j;
        }
    }
};

int main() {
    Solution s;
    string s1;
    string s2;
    cin >> s1 >> s2;
    int ans = s.strStr(s1, s2);
    cout << ans;
    return 0;
}