# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if root == None: return 0
        if root.left == None and root.right == None: return 0
        #单层循环逻辑
        #循环左子树
        left_value = self.sumOfLeftLeaves(root.left)
        if root.left != None and root.left.left == None and root.left.right == None:
            left_value = root.left.val
        right_value = self.sumOfLeftLeaves(root.right)

        return left_value + right_value