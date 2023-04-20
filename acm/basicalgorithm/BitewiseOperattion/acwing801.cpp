//
// Created by StarkLu on 2023/4/20.
//
#include "iostream"
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        int res = 0;
        while(x)
        {
            if(x & 1 == 1) res++;
            x >>= 1;
        }
        cout << res << ' ';
    }
}