def arrayStringsAreEqual(word1: [], word2:[]) -> bool:
    res1 = ''
    res2 = ''
    for i in word1:
        res1 += i
    for j in  word2:
        res2 += j
    if res1 == res2:return True
    else: return False
print(arrayStringsAreEqual(word1 = ['a','cb'], word2 =['ab', 'c']))
print(arrayStringsAreEqual(word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]))
#简单的遍历