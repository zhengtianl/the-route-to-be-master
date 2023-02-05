//
// Created by 45807 on 2023/2/5.
//在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，每一列都按照从上到下 非递减 的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//

#include<iostream>
#include <cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstring>

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {
        int i = matrix.size() - 1, j = 0;
        while(i >= 0 && j < matrix[0].size())
        {
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }


int main()
{

}