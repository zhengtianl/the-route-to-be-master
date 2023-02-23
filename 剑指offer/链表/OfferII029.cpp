//
// Created by 45807 on 2023/2/23.
//
#include "ListNode.h"
#include "iostream"
ListNode *insert(ListNode* head, int insertVal)
{
    ListNode* insert = new ListNode(insertVal);
    if(head == nullptr){
        insert -> next = insert;
        return insert;
    }
    if(head -> next == head){
        head -> next = insert;
        insert -> next = head;
        return head;
    }
    ListNode* curr = head;
    ListNode* next = head -> next;
    while(next != head){
        if(insertVal >= curr -> val && insertVal <= next -> val){
            break;
        }
        if(curr -> val > next -> val){
            if(insertVal <= curr -> val || insertVal >= next -> val){
                break;
            }
        }
        curr = curr -> next;
        next = next -> next;
    }
    curr -> next = insert;
    insert -> next = next;
    return head;
}