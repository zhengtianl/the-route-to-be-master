#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string& s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && c == st.top()) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        
        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};

int main() {
    string s = "abbaca";
    Solution sol;
    string s1 = sol.removeDuplicates(s);
    cout << s1 << endl;
    return 0;
}
