//
// Created by 45807 on 2023/2/21.
//
#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

ListNode* reverseList(ListNode* head)
{
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while(cur){
        ListNode* nxt = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}