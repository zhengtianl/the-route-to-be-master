//
// Created by Zhengtian  on 25/3/2023.
//
#include "vector"
#include "iostream"
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int j = n -1;
        while(j > 0 && arr[j-1] <= arr[j])
        {
            j--;
        }
        if(j == 0)
        {
            return 0;
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            while(j < n && arr[j] < arr[i])
            {
                j++;
            }
            res = min(res, j - i - 1);
            if(i + 1 < n && arr[i] > arr[i+1]){
                break;
            }
        }
        return res;
    }
};