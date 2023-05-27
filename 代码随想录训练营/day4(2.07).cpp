//
// Created by StarkLu on 2023/5/27.
//
#include "iostream"
#include "DataStruct.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while( curA != nullptr){
            lenA ++;
            curA = curA -> next;
        }

        while( curB != nullptr){
            lenB ++;
            curB = curB -> next;
        }
        curA = headA;
        curB = headB;
        if(lenB > lenA){
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;
        while (gap--) {
            curA = curA->next;
        }


        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};