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
        right += 1
    return res if res != float('inf') else 0

s = int(input())
nums = [int(x) for x in input().split()]
print(miniLengthArray(s, nums))
