#include "iostream"
#include "unordered_set"
#include "vector"
using namespace std;
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        unordered_set<int> set;
        for(int i = 0; i < n-1; i++)
        {
            sum = nums[i] + nums[i+1];
            if(set.count(sum)){
                return true;
            }
            set.insert(sum);
        }
        return false;
        
    }
};