//
// Created by StarkLu on 2023/5/27.
//
#include "iostream"
#include "DataStruct.h"
using namespace std;
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* cur = dummy;
        while(cur -> next != nullptr)
        {
            if(cur -> next -> val  == val){
                cur -> next = cur -> next -> next;
            }else{
                cur  = cur -> next;
            }
        }
        return dummy -> next;

    }
};