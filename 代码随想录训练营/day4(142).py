class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head):
        v = set()
        while(head != None):
            if head in v:
                return head
            head = head.next
            v.add(head)
        return None
# Test case
# Create a cycle: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node2  # cycle

# Create an instance of the Solution class
solution = Solution()

# Call the detectCycle method
result = solution.detectCycle(node1)

# Check if a cycle was detected and print the starting node of the cycle
if result is not None:
    print("Cycle detected! Start of the cycle:", result.val)
else:
    print("No cycle detected.")
