#create hashtable the space complex is o(n)
import functools
def singleNumber (nums = []):
    hashtable = {}
    for i in nums:
        if i in hashtable:
            hashtable[i] += 1
        else:
            hashtable[i] = 1
    for j in hashtable.keys():
        if hashtable[j] == 1:
            return j
# xor mthod o(1)
def otherSolution(nums):
    return functools.reduce(lambda x, y : x^y, nums)

print(singleNumber([1,1,2,2,3]))
print(otherSolution([1,1,2,2,3]))


