class Solution:
    def deleteGreatestValue(self, grid: List[List[int]]) -> int:
        #对每一行排列
        sorted_grid = [sorted(row) for row in grid]
        #取每一列最大的数
        max_col = [max(col) for col in zip(*sorted_grid)]
        #返回最大数的和
        return sum(max_col)
        
        