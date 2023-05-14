//
// Created by StarkLu on 2023/5/14.
//
#include "vector"
#include "algorithm"
#include "iostream"
using namespace std;
int removeElement(vector<int>& nums, int val)
{
    int size = nums.size();
    int slowIndex = 0;
    for(int fastIndex = 0; fastIndex < size; fastIndex++)
    {
        if(nums[fastIndex] != val){
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    return slowIndex;
}


int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    cout << removeElement(nums,val) << endl;
}