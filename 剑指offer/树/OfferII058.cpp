//
// Created by StarkLu on 2023/3/4.
//
#include "vector"
using namespace std;
class MyCalendar {
    vector<pair<int, int>> booked;

public:
    bool book(int start, int end) {
        for (auto &[l, r] : booked) {
            if (l < end && start < r) {
                return false;
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
};