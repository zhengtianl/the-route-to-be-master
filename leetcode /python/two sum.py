def twoSum(nums:[], target:int):
    hashtable = {} #create hashtable
    for i, num  in enumerate(nums): #create the nums with tag
        
        if target - num in hashtable:
            return [hashtable[target - num], i]
        hashtable[nums[i]] = i
    return  []
print(twoSum(nums = [1,2,4,5], target=6))

