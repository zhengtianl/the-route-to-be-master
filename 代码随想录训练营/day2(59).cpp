//
// Created by StarkLu on 2023/5/25.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startX = 0, startY = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
        int offset = 1;
        int i, j;
        while (loop--) {
            i = startX;
            j = startY;
            //第一条边
            for (j = startY; j < n - offset; j++) {
                res[startX][j] = count++;
            }
            //第二条边
            for (i = startX; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > startY; j--) {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startX; i--) {
                res[i][j] = count++;
            }
            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startX++;
            startY++;

            offset += 1;
        }
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    };
};



int main(){
    Solution s;
    int n = 9;
    vector<vector<int>>res = s.generateMatrix(9);
    for (const auto& row : res) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

}
