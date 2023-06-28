def backtracking(nums, path, res, used):
    if len(path) == len(nums):
        res.append(path[:])
        return

    for i in range(0, len(nums)):
        if used[i]:
            continue

        path.append(nums[i])
        used[i] = True
        backtracking(nums, path, res, used)
        used[i] = False
        path.pop()

def find_kth_permutation(n,k):
    nums = [i for i in range(1, n+1)]
    used = [False] * n
    res = []
    path = []
    backtracking(nums, path, res, used)
    return res[k-1]


# 示例用法
n = int(input("请输入n的值："))
k = int(input("请输入k的值："))

result = find_kth_permutation(n, k)
if result:
    print("第{}小的排列为：{}".format(k, result))
else:
    print("无效的k值。")
