//
// Created by StarkLu on 2023/5/27.
//
#include "iostream"
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}

};

ListNode* E(ListNode* head) {
    ListNode* pre = head;
    ListNode* cur = head->next;
    ListNode* newHead = cur;  // 记录新的头节点
    while (pre != nullptr && cur != nullptr) {
        pre->next = cur->next;
        cur->next = pre;
        pre = pre->next;
        if (pre != nullptr) {
            cur = pre->next;
        }
    }
    return newHead;
}



int main() {
    // 创建链表并赋值
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    head->next = node1;
    node1->next = node2;

    // 调用函数进行处理
    ListNode* result = E(head);

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

    return 0;
}