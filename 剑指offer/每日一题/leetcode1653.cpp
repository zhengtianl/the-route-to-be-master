#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int n = s.size();
        int del = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a')
            {
                del++;
            }
        }
        ans = del;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a')
            {
                del--;
            }else{
                del++;
            }
            ans = min(ans,del);
        }
        return ans;
    }
};