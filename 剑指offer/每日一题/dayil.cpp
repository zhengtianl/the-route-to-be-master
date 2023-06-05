#include "vector"
#include "unordered_set"
using namespace std;
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> res;
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            res.emplace(nums[i] + nums[j]);
            i++;
            j--;
        }
        return res.size();
        
    }
};