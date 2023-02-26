#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fib(int n) {
        int dp[n+2]; //dp数组，数组要多开两个数因为数组后面有个/n
        dp[0] = 0;  //dp数组的初始之
        dp[1] = 1;
        for(int i = 2; i <= n; i ++){ //循环的开始
            dp[i] = dp[i-1] + dp[i-2]; //状态转移
        }
        return dp[n];
    }
};