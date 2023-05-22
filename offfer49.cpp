#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int r = 0;
        int res = 0;
        for(int l = 0; l < s.size(); l++)
        {
            while(set.find(s[r]) == set.end() && r < s.size())
            {
                set.insert(s[r]);
                res = max(r - l + 1, res);
                r++;
            }
            set.erase(s[l]);
        }
        return res;
    }
};

int main() {
    Solution solution;
    string input = "peweew";
    int length = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << length << endl;

    return 0;
}
