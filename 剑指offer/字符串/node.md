# 回文串

```C++
bool checkPalindrome(const string& s, int low, int high) {
    for (int i = low, j = high; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}
```