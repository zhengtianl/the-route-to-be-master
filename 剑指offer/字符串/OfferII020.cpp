#include <iostream>
using namespace std;

bool helper(string s){
    int i = 0;
    int j = s.length() - 1;
    while(i <= j){
        if (s[i] != s[j]){
            return false;
        }else{
            i++;
            j--;
        }
    }
    return true;
}

int countSubstrings(string s){
    int ans = 0;
    string s1;
    for(int i = 0; i < s.length(); i++){
        for(int j = i; j< s.length(); j++){
            if(helper(s.substr(i, j-i+1))){
                ans += 1;
            }
        }
    }
    return ans;
}

int main()
{
    string s = "abc";
    cout << countSubstrings(s) << endl;
}