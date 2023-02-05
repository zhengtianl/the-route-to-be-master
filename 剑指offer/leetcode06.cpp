#include<iostream>
#include <cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stack>

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        std::stack<int> res;
        while(head != nullptr)
        {
            res.push(head ->val);
            head = head -> next;
        }
        std::vector<int> ans;
        while(!res.empty()) {
            ans.push_back(res.top());
            res.pop();
        }
        return ans;
    }
};
