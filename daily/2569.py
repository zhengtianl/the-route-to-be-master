class Solution:
    def handleQuery(self, nums1: List[int], nums2: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums1)
        m = len(queries)
        seg_tree = SegTree(nums1)

        total = sum(nums2)
        ans = []
        for i in range(m):
            if queries[i][0] == 1:
                l = queries[i][1]
                r = queries[i][2]
                seg_tree.reverse_range(l, r)
            elif queries[i][0] == 2:
                total += seg_tree.sum_range(0, n - 1) * queries[i][1]
            elif queries[i][0] == 3:
                ans.append(total)
        return ans


class SegTree:
    def __init__(self, nums):
        n = len(nums)
        self.arr = [SegNode() for _ in range(n * 4 + 1)]
        self.build(1, 0, n - 1, nums)

    def sum_range(self, left, right):
        return self.query(1, left, right)

    def reverse_range(self, left, right):
        self.modify(1, left, right)

    def build(self, id, l, r, nums):
        arr = self.arr
        arr[id] = SegNode()
        arr[id].l = l
        arr[id].r = r
        arr[id].lazytag = False
        if l == r:
            arr[id].sum = nums[l]
            return
        mid = (l + r) >> 1
        self.build(2 * id, l, mid, nums)
        self.build(2 * id + 1, mid + 1, r, nums)
        arr[id].sum = arr[2 * id].sum + arr[2 * id + 1].sum

    # pushdown函数：下传懒标记，即将当前区间的修改情况下传到其左右孩子结点
    def pushdown(self, x):
        arr = self.arr
        if arr[x].lazytag:
            arr[2 * x].lazytag = not arr[2 * x].lazytag
            arr[2 * x].sum = arr[2 * x].r - arr[2 * x].l + 1 - arr[2 * x].sum
            arr[2 * x + 1].lazytag = not arr[2 * x + 1].lazytag
            arr[2 * x + 1].sum = arr[2 * x + 1].r - arr[2 * x + 1].l + 1 - arr[2 * x + 1].sum
            arr[x].lazytag = False
    # 区间修改
    def modify(self, id, l, r):
        arr = self.arr
        if arr[id].l >= l and arr[id].r <= r:
            arr[id].sum = (arr[id].r - arr[id].l + 1) - arr[id].sum
            arr[id].lazytag = not arr[id].lazytag
            return
        self.pushdown(id)
        mid = (arr[id].l + arr[id].r) >> 1
        if arr[2 * id].r >= l:
            self.modify(2 * id, l, r)
        if arr[2 * id + 1].l <= r:
            self.modify(2 * id + 1, l, r)
        arr[id].sum = arr[2 * id].sum + arr[2 * id + 1].sum

    # 区间查询
    def query(self, id, l, r):
        arr = self.arr
        if arr[id].l >= l and arr[id].r <= r:
            return arr[id].sum
        if arr[id].r < l or arr[id].l > r:
            return 0
        self.pushdown(id)
        mid = (arr[id].l + arr[id].r) >> 1
        res = 0
        if arr[2 * id].r >= l:
            res += self.query(2 * id, l, r)
        if arr[2 * id + 1].l <= r:
            res += self.query(2 * id + 1, l, r)
        return res

class SegNode:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.sum = 0
        self.lazytag = False
