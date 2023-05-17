
def daima349(nums1,nums2):
    set_num = set(nums1)
    list = []
    for num in nums2:
        if num in set_num:
            list.append(num)
    return set(list)
