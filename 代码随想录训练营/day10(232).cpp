#include "iostream"
#include "stack"
using namespace std;
class Myqueue
{
private:
    stack<int> StackIn; 
    stack<int> StackOut;
public:
    void push(int x){
        StackIn.push(x);
    }

    int pop(){
        if(StackOut.empty()){
            while(!StackIn.empty()){
                //push 1 2 3 stackIn 123
                
                StackOut.push(StackIn.top());
                StackIn.pop();
                //push out 3 2 1
            }
        }
        int res = StackOut.top();
        StackOut.pop();
        return res;
    }
    
    int peek(){
        int res = this -> pop();
        StackOut.push(res);
        return res;
    }

    bool empty(){
        return StackIn.empty() && StackOut.empty();
    }
};


int main(){
    Myqueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    cout << queue.pop() << endl;
    cout << queue.peek() << endl;
    return 0;
}
