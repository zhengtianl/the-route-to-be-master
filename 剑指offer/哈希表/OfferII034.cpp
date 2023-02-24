//
// Created by 45807 on 2023/2/24.
//
#include "iostream"
#include "string"
#include "algorithm"
#include "unordered_map"
using namespace std;
bool isAlienSorted(vector<string>& words, string order)
{
    unordered_map<char, int> dic;
    for (int i = 0; i < order.size(); i++) {
        dic[order[i]] = i;
    }
    vector<vector<int>> lst(words.size());
    for (int i = 0; i < words.size(); i++){
        for(char c : words[i]){
            lst[i].emplace_back(dic[c]);
        }
    }
    for (int i = 1; i < words.size(); i++) {
        if (lst[i - 1] > lst[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    cout << isAlienSorted(words, order) << endl;
}