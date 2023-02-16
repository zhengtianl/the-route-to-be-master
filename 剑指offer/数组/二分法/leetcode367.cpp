//
// Created by 45807 on 2023/2/16.
//
#include "iostream"
using namespace std;
bool isPerfectSquare(int num) {
    int l = 0;
    int r = num;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (mid * mid < num) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }

    }
    return l*l == num;
}


int main()
{
    int num = 16;
    cout << isPerfectSquare(num) << endl;
    return 0;
}