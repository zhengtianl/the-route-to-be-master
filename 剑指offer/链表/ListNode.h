//
// Created by 45807 on 2023/2/22.
//

#ifndef PRATICE_LISTNODE_H
#define PRATICE_LISTNODE_H

#endif //PRATICE_LISTNODE_H
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};