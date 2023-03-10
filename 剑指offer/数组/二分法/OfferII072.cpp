//
// Created by StarkLu on 2023/3/10.
//
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        while(l  <= r){
           int mid = (r - l) / 2 + l;
           if (mid * mid < x){
               r = mid - 1;
           }
           else{
               l = mid + 1;
           }
        }
        return r;

    }
};