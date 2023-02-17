//
// Created by 45807 on 2023/2/17.
//

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int slow = 0;
    int fast = 0;
    for(; fast < nums.size(); fast++)
    {
        if(nums[fast] != nums[slow]){
            nums[slow++] = nums[fast];
        }
    }
    return slow;

}

int main()
{
    vector<int> nums = {3,2,2,3};
    int val = 3;
    cout << removeElement(nums,val) << endl;
    return 0;
}
