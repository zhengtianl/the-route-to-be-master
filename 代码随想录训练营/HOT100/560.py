class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        dic = {0:1}
        sums, res = 0, 0
        for num in nums:
            sums += num
            res += dic.get(sums - k, 0)
            dic[sums] = dic.get(sums, 0) + 1
        return res
            
            