//
// Created by 45807 on 2023/2/22.
//
#include <iostream>

using namespace std;

const int N = 100010;

int p[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    while (m -- )
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (*op == 'M') p[find(a)] = find(b); //先并再查
        else
        {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    cout << find(1);
    return 0;
}
