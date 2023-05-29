#include "unordered_set"
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1){
            int sum = sum1(n);
            if (sum == 1){
                return true;
            }
            if(set.find(sum) != set.end()){
                return false;
            }else{
                set.insert(sum);
            }
            n = sum;

        }

    }

    int sum1(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n%10)*(n%10);
            n /= 10;
        }

        return sum;
    }

};