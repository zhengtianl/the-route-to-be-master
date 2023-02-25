//
// Created by 45807 on 2023/2/25.
//
#include "string"
#include "vector"
#include "stack"
#include "algorithm"

using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> store;
        int n = tokens.size();
        for(int i =0; i < n; i++){
            string &token = tokens[i];
            if (isNumber(token)){
                store.push(atoi(token.c_str()));
            }else if(tokens[i]=="+"){
                int x=store.top();
                store.pop();
                int y=store.top();
                store.pop();
                store.push(x+y);
            }
            else if(tokens[i]=="-"){
                int x=store.top();
                store.pop();
                int y=store.top();
                store.pop();
                store.push(y-x);
            }
            else if(tokens[i]=="*"){
                int x=store.top();
                store.pop();
                int y=store.top();
                store.pop();
                store.push(x*y);
            }
            else if(tokens[i]=="/"){
                int x=store.top();
                store.pop();
                int y=store.top();
                store.pop();
                store.push(y/x);
            }
        }
        return store.top();

    }

private:
    bool isNumber(string& token){
        return !(token=="+"||token=="-"||token=="*"||token=="/");
    }
};