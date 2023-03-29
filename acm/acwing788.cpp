//
// Created by Zhengtian  on 29/3/2023.
//
#include "iostream"
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int a[N], tmp[N];
LL merge_sort(int q[],int l,int r)
{
    if( l >= r) return 0;
    int mid = l + r >> 1;
    int k = 0, i = l, j = mid + 1;
    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else
        {
            res += mid - i + 1;
            tmp[k ++ ] = q[j ++ ];
        }
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    cout << merge_sort(a, 0, n - 1) << endl;
    return 0;
}
