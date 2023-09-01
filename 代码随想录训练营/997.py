def sortElements(nums):
    n = len(nums)
    for i in range(n):
        nums[i] = abs(nums[i]) ** 2
    nums.sort()
    return nums

n = int(input())
nums = [int(x) for x in input().split()]
print(sortElements(nums))
