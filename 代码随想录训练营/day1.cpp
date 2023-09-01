#include <vector>
#include <iostream>
using namespace std;

int search(vector<int>& nums, int target)
{
    int l = 0;
    int r =nums.size() - 1;
    while( l <= r)
    {
        int mid = ((r -l)>>1) + l;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main()
{
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int target = 9;
    cout << search(nums, target) << endl;
}