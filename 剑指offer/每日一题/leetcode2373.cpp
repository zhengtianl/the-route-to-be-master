//
// Created by StarkLu on 2023/3/1.
//
/*给你一个大小为 n x n 的整数矩阵 grid 。生成一个大小为 (n - 2) x (n - 2) 的整数矩阵  maxLocal ，并满足：
maxLocal[i][j] 等于 grid 中以 i + 1 行和 j + 1 列为中心的 3 x 3 矩阵中的 最大值 。
换句话说，我们希望找出 grid 中每个 3 x 3 矩阵中的最大值。返回生成的矩阵。*/
#include <vector>
#include <iostream>
#include "algorithm"
#include "math.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n =  grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2,0));
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < n-2; j++){
                for(int x = i; x < i + 3; x++){
                    for(int y = j; y < j + 3; y++){
                        ans[i][j] = max(ans[i][j], grid[x][y]);
                    }
                }
            }
        }
        return ans;
    }
};