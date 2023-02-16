#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int ans = nums.size(); // initialize ans to the size of the vector (i.e., the index where target would be inserted if it is greater than all the elements in the vector)
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

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int ans = searchInsert(nums, target);
    cout << ans << endl;
    return 0;
}
