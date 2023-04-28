#include "iostream"
#include "string"
using namespace std;
int m;
const int N = 1000010;
int q[N], hh, tt = -1;

int main(){
    cin >> m;
    while(m --)
    {
        string op;
        int x;
        cin >> op;
        if(op == "push")
        {
            cin >> x;
            q[++ tt] = x;
        }
        else if (op == "empty")
        {
            cout << (hh <= tt ? "NO" : "YES") << endl;
        }
        else if (op == "pop")
        {
            hh ++ ;
        }
        else if (op == "query")
        {
            cout << q[hh] << endl;
        }
    }
}