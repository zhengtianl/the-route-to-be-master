n = int(input())
sum1 = 0
pay = 0
for i in range(n):
    x, y  = map(int, input().split())
    if x > y:
        pay += (x - y)
        sum1 += x
    else:
        sum1 += y
print(sum1, pay)
    