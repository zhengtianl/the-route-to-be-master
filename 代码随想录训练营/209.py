def miniLengthArray(s, nums):
    n = len(nums)
    left, right = 0, 0
    res = float('inf')
    cur_sum = 0
    while right < n:
        cur_sum += nums[right]
        while cur_sum >= s: # 当前累加值大于目标值
                res = min(res, right - left + 1)
                cur_sum -= nums[left]
                left += 1
        rigth += 1
    return res if res != float('inf') else 0

n = int(input())
