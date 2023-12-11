class ListNode:
    def _init_(self, val = 0, next = None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head):
        cur, pre = head, None
        while cur:
            cur.next, pre, cur = pre, cur, cur.next
        return pre