//
// Created by 45807 on 2023/2/16.
//
#include <iostream>
#include "vector"
using namespace std;

int helper(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size();
    while(l <= r){
        int mid = (r - l)/2  + l;
        if(nums[mid] < target ){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return r+1; //找到等于target的数
}

vector<int> searchrange(vector<int> &nums, int target)
{
    int l  = helper(nums, target);
    if( l == nums.size() || nums[l] != target){
        return {-1,-1};
    }
    int r = helper(nums, target + 1) - 1; //如果存在说明一定是两个找比他大的前一个就可以了
    return {l, r};
}




int main()
{
    vector<int> nums = {5,8,7,8,9,10};
    int target = 8;
    vector<int> ans = searchrange(nums, target);
    for (auto i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
