import collections

class Linklist:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
    
class Solution:
    def removeZeroSumSublists(self, head):
        dummy = Linklist(next=head, val=0)
        seen = {}  # Records prefix sums
        prefixSum, cur = 0, dummy
        
        while cur:
            prefixSum += cur.val
            seen[prefixSum] = cur
            cur = cur.next
            
        prefixSum, cur = 0, dummy
        
        while cur:
            prefixSum += cur.val
            cur.next = seen[prefixSum].next
            cur = cur.next
        
        return dummy.next

# Read the number of queries
num_queries = int(input())

# Process each query
for _ in range(num_queries):
    # Read the input for the linked list
    input_list = list(map(int, input().split()))

    # Create the linked list
    head = None
    tail = None

    for val in input_list:
        if head is None:
            head = Linklist(val)
            tail = head
        else:
            tail.next = Linklist(val)
            tail = tail.next

    # Create an instance of the Solution class
    solution = Solution()

    # Call the removeZeroSumSublists method
    result = solution.removeZeroSumSublists(head)

    # Print the result
    while result:
        print(result.val, end=" -> ")
        result = result.next
    print("None")
