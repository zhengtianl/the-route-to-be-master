#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int subarraySum(vector<int>& nums, int k)
{
    int sum = 0;
    unordered_map<int, int> mp;
    int n = nums.size();
    mp[0] = 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(mp.find(sum - k) != mp.end()){
            ans += 1;
        }
        mp[sum]++;
    }
    return ans;
}
int main()
{

}