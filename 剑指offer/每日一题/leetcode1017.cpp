//
// Created by StarkLu on 2023/4/6.
//
#include "iostream"
#include "string"
using namespace std;
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        int k = 1;
        string ans;
        while (n) {
            if (n % 2) {
                ans.push_back('1');
                n -= k;
            } else {
                ans.push_back('0');
            }
            k *= -1;
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string baseNeg3(int n){
        if(n == 0){
            return 0;
        }
        string res = "";
        while(n != 0)
        {
            char cur_bit = abs(n % 2) + '0';
            n = - (n / 2);
            res = cur_bit + res;

        }
        return res;
    }


};
int main()
{
    Solution s;
    s.baseNeg2(11);
    cout << s.baseNeg2(11) << endl;
}