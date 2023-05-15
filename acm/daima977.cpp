//
// Created by StarkLu on 2023/5/14.
//
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;
vector<int> sortSquare(vector<int> &nums)
{
    for(int& num : nums)
    {
        num *= num;
    }
    sort(nums.begin(), nums.end());
    return nums;
}

vector<int> sortSquare2(vector<int> &nums)
{
    int k = nums.size()-1;
    vector<int> res(nums.size(), 0);
    for(int i = 0, j = nums.size() - 1; i <= j;)
    {
        if(nums[i] * nums[i] < nums[j] * nums[j])
        {
            res[k --] = nums[j]* nums[j];
            j --;
        }else{
            res[k--] = nums[i] * nums[i];
            i++;
        }
    }
    return res;
}





int main() {
    // 创建一个测试向量
    vector<int> nums = {-4, -2, 0, 2, 4};

    // 调用函数进行排序
    vector<int> sortedNums = sortSquare2(nums);

    // 打印排序后的结果
    cout << "Sorted Squares: ";
    for (int num : sortedNums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
