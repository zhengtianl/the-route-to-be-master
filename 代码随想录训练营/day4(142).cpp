//
// Created by StarkLu on 2023/5/27.
//
#include "iostream"
#include "unordered_set"
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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while(head != nullptr){
            if(visited.find(head) != visited.end())
            {
                return head;
            }
            visited.insert(head);
            head = head -> next;
        }
        return nullptr;
    }
};
