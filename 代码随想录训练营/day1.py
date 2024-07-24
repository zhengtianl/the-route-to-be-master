def search(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    # 二分查找
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if target == nums[mid]:
            return mid
        elif target < nums[mid]:
            right = mid - 1
        else:
            left = mid + 1
    return -1

def removeElement(nums, target):
    slow = 0
    fast = 0
    while slow < fast:
        if nums[slow] != target:
            nums[slow] = nums[fast]
            slow += 1
        fast += 1
    return slow


n = int(input())
nums = [int(input()) for _ in range(n)]
target = int(input())
print(search(nums, target))