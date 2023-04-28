#include "iostream"
using namespace std;
const int N = 1000010;

int m;
int stk[N], tt;
int main()
{
    cin >> m;
    while( m-- )
    {
        string op;
        int x;
        cin >> op;
        if(op == "push")
        {
            cin >> x;
            stk[++ tt] = x;
        }
        else if(op == "pop") --tt;
        else if(op == "empty") cout << (tt ? "No" : "Yes") << endl;
        else cout << stk[tt] << endl;
    }
    return 0;
}