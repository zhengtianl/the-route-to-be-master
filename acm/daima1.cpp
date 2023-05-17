//
// Created by StarkLu on 2023/5/17.
//
#include "unordered_map"
#include "iostream"
using namespace std;
vector<pair<int,int>> twoSum(vector<int>nums, int target)
{
    unordered_map <int,int> map;
    vector<pair<int, int>> res;
    for(int i = 0; i < nums.size(); i++)
    {
        auto iter = map.find(target - nums[i]);
        if(iter != map.end())
        {
            res.push_back(make_pair(iter->second, i));
        }
        map[nums[i]] = i;
    }
    return res;
}
int main()
{
    vector<int> nums = {1,2,3,4};
    int target = 5;
    vector<pair<int,int>> res = twoSum(nums, target);
    for (auto pair : res)
    {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    return 0;
}