//
// Created by 45807 on 2023/2/26.
//
#include "vector"
#include "string"
#include "stack"
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> left(m+2, vector<int>(n, 0));  // 首尾各添加一行全为0
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    left[i+1][j] = j == 0 ? 1 : left[i+1][j-1]+1;
                }
            }
        }
        int res = 0;

        for(int j = 0; j < n; j++){
            stack<int> st;  // 栈里面存储的是行索引
            st.push(0);
            for(int i = 1; i < m+2; i++){
                // 分三种情况考虑：
                // 当前元素大于、等于、小于栈顶元素
                if(left[i][j] > left[st.top()][j]){
                    st.push(i);
                }
                else if(left[i][j] == left[st.top()][j]){
                    st.pop();
                    st.push(i);
                }
                else{
                    while(!st.empty() && left[i][j] < left[st.top()][j]){
                        int mid = st.top();
                        st.pop();
                        if(!st.empty()){
                            int w = i - st.top() - 1;
                            int s = w * left[mid][j];
                            if(s > res) res = s;
                        }
                    }
                    st.push(i);
                }
            }
        }

        return res;
    }
};