//
// Created by StarkLu on 2023/5/8.
//
#include "iostream"
using namespace std;
const int N = 100010, M = 300000000;
int son[M][2], idx;
int n;
int a[N];

int brute_search(int a[N])
{
    int res = 0;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res = max(res, a[i] ^ a[j]);
    cout << res << endl;
    return 0;
}
void insert(int x)
{
    int p=0;  //根节点
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;   /////取X的第i位的二进制数是什么  x>>k&1(前面的模板)
        if(!son[p][u]) son[p][u]=++idx; ///如果插入中发现没有该子节点,开出这条路
        p=son[p][u]; //指针指向下一层
    }
}
int query(int x)
{
    int p=0;int res=0;
    for(int i=30;i>=0;i--)
    {                               ///从最大位开始找
        int u=x>>i&1; ///第i位是0还是1
        if(son[p][!u]) ////如果当前层有对应的不相同的数
        {   ///p指针就指到不同数的地址

            p=son[p][!u];
            res=res*2+1;
            ///*2相当左移一位  然后如果找到对应位上不同的数res+1 例如    001
        }                                                       ///       010
        else                                            ////          --->011                                                                           //刚开始找0的时候是一样的所以+0    到了0和1的时候原来0右移一位,判断当前位是同还是异,同+0,异+1
        {
            p=son[p][u];
            res=res*2+0;
        }
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for(int i = 0; i < n; i++) res = max(res, query(a[i]));

    cout << res << endl;
    return 0;
}
