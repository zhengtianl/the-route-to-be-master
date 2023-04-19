//
// Created by StarkLu on 2023/4/19.
//
#include "iostream"
#include "algorithm"
using namespace std;
const int N = 100010;
int n;
int q[N], s[N];//记录出现次数;
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    int res = 0;
    for(int i = 0, j = 0; i < n ; i ++)
    {
        s[q[i]] ++;
        while(j  < i && s[q[i]] > 1)
        {
            s[q[j]] --;
            j ++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}

