class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if not s or len(s) < len(p):
            return []
        from collections import Counter
        cnt_p = Counter(p) # 统计p中字母出现的次数
        cnt_s = Counter()  # 统计滑动窗口里字母出现的次数
        ans = []
        left = 0
 
        for right, char in enumerate(s):
            cnt_s[char] += 1  # 添加窗口内的字母
            # 如果窗口等于p的长度，判断窗口内是否符合要求，然后开始滑动
            if right - left + 1 == len(p):
                if cnt_s == cnt_p:
                    ans.append(left)

                cnt_s[s[left]] -= 1
                # 注意Counter减到0并不会删除，因此需要手动删除
                if cnt_s[s[left]] == 0:
                    del cnt_s[s[left]]
                left += 1

        return ans

