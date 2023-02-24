//
// Created by 45807 on 2023/2/24.
//
#include <algorithm>
#include <unordered_set>
#include "iostream"
#include "vector"
using namespace std;

int minimumOperations(vector<int>& nums)
{
    int ans = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] > 0){
            for(int j = i + 1; j < n; j++){
                nums[j] -= nums[i];
            }
            ans += 1;
        }
    }
    return ans;
}

int minimumOperations2(vector<int>& nums)
{

}



int main(){
    vector<int> nums = {1,5,0,3,5};
    int m = minimumOperations2(nums);
    cout << m << endl;

}