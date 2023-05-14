//
// Created by StarkLu on 2023/5/14.
//
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int search(vector<int> nums, int n)
{
    sort(nums.begin(), nums.end());
    int r  = nums.size();
    int l = 0;
    while(l <= r)
    {
        int mid = l + ((r - l) / 2);
        if(nums[mid] < n)
        {
            l = mid + 1;
        }else if(nums[mid] > n) {
            r = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
}
int main()
{
    cout << search({-1,0,3,5,9,12},9) << endl;
}