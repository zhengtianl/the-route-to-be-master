//
// Created by 45807 on 2023/2/24.
//

#include <iostream>
#include <unordered_map>
using namespace std;
class RandomizedSet{
public:
    RandomizedSet(){
        srand((unsigned)time(NULL));
    }

    bool insert(int val)
    {
        if(indices.count(val)){
            return false;
        }
        int index = nums.size();
        nums.emplace_back(val);
        indices[val] = index;
        return true;

    }

    bool remove(int val)
    {
        if(!indices.count(val)){
            return false;
        }
        int index = indices[val];
        int last = nums.back();
        nums[index] = nums.back();
        indices[last] = index;
        nums.pop_back();
        indices.erase(val);
        return true;
    }

    int getRandom()
    {
        int index = ::rand() % nums.size();
        return nums[index];
    }

private:
    vector<int> nums;
    unordered_map<int, int> indices;

};