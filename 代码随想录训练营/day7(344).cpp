//
// Created by StarkLu on 2023/5/31.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution{
public:
    void reverseString(string& s){
        int l = 0;
        int r = s.size() - 1;
        while(l <= r){
            swap(s[l], s[r]);
            l ++ ;
            r --;
        }
    }
};

int main(){
    Solution s;
    string res = "abddsds";
    s.reverseString(res);
    cout << res << endl;
}