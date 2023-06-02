#include "queue"
#include "iostream"
using namespace std;
class MyStack {
public:
    queue<int> que1;
    queue<int> que2; // 辅助队列，用来备份
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        que1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = que1.size();
        size--;
        while (size--) { // 将que1 导入que2，但要留下最后一个元素
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front(); // 留下的最后一个元素就是要返回的值
        que1.pop();
        que1 = que2;            // 再将que2赋值给que1
        while (!que2.empty()) { // 清空que2
            que2.pop();
        }
        return result;
    }

    /** Get the top element. */
    int top() {
        return que1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty();
    }
};

int main() {
    MyStack stack;

    // 测试空栈
    cout << stack.empty() << endl; // 输出1

    // 入栈
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // 测试栈是否为空
    cout << stack.empty() << endl; // 输出0

    // 出栈
    cout << stack.pop() << endl; // 输出3
    cout << stack.pop() << endl; // 输出2


    // 入栈
    stack.push(4);

    // 出栈
    cout << stack.pop() << endl; // 输出4
    cout << stack.pop() << endl; // 输出1

    // 测试栈是否为空
    cout << stack.empty() << endl; // 输出1

    return 0;
}
