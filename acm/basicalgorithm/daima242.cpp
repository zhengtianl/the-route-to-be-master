//
// Created by StarkLu on 2023/5/13.
//
#include "string"
#include "iostream"
using namespace std;
bool isAnagram(string s, string t)
{
    int record[26] = {0};
    for(int i = 0; i < s.size(); i++)
    {
        record[s[i] - 'a'] ++;
    }
    for(int i = 0; i < t.size(); i++)
    {
        record[t[i] - 'a'] --;
    }

    for (int i = 0; i < 26; i++) {
        if (record[i] != 0) {
            // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
            return false;
        }
    }
    return true;
}


int main()
{
    string s, t;
    string s1, t1;
    s = "rat", t = "car";
    cout << isAnagram(s,t) << endl;
}