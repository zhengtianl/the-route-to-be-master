//
// Created by 45807 on 2023/2/18.
//
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
public:
    ListNode* removeElements1(ListNode* head, int val){
        while( head != nullptr && head -> val == val){
            head = head -> next;
        }
        ListNode *cur = head;
        while(cur != nullptr && cur->next){
            if(cur -> next ->val  == val){
                cur -> next = cur -> next ->next;
            }else{
                cur = cur -> next;
            }
        }
        return head;
    }

    ListNode* removeElements2(ListNode* head, int val)
    {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *cur = dummy;
        while(cur->next != nullptr){
            if(cur -> next -> val == val){
                cur -> next  = cur -> next -> next;
            }else{
                cur  = cur -> next;
            }
        }
        return dummy -> next;
    }
};

int main(){

}