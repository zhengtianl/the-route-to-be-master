#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int ans = INT_MAX;
        int l = 0;
        int sum = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum >= target){
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l ++;
            }
        }
        return ans == INT_MAX ? 0: ans;
    }
};

int main(){
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    Solution s;
    cout << s.minSubArrayLen(7, nums) << endl;
}