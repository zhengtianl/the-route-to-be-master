//
// Created by StarkLu on 2023/5/27.
//
#include "DataStruct.h"
#include "iostream"
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(n -- && fast != nullptr)
        {
            fast = fast -> next;
        }
        fast  = fast -> next;
        while(fast != nullptr){
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;

        return dummy -> next;

    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;


    Solution solution;

    // 调用 swapPairs 函数进行处理
    ListNode* result = solution.removeNthFromEnd(head, 1);

    // 输出处理后的链表
    ListNode* current = result;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    delete head;
    delete node1;
    delete node2;
    delete node3;
    
    return 0;
}