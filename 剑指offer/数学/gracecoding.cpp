//
// Created by 45807 on 2023/2/23.
//

#include "iostream"
#include "vector"
using namespace std;
vector<int> graceCoding(int n, int start){
    vector<int> ans(1 << n);
    for(int i =  0; i < ans.size(); i++){
        ans[i] = (i >> 1) ^ i ^ start;
    }
    return ans;
}

int main()
{
    int n, start;
    cin >> n >> start;
    vector<int> ans;
    ans = graceCoding(n, start);
    for(auto s : ans){
        cout << s << endl;
    }
}