//
// Created by 45807 on 2023/2/17.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};



int main()
{
    vector<int> nums = {1,2,3,4,5,6};
    Solution s;
    vector<int> ans = s.sortedSquares(nums);
    for(auto vec : ans){
        cout << vec << endl;
    }
    return 0;


}
