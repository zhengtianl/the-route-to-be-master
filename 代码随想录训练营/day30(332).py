from typing import List
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        tickets.sort() # 先排序，这样一旦找到第一个可行路径，一定是字母排序最小的
        used = [0] * len(tickets)
        path = ['JFK']
        results = []
        self.backtracking(tickets, used, path, 'JFK', results)
        return results[0]

    def backtracking(self, tickets, used, path, cur, results):
        if len(path) == len(tickets) + 1:  # 终止条件：路径长度等于机票数量+1
            results.append(path[:])  # 将当前路径添加到结果列表
            return True

        for i, ticket in enumerate(tickets):  # 遍历机票列表
            if ticket[0] == cur and used[i] == 0:  # 找到起始机场为cur且未使用过的机票
                used[i] = 1  # 标记该机票为已使用
                path.append(ticket[1])  # 将到达机场添加到路径中
                state = self.backtracking(tickets, used, path, ticket[1], results)  # 递归搜索
                path.pop()  # 回溯，移除最后添加的到达机场
                used[i] = 0  # 标记该机票为未使用
                if state:
                    return True  # 只要找到一个可行路径就返回，不继续搜索
