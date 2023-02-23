//
// Created by 45807 on 2023/2/22.
//
#include "iostream"
#include "ListNode.h"
#include "stack"
using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s1;
        ListNode* curr = head;
        while(curr != nullptr){
            s1.push(curr -> val);
            curr = curr -> next;
        }
        curr = head;
        while (curr != nullptr) {
            if (s1.top() != curr->val) {
                return false;
            }
            s1.pop();
            curr = curr->next;
        }
        return true;
    }
};
int main(){
    Solution s;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    bool n = s.isPalindrome(head);
    cout << n << endl;
}

