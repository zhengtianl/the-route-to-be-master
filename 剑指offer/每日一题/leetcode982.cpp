#include "unordered_map"
#include "iostream"
using namespace std;

class Solution 
{
public:
    int countTriplets(vector<int>& nums) 
    {
        int ans = 0;
        unordered_map<int, int> cnt(1<<16);
        for(int x:nums)
        {
            for(int y: nums)
            {
                ++cnt[x & y];
            }
        }

        for(int x: nums)
        {
            for(int j = 0; j < (1 << 16); j++)
            {
                if((x & j) == 0)
                {
                    ans += cnt[j];
                }
            }
        }
        return ans;
    }
};