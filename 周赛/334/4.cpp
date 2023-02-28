#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        //讨论偶数位小于奇数位
        for(int i = 0; i < n; i+=2)
        {
            int left = i > 0 ? nums[i-1]: INT_MAX;
            int right = i < n - 1 ? nums[i+1]: INT_MAX;
            int diff = nums[i] - min(left, right);
            if(diff >= 0) cnt1 += diff + 1;
        }
        //讨论奇数位小于偶数位
        for(int i = 1; i < n; i += 2)
        {
            int left = i > 0 ? nums[i-1]: INT_MAX;
            int right = i < n-1 ? nums[i+1] : INT_MAX;
            int diff = nums[i] - min(left, right);
            if (diff >= 0) cnt2 += diff + 1;
        }
        return min(cnt1, cnt2);
    }
};

int main(){
    vector<int> nums = {7,4,8,9,7,7,5};
    Solution s;
    cout << s.movesToMakeZigzag(nums) << endl;
}