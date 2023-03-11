//
// Created by StarkLu on 2023/3/11.
//
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
class Solution {
public:
    int findKthLargest1(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1]; // 快排
    }

    int findKthLargest2(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num : nums)
        {
            pq.push(num);
            if (pq.size() > k){
                pq.pop();
            }
        }
        return pq.top(); //堆排

    }
};