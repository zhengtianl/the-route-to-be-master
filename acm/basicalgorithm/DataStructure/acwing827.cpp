#include "iostream"
using namespace std;
 
 class Node
 {
    public:
    int data;
    Node* last;
    Node* prev;
 };
 class DoubleNode
 {
    private:
    Node * head;
    Node * tail;
 };

 