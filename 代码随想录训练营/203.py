class linkList:
    def __init__(self):
        self.val = None
        self.next = None
        



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
n = int(input())
nums = [int(input()) for _ in range(n)]
val = int(input())
print(removeElements(nums, val))