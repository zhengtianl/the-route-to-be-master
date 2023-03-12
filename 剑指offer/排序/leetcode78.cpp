#include <iostream>
#include <vector>
#include <queue>
#include "../dataStruct.h"
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> que;
        for (auto list : lists) {
            while (list) {
                que.push(list->val);
                list = list->next;
            }
        }
        // print values in the priority queue
//        cout << "Priority Queue: ";
//        while (!que.empty()) {
//            cout << que.top() << " ";
//            que.pop();
//        }
//        cout << endl;

        ListNode* cur = new ListNode(-1);
        ListNode* pre = cur;
        while (!que.empty()) {
            ListNode* node = new ListNode(que.top());
            pre->next = node;
            pre = node;
            que.pop();
        }
        return cur->next;
    }
};

int main() {
    // create three linked lists to merge
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    // call the mergeKLists method and print the result
    Solution sol;
    ListNode* mergedList = sol.mergeKLists(lists);

    cout << "Merged List: ";
    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}
