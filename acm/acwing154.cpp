#include <iostream>
using namespace std;
const int N = 1000100;
//单调队列一般用双端队列保证其单调性
int a[N], q[N], n, k;
//队头和队尾，在队尾插入，队头获取
int front = 0, tail = -1;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    //先找每个窗口的最小值
    for (int i = 0; i < n; i++) {
        //如果当前队头在数组的下标小于当前窗口的最小下标，这个窗口就不包含这个元素了那么无论如何都要剔除队头这个元素
        //所以要在队头删除这个元素
        if (front <= tail && i - k + 1 > q[front]) front++;
        //保证单调性，在队尾删除（为什么要在队尾删除，简单来说在队头删除不能保证单调
        //比如-3 5为当前队列，当前的元素为3，如果在队头操作，那么按照a[i] <= a[q[front]，有3 > -3，因此不做删除操作
        //但是接下来就出现问题了，3就要入队了。此时队列就是-3 5 3，不符合单调性了！
        //但如果在队尾操作，按照a[i] <= a[q[tail]，有3 < 5，就要让5出队
        //之后3入队，队列就是-3 3，满足单调性
        while (front <= tail && a[i] <= a[q[tail]]) tail--;
        q[++tail] = i;
        //队头为窗口的最小值
        if (i >= k - 1) printf("%d ", a[q[front]]);
    }
    printf("\n");
    //这次找最大值，同理
    front = 0, tail = -1;
    for (int i = 0; i < n; i++) {
        if (front <= tail && i - k + 1 > q[front]) front++;
        while (front <= tail && a[i] >= a[q[tail]]) tail--;
        q[++tail] = i;
        if (i >= k - 1) printf("%d ", a[q[front]]);
    }
}
