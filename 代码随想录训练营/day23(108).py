# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        root = self.travel(nums, 0, len(nums) - 1)
        return root


    def travel(self, nums, left, right):
        if left > right: return None
        mid = left + ((right - left) // 2)
        root = TreeNode(nums[mid])
        root.left = self.travel(nums, left, mid - 1)
        root.right = self.travel(nums, mid + 1, right)
        return root


