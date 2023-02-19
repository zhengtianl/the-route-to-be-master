#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findmaxLength(vector<int>& nums){
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            sum += 1;
        }else{
            sum -= 1;
        }
        if(mp.find(sum) != mp.end()){
            ans = max(ans, i -  mp[sum]);
        }
        else{
            mp[sum] = i;
        }
    }
    return ans;

}

int main()
{
    vector<int> nums = {0,0,1,0,0,0,1,1};
    int n = findmaxLength(nums);
    cout << n << endl;

}