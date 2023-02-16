````C++
int l = 0;
int r = n;
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