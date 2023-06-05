//
// Created by StarkLu on 2023/6/5.
//
#include <vector>
#include <algorithm>
#include "deque"
#include "iostream"
using namespace std;

class Myqueue{
public:
    deque<int> dq;
    void pop(int x){
        if(!dq.empty() && x == dq.front()){
            dq.pop_front(); //只有是最大值的时候才pop
        }

    }

    void push(int x){
        while(!dq.empty() && x > dq.back()){
            dq.pop_back();
        }
        dq.push_back(x);
    }

    int max_elements(){
        return dq.front();
    }


};

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Myqueue q;
        vector<int> res;
        for(int i = 0; i < k; i++){
            q.push(nums[i]);
        }
        res.push_back(q.max_elements());
        for(int i = k; i < nums.size(); i++){
            q.pop(nums[i - k]);
            q.push(nums[i]);
            res.push_back(q.max_elements());
        }
        return res;

    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = s.maxSlidingWindow(nums, 3);
    for(auto num: ans){
        cout << num << endl;
    }
}





