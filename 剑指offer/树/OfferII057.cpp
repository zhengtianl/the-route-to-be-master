#include "set"
#include "vector"
#include "math.h"
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> st;
        for (int i = 0; i < nums.size(); ++i) 
        {
            int lowerLimit = max(nums[i], INT_MIN + t) - t;//这个数满足限定值t的上下界
            int upperLimit = min(nums[i], INT_MAX - t) + t;
            auto it = st.lower_bound(lowerLimit);//找在nums[i]-t到nums.end前后内，满足要求的最小数
            if (it != st.end() && *it <= upperLimit) //这个数存在，且在nums[i]+t范围内
                return true;
            st.insert(nums[i]);
            if (i >= k) 
                st.erase(nums[i - k]);//把超过k索引范围的都删除，最后set中存的查询数都是满足i-j<=k
        }
        return false;
    }
};