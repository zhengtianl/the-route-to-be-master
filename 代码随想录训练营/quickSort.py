def quickSort(list1, l, r):
    if l >= r:return
    i = l
    j = r
    x = list1[l]
    while i < j:
        while list1[l] < x:
            l += 1
        while list1[r] > x:
            r -= 1
        if i < j:
            tmp = list1[l]
            list1[l] = list1[r]
            list1[r] = tmp
    quickSort(list1, l, j - 1)
    quickSort(list1, j + 1, r)

list1 = [3, 4, 5, 8, 1]
quickSort(list1, 0, 4)
print(list1)
