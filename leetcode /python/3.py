from pyparsing import string


def longset(s:str):
    occ = set()
    n = len(s)
    rk, ans  = -1, 0
    if s == None: return 0
    for i in range(n):
        if i != 0:
            occ.remove(s[i - 1])
        while rk + 1 < n and s[rk + 1] not in occ:
            occ.add(s[rk + 1])
            rk += 1
        ans = max(ans, len(occ))
    return ans
print(longset('string'))

            
            
    