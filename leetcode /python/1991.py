from pandas import pivot


def pivotIndex(nums : list):
    sums = sum(nums)
    left = 0
    for i in range(len(nums)):
        if left * 2 + nums[i] == sums:
            return i
        else :
            left += nums[i]
    return -1

print(pivotIndex([1,2,3,4,5,6]))
print(pivotIndex([1,7,3,6,5,6]))