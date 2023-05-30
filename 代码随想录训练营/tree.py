class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def preorderTraversal(self, root: TreeNode):
        def preoder(root:TreeNode):
            if not root:
                return
            res.append(root.val)
            preoder(root.left)
            preoder(root.right)

        res = list()
        preoder(root)
        return res

