#include "iostream"
#include "stack"
#include "string"
using namespace std;

class Solution{
    public:
    bool isValid(string& s){
        //第一种情况不匹配(}
        stack<char> res;
        if (s.length() % 2 != 0) return false;
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '{' ) res.push('}');
            else if (s[i] == '(') res.push(')');
            else if (s[i] == '[') res.push(']');
            //当不相同的时候，或没有可以和它匹配的括号了就return false;
            else if(s[i] != res.top() || res.empty()) return false;
            else res.pop();
        }
        return res.empty();        
    }
};

int main()
{
    string s = "()[]{}";
    Solution sol;
    cout << sol.isValid(s) << endl;
    return 0;
}