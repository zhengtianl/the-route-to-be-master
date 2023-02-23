//
// Created by 45807 on 2023/2/22.
//
#include <iostream>
#include <queue>
#include "stack"
#include "deque"
int main() {
    std::queue<int> q1;
    std::stack<int> s1;
    std::deque<int> d1;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    s1.push(1);
    s1.push(2);
    s1.push(3);

    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_front(0);

//    while (!q1.empty()) {
//        int front = q1.front();
//        std::cout << front << std::endl;
//        q1.pop();
//    } //FIFO
//
//    while (!s1.empty()) {
//        int front = s1.top();
//        std::cout << front << std::endl;
//        s1.pop();
//    }//FILO

    for (auto it = d1.begin(); it != d1.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}