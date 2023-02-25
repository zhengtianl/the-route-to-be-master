//
// Created by 45807 on 2023/2/25.
//
#include "string"
#include "iostream"

using namespace std;
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        int n = s1.length();
        for(int i = 0; i < n; i++){
            if(s1[i] == 'x' && s2[i] == 'y'){
                xy += 1;
            }
            if(s1[i] == 'y' && s2[i] == 'y'){
                yx += 1;
            }
        }
        return (xy + yx) % 2 == 1 ? -1 : xy / 2 + yx/2 + xy % 2 + yx % 2;
    }
};
int main(){
    Solution s;
    int c;
    cin >> c;
    while(c--){
        string s1;
        string s2;
        cin >> s1 >> s2;
        int ans;
        ans = s.minimumSwap(s1, s2);
        cout << ans << endl;
    }
    return 0;
}