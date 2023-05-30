//
// Created by StarkLu on 2023/5/30.
//
#include "iostream"
#include "unordered_map"
#include "vector"
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //用hash-map 存数据 key:value , key是值， value是次数；
        int ans = 0;
        unordered_map<int, int> res;
        for(auto num1: nums1){
            for(auto num2: nums2){
                res[num1 + num2]++;
            }
        }

        for(auto num3: nums3){
            for(auto num4: nums4){
                if(res.count(-num3-num4)){
                    ans += res[-num3-num4];
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {5, 6, 7, 8};
    vector<int> nums3 = {9, 10, 11, 12};
    vector<int> nums4 = {13, 14, 15, 16};

    Solution solution;
    int result = solution.fourSumCount(nums1, nums2, nums3, nums4);
    cout << "Result: " << result << endl;

    return 0;
}
