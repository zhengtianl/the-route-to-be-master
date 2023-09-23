#include "iostream"
#include "algorithm"
using namespace std;
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main()
{
    int q[10] = {1, 3, 2, 4, 5, 6, 7, 8, 9, 0};
    quick_sort(q, 0, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << q[i] << " ";
    }
    return 0;
}