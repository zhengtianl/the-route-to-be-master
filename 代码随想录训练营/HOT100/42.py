def trap(height):
    if not height:
        return 0
    
    n = len(height)
    leftMax = [height[0]] + [0] * (n - 1)
    for i in range(1,n):
        leftMax[i] = max(leftMax[i - 1], height[i])
    
    rightMax = [0] * (n - 1) + [height[n - 1]]
    for i in range(n - 2, -1, -1):
        rightMax[i] = max(rightMax[i + 1], height[i])

    ans = sum(min(leftMax[i], rightMax[i]) - height[i] for i in range(n))
    return ans

