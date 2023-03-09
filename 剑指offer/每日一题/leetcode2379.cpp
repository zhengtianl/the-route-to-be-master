#include <string>
using namespace std;
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0;
        int r =  0;
        int count = 0;
        while(r < k){
            if(blocks[r] == 'W'){
                count += 1;
            }
            r++;
        }
        int ans = count;
        while( r < blocks.length())
        {
            if(blocks[r] == 'W'){
                count += 1;
            }
            if(blocks[l] == 'W'){
                count -= 1;
            }
            ans = min(count, ans);
            r ++;
            l ++;

        }
        return ans;
    }
};