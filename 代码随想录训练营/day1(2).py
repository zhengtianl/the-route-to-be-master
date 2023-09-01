def removeElements(nums, val):
    """
    203. 移除链表元素
    https://leetcode-cn.com/problems/remove-linked-list-elements/
    """
    slow = 0
    fast = 0
    n  = len(nums)
    for fast in range(n):
        if nums[fast] != val:
            nums[slow] = nums[fast]
            slow += 1
    return slow
nums = [3,2,2,3]
val = 3
print(removeElements(nums, val))