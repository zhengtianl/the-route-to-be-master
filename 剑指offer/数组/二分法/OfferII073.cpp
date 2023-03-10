//
// Created by StarkLu on 2023/3/10.
//
#include "algorithm"
#include "vector"
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int speed = (right - left) / 2 + left;
            int hours = 0;
            for (int p : piles) {
                hours += (p + speed - 1) / speed;
            }
            if (hours <= h) {
                right = speed;
            } else {
                left = speed + 1;
            }
        }
        return left;
    }
};

