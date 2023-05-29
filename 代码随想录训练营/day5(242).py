from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count1 = Counter(s)
        count2 = Counter(t)
        if(count2 != count1):
            return False
        return True

