#include "iostream"
#include "string"
using namespace std;


bool isGoodstring(string s)
{
    string s1;
    for(auto a:s){
        if(::isalpha(a)){
            s1 += tolower(a);
        }
    }
    string s2(s1.rbegin(),s1.rend());
    return s1 == s2;
}

int main()
{
    string n;
    cin >> n;
    cout << isGoodstring(n) << endl;
    return 0;
}