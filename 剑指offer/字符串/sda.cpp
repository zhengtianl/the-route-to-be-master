//
// Created by 45807 on 2023/2/21.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15;

int n, m;
int a[N], b[N];
bool st[N];
int res = N;

void dfs(int u, int hp, int cnt)
{
    if(hp <= 0) {
        res = min(res, cnt);
        return ;
    }

    if(u == n + 1) return ;

    for(int i = 1; i <= n; i ++)
    {
        if(!st[i])
        {
            st[i] = true;
            if(hp <= b[i]) dfs(u + 1, hp - a[i] * 2, cnt + 1);
            else dfs(u + 1, hp - a[i], cnt + 1);
            st[i] = false;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

        res = N;
        memset(st, false, sizeof st);
        dfs(0, m, 0);

        if (res == N) puts("-1");
        else cout << res << endl;
    }

    return 0;

}