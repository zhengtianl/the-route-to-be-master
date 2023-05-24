#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums = {1, 2, 0}; // 数组长度为3，索引范围是0到2
    int val = 0; // 假设要比较的值为0

    int slow = 0;
    int fast = 0;

    while (fast < nums.size()) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++; // 在这里仅递增 fast

    }

    return slow;
}
