def get_permutations(n):
    # 生成n的全排列
    nums = [i for i in range(1, n+1)]
    permutations = []

    def backtrack(start):
        if start == n:
            permutations.append(nums[:])  # 复制当前排列到结果列表
        else:
            for i in range(start, n):
                nums[start], nums[i] = nums[i], nums[start]  # 交换元素
                backtrack(start+1)  # 递归生成下一个位置的排列
                nums[start], nums[i] = nums[i], nums[start]  # 恢复原始顺序

    backtrack(0)
    return permutations


def find_kth_permutation(n, k):
    permutations = get_permutations(n)
    if k < 1 or k > len(permutations):
        return None  # k超出范围，返回None

    return permutations[k-1]  # 返回第k小的排列


# 示例用法
n = int(input("请输入n的值："))
k = int(input("请输入k的值："))

result = find_kth_permutation(n, k)
if result:
    print("第{}小的排列为：{}".format(k, result))
else:
    print("无效的k值。")
