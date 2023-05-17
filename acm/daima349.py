
def daima349(nums1,nums2):
    set_num = set(nums1)
    list = []
    for num in nums2:
        if num in set_num:
            list.append(num)
    return set(list)
print(daima349([1,2,2,1], [2,2]))