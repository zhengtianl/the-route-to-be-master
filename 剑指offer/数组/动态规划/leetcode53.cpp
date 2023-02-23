//
// Created by 45807 on 2023/2/23.
//
#include "iostream"
#include "vector"
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    return ans;
}

int main()
{
    vector<int> ans = {-2,1,-3,4,-1,2,1,-5,4};
    int m = maxSubArray(ans);
    cout  << m << endl;
}