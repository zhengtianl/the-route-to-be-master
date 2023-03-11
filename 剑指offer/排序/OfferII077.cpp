//
// Created by StarkLu on 2023/3/11.
//
#include "vector"
#include "algorithm"
#include "../dataStruct.h"
using namespace std;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        // 快慢指针找中间节点
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        // 递归调用排序函数
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        // 合并已排序的子链表
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (left && right) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        cur->next = left ? left : right;
        return dummy->next;
    }

    ListNode* sortList2(ListNode* head) {
        if(!head || !head -> next){
            return head;
        }
        vector<int> nums;
        ListNode *cur = head;
        while(cur){
            nums.push_back(cur -> val);
            cur = cur -> next;
        }
        sort(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(-1);
        cur = dummy;
        for(int num: nums)
        {
            cur -> next = new ListNode(num);
            cur = cur -> next;
        }
        return dummy -> next;
    }
};
