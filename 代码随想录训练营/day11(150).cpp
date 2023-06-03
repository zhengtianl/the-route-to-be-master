#include "vector"
#include "string"
#include "stack"
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> ans;
        for(int i = 0; i < tokens.size(); i++){
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int num1 = ans.top();
                ans.pop();
                int num2 = ans.top();
                ans.pop();
                if (tokens[i] == "+") ans.push(num1 + num2);
                if (tokens[i] == "-") ans.push(num2 - num1);
                if (tokens[i] == "*") ans.push(num1 * num2);
                if (tokens[i] == "/") ans.push(num1 / num1);
            }
            else ans.push(stoll(tokens[i]));
        }
        
        return ans.top();
    }
};
