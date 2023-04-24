#include "iostream"
using namespace std;
const int N = 100010;
// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储当前已经用到了哪个点
int head, e[N], ne[N], idx;
void init()
{
    head = -1;
    idx = 0;
}
void add_to_head(int x)
{
    e[idx] = x, ne[idx] = head, head = idx ++ ;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

void add(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++ ;
}

int main()
{
    int m;
    cin >> m;
    init();
    while(m --)
    {
        int k, x;
        char op;
        cin >> op;
        if( op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D')
        {
            /* code */
            cin >> k;
            if (!k) head = ne[head];
            else remove(k-1);
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);
        }   
    }
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;
    return 0;
}