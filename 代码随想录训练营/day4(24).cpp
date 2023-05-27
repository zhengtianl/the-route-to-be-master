#include <iostream>
#include "DataStruct.h"

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next;
            ListNode* tmp2 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp2;
            cur  = cur -> next -> next;
        }
        return dummyHead->next;
    }
};

int main() {
    // 创建链表并赋值
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;

    // 创建 Solution 对象
    Solution solution;

    // 调用 swapPairs 函数进行处理
    ListNode* result = solution.swapPairs(head);

    // 输出处理后的链表
    ListNode* current = result;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // 释放链表的内存
    delete head;
    delete node1;
    delete node2;
    delete node3;

    return 0;
}
