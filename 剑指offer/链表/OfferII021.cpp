//
// Created by 45807 on 2023/2/21.
//
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution {
public:
    int getLength(ListNode *head)
    {
        int length = 0;
        while(head != nullptr){
            ++length;
            head = head -> next;
        }
        return length;
    }

    ListNode* removeNthFromEnd1(ListNode* head, int n)
    {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* cur = dummy;
        int m = getLength(head);
        for(int i = 0; i < m - n ; i++){
            cur = cur -> next;
        }
        cur->next = cur->next->next;
        ListNode* ans = dummy -> next;
        delete dummy;
        return ans;
    }


    ListNode* removeNthFormEnd2(ListNode* head, int n)
    {
        ListNode* dummy = new ListNode(0,head);
        ListNode* first = head;
        ListNode* second = dummy;
        for(int i= 0; i < n; i++){
            first = first -> next;
        }
        while(first != nullptr){
            first = first -> next;
            second = second -> next;
        }
        second -> next = second -> next -> next;
        ListNode *ans = dummy -> next;
        delete dummy;
        return ans;
    }












};