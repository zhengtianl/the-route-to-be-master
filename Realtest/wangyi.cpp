#include <iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
/*
 * 现在有n个物品，每一个物品都有一个价值，现在想将这些物品分给两个人，要求这两个人每一个人分到的物品的价值总和相同（个数可以不同，总价值相同即可），
 * 剩下的物品就需要扔掉，现在想知道最少需要扔多少价值的物品才能满足要求分给两个人。
 */
using namespace std;
int res = INT_MAX;
void dfs(vector<int>& nums, int res1, int res2, int sum, int index, int n){
  //一直选到最后一个数字才返回
  if(index == n){
    if(res1 == res2){
      res = min(res, sum - res1 - res2);
      //res = sum - res1 - res2;
    }
    return;
  }
  // 每次的选择环节都有3种选择
  dfs(nums, res1 + nums[index], res2, sum, index + 1, n);
  dfs(nums, res1, res2+ nums[index], sum, index + 1, n);
  dfs(nums, res1, res2, sum, index + 1, n);
}
int main (){
  int t;
  cin >> t; // 组数
  while(t--){
    int n;//该组的物品总数
    cin >> n;
    int temp; //当前存入值
    vector<int> nums;
    for(int i =0; i < n ; i++){
      cin >> temp;
      nums.push_back(temp);
    }
    // 计算该组的元素总和
    int sum = 0;
    for(auto i : nums){
      sum += i;
    }
    //vector，res1和res2和index初始都是0，sum需单独设变量存起来
    dfs(nums, 0, 0, sum, 0, n);
    cout<<res<< endl;
    res = INT_MAX;
  }
}
