#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(const string& s, int low, int high) {
    for (int i = low, j = high; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s)
{
    int l = 0, r = s.length() - 1;
    while( l  <= r){
        if(s[l] == s[r]){
            l ++;
            r --;
        }else{
            return checkPalindrome(s,l+1,r) || checkPalindrome(s,l,r-1);
        }

    }
    return true;
}


int main(){
    string a;
    cin >> a;
    cout << validPalindrome(a) << endl;

}