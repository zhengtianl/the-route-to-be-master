class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        res = []
        new_line = []
        in_block = False
        for line in source:
            i = 0
            while i < len(line):
                if in_block:
                    if i + 1 < len(line) and line[i] == '*' and line[i + 1] == '/':
                        in_block = False
                        i += 1
                else:
                    if i + 1 < len(line) and line[i] == '/' and line[i + 1] == '*':
                        in_block = True
                        i += 1
                    elif i + 1 < len(line) and line[i] == '/' and line[i + 1] == '/':
                        break
                    else:
                        new_line.append(line[i])
                i += 1
                
            if  not in_block and len(new_line) > 0:
                res.append(''.join(new_line))
                new_line = []
        return res
