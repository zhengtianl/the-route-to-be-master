class TreeNode:
    def _int_(self, val, right, left):
        self.val = val
        self.right = right
        self.left = left

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

