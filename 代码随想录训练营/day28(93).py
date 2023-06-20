class Solution:
    def restoreIpAddresses(self, s: str):
        res = []
        path = []
        self.backTracking(s,0,res,path)
        return res

    def backTracking(self, s, startIndex,res, path):
        #递归结束条件当起始位置等于字符串长度或者path的长度等于4时
        if startIndex == len(s) and len(path) == 4:
            res.append('.'.join(path))
            return

        for i in range(startIndex, len(s)):
            if self.is_valid(s,startIndex,i):
                path.append(s[startIndex:i+1])
                self.backTracking(s,i+1,res,path)
                path.pop()

    def is_valid(self, s, start, end):
        if start > end:
            return False
        if s[start] == '0' and start != end:  # 0开头的数字不合法
            return False
        num = int(s[start:end+1])
        return 0 <= num <= 255
