//
// Created by 45807 on 2023/2/16.
//
#include "iostream"
using namespace std;
int mySqrt(int x){
    int l = 0;
    int r = x;
    while( l <= r){
        int mid = (r -l)/2 + l;
        if((long long)mid * mid <= x){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return r;
}

int main(){
    int x = 8;
    int ans = mySqrt(x);
    cout << ans << endl;
}