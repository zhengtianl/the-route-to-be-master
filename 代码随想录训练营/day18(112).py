# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None: return False
        return self.helper(root, targetSum - root.val)
    def helper(self, cur, count):
        #决定递归结束条件
        if cur.left is None and cur.right is None and count == 0:return True
        if cur.left is None and cur.right is None and count != 0:return False
        if cur.left:
            count -= cur.left.val
            if self.helper(cur.left, count):
                return True
            count += cur.left.val
        
        if cur.right:
            count -= cur.right.val
            if self.helper(cur.right, count):
                return True
            count += cur.right.val
        return False