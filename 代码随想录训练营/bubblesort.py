def bubblesort(nums):
    n = len(nums)
    for i in range(1,n):
        for j in range(0,n - i):
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j + 1], nums[j]
    return nums[0]