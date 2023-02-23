//
// Created by 45807 on 2023/2/23.
//
class Node{
public:
    int x;
    Node *child;
    Node *prev;
    Node *next;
};

Node* dfs(Node* head) {
    Node *curr = head;
    Node *last = nullptr;
    while (curr != nullptr) {
        Node *next = curr->next;
        if (curr->child) {
            Node *child_last = dfs(curr->child);
            next = curr->next;
            curr->next = curr->child;
            curr->child->prev = curr;
            if (next) {
                child_last->next = next;
                next->prev = child_last;
            }
            curr->child = nullptr;
            //last保存child表中最后一个节点，做返回值使用
            last = child_last;
        }
        else
        {
            //如果没有child表，last保存链表最后一个节点，做返回用
            last = curr;
        }
        curr = next;
    }
    return last;
}

Node* Fallten(Node* head)
{
    dfs(head);
    return head;
}

