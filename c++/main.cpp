#include<iostream>
#include <cmath>
#include<cstring>
#include<vector>

using namespace std;
//Basic
int simplemutipky(){
    int  a = 0;
    int  b = 0;
    cin >> a >> b;
    ::printf("PROD = %d", a * b);
    cin.get();
}

int  switchday(){
    int n = 0;
    cin >> n;
    cout << n / 365 << " ano(s)" << endl;
    cout << n % 365 / 30 << " mes(es)" << endl;
    cout << n % 365 % 30 << " dia(s)" << endl;
}


int countAsterisks(string s) {
    int ans = 0;
    int flag = 0;
    for (int i = 0; i < s.size(); i ++){
        char c = s[i];
        if(c == '|'){
            flag++;
        }else if(c == '*' && flag % 2 == 0){
            ans++;
        }
    }
    return ans;
}

int diamond(){
    int n = 0;
    cin >> n ;
    int xm = n /2 , ym  = n/2;
    for (int i  = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j++) {
            if (abs(xm - i) + abs(ym - j) <= n / 2) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

//Array
//
// 输入整数 N，输出一个 N阶的回字形二维数组。数组的最外层为 1，次外层为 2，以此类推。
void printMatrix(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int up = i, down = n - i + 1, left = j, right = n - j + 1;
            cout << min(min(up, down), min(left, right)) << ' ';
        }
        cout << endl;
    }

}

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    for(int i = 0; i < matrix.size(); i++) {
        int a = 0;
        int b = matrix[i].size() - 1;
        while (a <= b) {
            int mid = (a + b) / 2;
            if(target == matrix[i][mid]) return true;
            else if (target > matrix[i][mid]){
                a = mid + 1;
            }
            else{
                b = mid - 1;
            }
        }
    }
    return false;
}

vector<vector<int>> printMatrix(int n, int m) {
    vector<vector<int>> matrix(n, vector<int>(m));
    int k = 1;
    for (int i = 0; i < (n + 1) / 2 && i < (m + 1) / 2; i++) {
        for (int j = i; j < m - i; j++)
            matrix[i][j] = k++;
        for (int j = i + 1; j < n - i; j++)
            matrix[j][m - i - 1] = k++;
        for (int j = m - i - 2; j >= i && n - i - 1 != i; j--)
            matrix[n - i - 1][j] = k++;
        for (int j = n - i - 2; j > i && m - i - 1 != i; j--)
            matrix[j][i] = k++;
    }
    return matrix;
}






//字符串
string replace(string &s, string r) {
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, r.size()) == r) {
            s.replace(i, r.size(), "#");
        }
    }
}


string theOnceString(string input) {
    int cnt[26] = {0};
    int n = input.length();
    for (int i = 0; i < n; i ++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            cnt[input[i] - 'a']++;
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            cnt[input[i] - 'A']++;
        }
    }
    for (int i = 0; i < n; i ++) {
        if (cnt[input[i] - (input[i] >= 'a' ? 'a' : 'A')] == 1) {
            return string(1, input[i]);
        }
    }
    return "no";
}
//the start of the program.
int main(){
    printMatrix(20);

    return 0;
}
