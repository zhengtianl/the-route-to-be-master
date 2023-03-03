//
// Created by StarkLu on 2023/3/3.
//
#include "string"
#include "vector"
using namespace std;

class Solution {
public:
    int strStr1(string haystack, string needle) {
        if(haystack.find(needle) == string::npos){
            return -1;
        }
        return haystack.find(needle);
    }


    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) {
            return 0;
        }
        vector<int> lps(m, 0);
        computeLPS(needle, lps);
        int i = 0, j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return i - j;
            }
            else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j-1];
                }
                else {
                    i++;
                }
            }
        }
        return -1;
    }

    void computeLPS(string needle, vector<int>& lps) {
        int m = needle.size();
        int len = 0;
        int i = 1;
        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len-1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};