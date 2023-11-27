def longestConsecutive(nums):
    res = 0
    num_set = set(nums)
    for num in num_set:
        if num - 1 not in num_set:
            current_num = num
            current_streak = 1

            while current_num + 1 in num_set:
                current_num += 1
                current_streak += 1
            
            res = max(current_streak, res)
    return res