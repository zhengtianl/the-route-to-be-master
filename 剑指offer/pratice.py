from collections import deque
from collections import Counter

class ArrayStack:
    def __init__(self):
        self._data = []

    def size(self):
        return len(self._data)

    def is_empty(self):
        """ return True if the stack is empty"""
        return len(self._data) == 0

    def push(self, e):
        self._data.append(e)

    def pop(self):
        if self.is_empty():
            raise Exception('Stack is empty')
        return self._data.pop()

    def top(self):
        if self.is_empty():
            raise Exception('Stack is empty')
        return self._data[-1]  # the last item in the list


# quicksort
class QuickSortClass:
    def __init__(self, a: 'list'):
        self.a = a

    def QuickSort_partition(self, left, right):
        reference = a[left]
        while (left < right):
            while ((a[right] >= reference) and (left < right)):
                right -= 1
            if (left < right):
                a[left] = a[right]
                left += 1
            while ((a[left] < reference) and (left < right)):
                left += 1
            if (left < right):
                a[right] = a[left]
                right -= 1
        a[right] = reference
        return right

    def QuickSort(self, left, right):
        if (left < right):
            middle_value_index = self.QuickSort_partition(left, right)
            self.QuickSort(left, middle_value_index - 1)
            self.QuickSort(middle_value_index + 1, right)


# 滑动窗口
# 1.单调栈单调队列sliding windows，用朴素想法先做
# 滑动窗口算法的思路是这样：
# 我们在字符串 S 中使用双指针中的左右指针技巧，初始化 left = right = 0，把索引闭区间 [left, right] 称为一个「窗口」。
# 我们先不断地增加 right 指针扩大窗口 [left, right]，直到窗口中的字符串符合要求（包含了 T 中的所有字符）。
# 此时，我们停止增加 right，转而不断增加 left 指针缩小窗口 [left, right]，直到窗口中的字符串不再符合要求（不包含 T 中的所有字符了）。同时，每次增加 left，我们都要更新一轮结果。
# 重复第 2 和第 3 步，直到 right 到达字符串 S 的尽头。

class MonotonicQueue:
    def __init__(self, a: 'list'):
        self.a = a

    def nextGreatnumber(self, a):
        n = len(a)
        ans = [-1 for _ in range(n)]
        stack = []
        for i in range(n - 1, -1, -1):
            while stack and stack[-1] <= a[i]:
                stack.pop()
            if stack:
                ans[i] = stack[-1]
            stack.append(a[i])
        return ans


def test1():
    a = [3, 4, 13, 2, 13, 1]
    return a


def minWindow( s, t):
    if len(t) > len(s): return ""
    cnt = Counter(t)
    need = len(t)
    ans = len(s) + 1
    start = left = 0  # define the left boundary
    end = right = 0  # define the right boundary
    n = len(s)

    for right in range(n):
        ch = s[right]
        if ch in t:
            if cnt[ch] > 0:
                need -= 1
            cnt[ch] -= 1
        right += 1

        while need == 0:
            if right - left < ans:
                ans = right - left
                start, end = left, right - 1
            ch2 = s[left]
            if ch2 in t:
                cnt[ch2] += 1
                if cnt[ch2] > 0:
                    need += 1
            left += 1

    return s[start: end + 1]


def next(s):
    n = len(s)
    pi = [0] * n
    j = 0
    for i in range(1, n):
        while j > 0 and s[i] != s[j]:
            j = pi[j-1]
        if s[i] == s[j]:
            j += 1
        pi[i] =j
    return pi


class Solution:
    def strStr(self, s: str, t: str) -> int:

        '''KMP模板'''

        def prefix_function(s):
            n = len(s)
            pi = [0] * n

            j = 0
            for i in range(1, n):
                while j > 0 and s[i] != s[j]:  # 当前位置s[i]与s[j]不等
                    j = pi[j - 1]  # j指向之前位置，s[i]与s[j]继续比较

                if s[i] == s[j]:  # s[i]与s[j]相等，j+1，指向后一位
                    j += 1

                pi[i] = j
            return pi

        '''主程序'''
        n, m = len(s), len(t)
        pi = prefix_function(t)  # 预处理得到t的前缀函数

        '''再次基于KMP的思想在s中匹配t'''
        j = 0
        for i in range(n):
            while j > 0 and s[i] != t[j]:
                j = pi[j - 1]
            if s[i] == t[j]:
                j += 1
                if j == m:  # 匹配到了t，直接返回
                    return i - m + 1
        return -1


# n, m = len(s), len(t)
#         pi = prefix_function(t)             # 预处理得到t的前缀函数
#
#         '''再次基于KMP的思想在s中匹配t'''
#         j = 0
#         for i in range(n):
#
#             while j>0 and s[i] != t[j]:
#                 j = pi[j-1]
#
#             if s[i] == t[j]:
#                 j += 1
#                 if j == m:          # 匹配到了t，直接返回
#                     return i-m+1
#         return -1



if __name__ == "__main__":
    # a = test1()
    # # quickSort = QuickSortClass(a)
    # # quickSort.QuickSort(0, len(a) - 1)
    # mono = MonotonicQueue(a)
    # b = mono.nextGreatnumber(a)
    # print(b)
    p = "abeabf"

    print(next(p))
