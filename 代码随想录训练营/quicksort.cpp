#include "iostream"
#include "algorithm"
using namespace std;
void quickSort(int q[],int l,int r){
    //递归结束条件
    int i  = l;
    int j = r;
    if (i >= j) return;
    int mid = q[l];
    while( i < j){
        if (q[i] <= mid){
            i ++;
        }
        if (q[j] >= mid){
            j --;
        }
        if(i < j){
            swap(q[i], q[j]);
        }
    }
    quickSort(q, l, j - 1);
    quickSort(q, j+1, r);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i =  0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}