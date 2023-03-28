//
// Created by Zhengtian  on 29/3/2023.
//
#include "iostream"
using namespace std;
class solution{
public:
    int countVowelStrings(int n){
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};
int main(){
    solution s;
    s.countVowelStrings(2);
    cout << s.countVowelStrings(2) << endl;
}