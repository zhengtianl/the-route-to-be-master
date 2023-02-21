//
// Created by 45807 on 2023/2/21.
//
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};
//递归
ListNode* mergeTwolinklist1(ListNode* l1, ListNode* l2){
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    if(l1 -> val < l2->val){
        l1 -> next = mergeTwolinklist(l1 -> next, l2);
        return l1;
    }else{
        l2 -> next = mergeTwolinklist(l2 -> next, l1);
        return l2;
    }
}

//迭代
ListNode* mergeTwolinklist2(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode(-1);
    ListNode* prev = dummy;
    while(l1 != nullptr && l2 != nullptr){
        if(l1 -> val< l2 ->val){
            prev -> next = l1;
            l1  = l1 -> next;
        }else{
            prev -> next = l2;
            l2 = l2 -> next;
        }
        prev = prev -> next;
    }
    prev->next = l1 == nullptr ? l2 : l1;
    return dummy -> next;
}