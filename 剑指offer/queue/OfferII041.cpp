//
// Created by StarkLu on 2023/2/27.
//
#include <iostream>
#include "queue"
using namespace std;
class MovingAverage {
public:
    MovingAverage(int size){
        this -> size;
        this -> sum = 0.0;
    }
    double next(int val){
        if(qu.size() == size){
            sum -= qu.front();
            qu.pop();
        }
        qu.push(val);
        sum += val;
        return sum / qu.size();
    }
private:
    int size;
    double sum;
    queue<int> qu;

};