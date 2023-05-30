from collections import Counter
class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        countAB = Counter( u + v for u in nums1 for v in nums2)
        ans = 0
        for x in nums3:
            for z in nums4:
                if -x-z in countAB:
                    ans += countAB[-x-z]
        return ans