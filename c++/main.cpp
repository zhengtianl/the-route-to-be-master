#include<iostream>
#include <cmath>
#include<cstring>
#include<vector>
#include<algorithm>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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


class Array {
private:
    int age,height;
    double money;

public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i ++){
            for(int j = 0; j<n; j++ ){
                if ( i == j || i + j + 1== n ){
                    if (grid[i][j] == 0) return false;
                }
                else if(grid [i][j] != 0) return false;
            }
        }
        return true;
    }
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

    int maxArea(vector<int>& height) {   //双指针移动长板
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        while( i < j){
            if(height[i] < height[j]){
                res = max(res, (j-i)*height[i]);
                i+= 1;
            }else{
                res = max (res, (j-i)*height[j]);
                j -= 1;
            }

        }
        return res;
    }

    //Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
    // Return the sum of the three integers.
    // You may assume that each input would have exactly one solution.

    int threeSumClosest(std::vector<int> &nums, int target) {
        //首先对数组排序
        sort(nums.begin(), nums.end());

        //最基本的答案
        int ans = nums[0] + nums[1] + nums[2];

        //数组大小
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            //去重
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            //左右双指针
            int left = i + 1;
            int right = size - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                //等于target直接返回
                if (sum == target) return target;

                //左右指针移动, 逼近最接近的值
                if (sum > target) {
                    ans = abs(sum - target) < abs(ans - target) ? sum : ans;
                    right--;
                } else {
                    ans = abs(sum - target) < abs(ans - target) ? sum : ans;
                    left++;
                }
            }
        }
        return ans;
    }

};


//字符串
class string {
    string replace(string &s, string r) {
        for (int i = 0; i < s.size(); i++) {
            if (s.substr(i, r.size()) == r) {
                s.replace(i, r.size(), "#");
            }
        }
    }

    string decodeMessage(string key, string message) {
        char cur = 'a';
        unordered_map<char, char> rules;
        string ans = "";
        rules[' '] = ' '; // mapping for space character
        for (char c: key) {
            if (c != ' ' and rules.count(c) == 0) {
                rules[c] = cur;
                cur++;
            }
        }

        for (char c: message) {
            ans += rules[c];
        }
        return ans;

    }

    string decodeMessage2(string key, string message) {
        char cur = 'a';
        unordered_map<char, char>dic;
        for(char c : key){
            if(c !=' ' && dic.count(c) == 0){
                dic[c] = cur;
                cur += 1;
            }
        }

        for(char &c:message){
            if( c != ' '){
                c = dic[c];
            }
        }

        return message;

    }




    string theOnceString(string input) {
        int cnt[26] = {0};
        int n = input.length();
        for (int i = 0; i < n; i++) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                cnt[input[i] - 'a']++;
            } else if (input[i] >= 'A' && input[i] <= 'Z') {
                cnt[input[i] - 'A']++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (cnt[input[i] - (input[i] >= 'a' ? 'a' : 'A')] == 1) {
                return string(1, input[i]);
            }
        }
        return "no";
    }
};

//链表
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    //定义到左边界的链表
    ListNode* le = list1;
    for (int i = 0; i < a - 1; i++) {
        le = le->next;
    }
    //定义从右边界开始到最末尾的链表
    ListNode* Ri = list1;
    for (int i = 0; i <= b; i++) {
        Ri = Ri->next;
    }
    //将左节点的w尾结点指向第二个链表头节点
    le->next = list2;

    while (list2->next != nullptr) {
        list2 = list2->next;
    }
    //list2的尾节点指向Ri节点的头节点
    list2->next = Ri;
    return list1;
}

class Player{
public:
    int x,y;
    int speed;
    void Move(int xa, int ya){
        x += xa * speed;
        y += ya * speed;
    }

    void increment(int *ptr) {
        (*ptr)++;
    }

    void incrementRef(int &ref) {
        ref++;
    }
};

//the start of the program.

int max(int &x, int &y){
    x = 10 , y=10;
    if (x>y) return x;
    else return y;
}


void swap(double &x, double &y){
    double t = x; //init a memory space for x, x has no value
    x = y; //give the x value to the y memory address
    y = t; // give the y value to the y memory address
    //vo
}

inline void foo(){
    ::puts("dasdkjahsdkjhaskjdh");
    foo();

}
int factor(int a){
    if(a == 1) return 1; //递归重要的是边界
    return a * factor(a-1);
}
char a, g;














int main() {
//    int x = 42;
//    int *ptr = &x;
//    int &ref = x;
//      Player player;
//    player.increment(ptr);
//    player.incrementRef(ref);
//    std::cout << "x: " << x << std::endl; // Outputs 44
// cout << factor(5) <<" ";






}