#floor() 返回数字的下舍整数。简单模拟纯纯畜生题
import math
def bestCoordinate(towers:[[]], radius:int):
    mx = 0
    ans =[0,0]
    for i in range(51):
        for j in range(51):
            t = 0
            for x,y,q in towers:
                d = ((x - i)**2 + (y-j)**2)
                if d <= radius:
                    t += math.floor(q/(1+d))
            if t > mx:
                mx = t
                ans =[i,j]
    return ans

print(bestCoordinate([[1,2,5],[2,1,7],[3,1,9]],2))
print(bestCoordinate([[1,2,4],[2,3,5],[7,8,9]],4))



    
    