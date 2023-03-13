
//
// Created by StarkLu on 2023/3/13.
//
#include <vector>
using namespace std;
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience) {
        int sum = 0;
        for(auto e:energy){
            sum += e;
        }
        int time  = sum <= initialEnergy ? 0: (initialEnergy - sum) + 1;
        for(auto ex:experience){
            if(initialExperience <= ex){
                time += 1 + (ex - initialExperience);
                initialExperience = 2 * ex + 1;
            }
            else{
                initialExperience += ex;
            }
        }
        return time;
    }
};