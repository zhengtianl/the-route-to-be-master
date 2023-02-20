数组不能直接删除操作用双指针或者快慢指针的方法
```c++
int binarySearch(vector<int> &nums, target)
int n = nums.size() - 1; 
int l = 0, r = n;
while (l <= r) {
        int mid = (r - l) / 2 + l;
        if(nums[mid] < target ){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return l;
}
````