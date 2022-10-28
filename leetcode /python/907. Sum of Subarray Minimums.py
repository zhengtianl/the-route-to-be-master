
def sumSubarrayMins(arr):
    # Dp dynamic programming
    # Montonic stack, increasing, decreasing
    # i= 4:3 1 2 4, 1 2 4, 2 4, 4
    arr = [0] + arr
    #store index
    stack = [0]
    #sum of minmuns up to i
    dp = [0] * len(arr)
    for i in range(len(arr)):
        #print(stack)
        while arr[stack[-1]] > arr[i]:

            stack.pop()
        j = stack[-1]
        dp[i] = dp[j] +(i - j) * arr[i]
        stack.append(i)
    return sum(dp)
print(sumSubarrayMins([1,2,4,6]))
