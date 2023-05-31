def quickSort(q, l, r):
    if l >= r:
        return
    i, j = l, r
    x = q[l]
    while i < j:
        while q[i] < x:
            i += 1
        while q[j] > x:
            j -= 1
        if i < j:
            q[i], q[j] = q[j], q[i]
    quickSort(q, l, j - 1)
    quickSort(q, j + 1, r)

n = int(input())
arr = list(map(int, input().split()))

quickSort(arr, 0, n - 1)

print("Sorted array:", end=" ")
for i in range(n):
    print(arr[i], end=" ")
print()
