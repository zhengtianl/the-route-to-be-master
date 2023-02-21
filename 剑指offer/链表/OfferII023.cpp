#include <iostream>
#include <unordered_set>
 using namespace std;
 struct ListNode{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        if(headB == nullptr || headA == nullptr){
            return nullptr;
        }
        ListNode *pA = headA;
        ListNode *pB = headB;
        while(pA != pB){
            pA = pA == nullptr ? headB: pA -> next; //如果 pA 指向空指针（即链表 A 已经到达末尾），那么将 pA 指向链表 B 的头节点 headB；否则将 pA 指向链表 A 的下一个节点 pA->next。
            pB = pB == nullptr ? headA: pB -> next;
        }
        return pA;
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visited;
        ListNode *temp = headA;
        while (temp != nullptr) {
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr) {
            if (visited.count(temp)) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

};
int main()
{

}