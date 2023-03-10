#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int x = 0;
        for(int i  = 0; i < nums.size(); i++)
        {
            x +=  nums[i];
            x %= p;
        }
        if (x == 0) return 0;
        int y = 0, res = nums.size();
        unordered_map<int, int> index;
        for(int i = 0 ; i < nums.size(); i++)
        {
            index[y] = i;
            y = (y + nums[i]) % p;
            if(index.count((y - x + p) % p) > 0)
            {
                res = min(res, i - index[(y - x + p) % p] + 1);
            }
        }
        return res == nums.size() ? -1 : res;
    }
};

int main() {
    vector<int> nums = {3, 1, 4, 2};
    int p = 5;
    Solution s;
    cout << s.minSubarray(nums, p) << endl;
    return 0;
}
