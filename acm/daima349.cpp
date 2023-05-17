//
// Created by StarkLu on 2023/5/17.
//
#include "iostream"
#include "unordered_set"
#include "vector"
using namespace std;
vector <int>daima349(vector<int> &nums1,vector<int> &nums2)
{
    unordered_set<int> result;
    unordered_set<int> nums_set(nums1.begin(), nums1.end());
    for(int num : nums2)
    {
        if(nums_set.find(num) != nums_set.end())
        {
            result.insert(num);
        }
    }
    return vector<int>(result.begin(), result.end());
}

int main()
{
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> res = daima349(nums1, nums2);
    for (auto num : res){
        cout << num << " ";
    }
    return 0;
}