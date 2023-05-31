from collections import Counter


class TreeNode:
    def __int__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right




class Solution:
    def fourSumCount(self, nums1: int, nums2: int, nums3: int, nums4: int) -> int:
        countAB = Counter(u + v for u in nums1 for v in nums2)
        ans = 0
        for x in nums3:
            for z in nums4:
                if -x-z in countAB:
                    ans += countAB[-x-z]
        return ans