# 链表操作一般都要定义dummy节点
```c++ 
struct ListNode
        {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

int getLength(ListNode *head)
    {
        length = 0;
        while(head != nullptr)
        {
            length ++;
            head = head -> next;
        }
        return length;
    }

//反转

ListNode* reverseList(ListNode* head)
{
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while(cur){
        ListNode* nxt = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}


```
