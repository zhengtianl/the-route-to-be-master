//
// Created by StarkLu on 2023/5/24.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        //{1,2,2,4}
        int slow = 0;

        for(int fast = 0; fast < nums.size(); fast++)
        {
            if(nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }

};


int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val =2;
    Solution s;
    cout << s.removeElement(nums, val) << endl;
}