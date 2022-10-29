
def countMatches(items: [str], ruleKey: str, ruleValue: str) -> int:
    index = {"type": 0, "color": 1, "name": 2}[ruleKey]
    ans = 0
    for item in items:
        if item[index] == ruleValue:
            ans +=1
    return ans
print(countMatches([["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]],ruleKey="color", ruleValue="silver"))


