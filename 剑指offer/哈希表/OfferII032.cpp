//
// Created by 45807 on 2023/2/24.
//
#include "iostream"
#include "string"
#include "unordered_map"

using namespace std;
bool isAnargam(string s, string t)
{
    if(s == t || s.length() != t.length()){
        return false;
    }
    unordered_map<char, int> count;
    for(auto ch: s){
        count[ch] ++;
    }
    for(auto ch : t){
        count[ch] --;
        if(count[ch] < 0){
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "rat";
    string t = "car";
    cout << isAnargam(s,t) << endl;
}