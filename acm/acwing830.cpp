//
// Created by StarkLu on 2023/5/1.
//
#include "iostream"
#include "algorithm"
using namespace std;
const int N = 1000010;
int stk[N], tt;

int main()
{
    int n;
    cin >> n;
    while(n -- )
    {
        int x;
        cin >> x;
        while(tt && stk[tt] >= x) tt--;
        if(!tt) ::printf("-1 ");
        else ::printf("%d ", stk[tt]);
        stk[++ tt] = x;
    }
    return 0;
}