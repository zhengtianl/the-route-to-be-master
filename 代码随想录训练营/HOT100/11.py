
def maxArea(height):
    i, j, res = 0, len(height) - 1, 0
    while i < j:
        if height[i] < height[j]:
            res = max(res, height[i] * abs(j - i))
            i += 1
        else:
            res = max(res, height[j] * abs(i -  j))
            j -= 1
    return res