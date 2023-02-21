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
# 遍历所有的字串
```c++
int allSubstr(string s)
{
    for(int i = 0; i < s.length(); i++){
        for(int j = i; j <s.length(); j++){
            sting ss = s.substr(i, j - i +1);
        }
    }
    return ss;
}
```