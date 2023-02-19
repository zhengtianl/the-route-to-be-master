
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int total = 0;
        for (int i = 0; i < n; ++i) {
            total  += nums[i];
        }

        for(int i = 0; i < n; i++)
        {
            if(nums[i] + 2*sum == total) {
                return i;
            }
            sum += nums[i];
        }

        return -1;

    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    int n = s.pivotIndex(nums);
    cout << n << endl;

}