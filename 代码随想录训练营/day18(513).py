import collections
class TreeNode:
    def __int__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findBottomLeftValue(self, root):
        if root is None:
            return 0
        q = collections.deque()
        res = 0
        q.append(root)
        while q:
            size = len(q)
            for i in range(size):
                node = q.popleft()
                if i == 0:
                    result = node.val
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)

        return result
            