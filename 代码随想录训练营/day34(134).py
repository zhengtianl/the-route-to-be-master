class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        gas1 = sum(gas)
        cost1 = sum(cost)
        if cost1 > gas1:
            return -1
        n = len(gas)
        start = 0
        total = 0
        for i in range(n):
            total += gas[i] - cost[i]
            if total < 0:
                start = i + 1
                total = 0
        return start
