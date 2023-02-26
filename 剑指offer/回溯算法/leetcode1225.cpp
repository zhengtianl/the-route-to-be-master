#include<iostream>
#include<vector>
#include<functional>
using namespace std;
int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
    int ans = 0, left[26]{};
    for (char c : letters)
        ++left[c - 'a'];
    function<void(int, int)> dfs = [&](int i, int total) {
        if (i < 0) { // base case
            ans = max(ans, total);
            return;
        }

        // 不选 words[i]
        dfs(i - 1, total);

        // 选 words[i]
        bool ok = true;
        for (char c : words[i]) {
            if (left[c - 'a']-- == 0)
                ok = false; // 剩余字母不足
            total += score[c - 'a']; // 累加得分
        }

        if (ok)
            dfs(i - 1, total);

        // 恢复现场
        for (char c : words[i])
            ++left[c - 'a'];
    };

    dfs(words.size() - 1, 0);
    return ans;
}

