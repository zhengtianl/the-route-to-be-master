import collections
class Linklist:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next
    
class Solution:
    def removeZeroSumSublists(self, head):
        dummy = Linklist(next = head, val = 0)
        seen = {} #记录前缀和
        preixSum, cur = 0, dummy
        while cur:
            preixSum += cur.val
            seen[preixSum] = cur
            cur = cur.next
            
        preixSum, cur = 0, dummy
        while cur:
            preixSum += cur.val
            cur.next = seen[preixSum].next
            cur = cur.next
        return dummy.next
# Test case
# Input: 1 -> 2 -> -3 -> 3 -> 1
# Output: 3 -> 1

# Create the linked list
head = Linklist(val=1, next=Linklist(val=2, next=Linklist(val=-3, next=Linklist(val=3, next=Linklist(val=1, next=None)))))

# Create an instance of the Solution class
solution = Solution()

# Call the removeZeroSumSublists method
result = solution.removeZeroSumSublists(head)

# Print the result
while result:
    print(result.val, end=" -> ")
    result = result.next
print("None")

 
           