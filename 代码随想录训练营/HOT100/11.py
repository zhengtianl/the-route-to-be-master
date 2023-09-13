#给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
def rain(nums):
    left =  0
    right = len(nums) - 1
    left_max = 0
    right_max = 0
    ans = 0
    while left < right:
        left_max = max(left_max, nums[left])
        right_max = max(right_max, nums[right])
        if nums[left] < nums[right]:
            ans += left_max - nums[left]
            left += 1
        else:
            ans += right_max - nums[right]
            right -= 1
    return ans