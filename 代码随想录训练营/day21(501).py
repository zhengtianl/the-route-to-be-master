# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.res = []
        self.travel(root)
        counter = collections.Counter(self.res)
        max_count = max(counter.values())


        return [num for num, count in counter.items() if count == max_count]


    def travel(self, root):
        if root is None: return
        self.travel(root.left)
        self.res.append(root.val)
        self.travel(root.right)