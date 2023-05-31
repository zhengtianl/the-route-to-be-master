//
// Created by StarkLu on 2023/5/27.
//

#ifndef THE_ROUTE_TO_BE_MASTER_DATASTRUCT_H
#define THE_ROUTE_TO_BE_MASTER_DATASTRUCT_H

#endif //THE_ROUTE_TO_BE_MASTER_DATASTRUCT_H

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}

};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};