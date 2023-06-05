#include <iostream>
using namespace std;
int max_value(int num){
    int count = 0;
    if(num == 1) return 0;

    else if(num == 2) return 1;
    else return num/3 + max_value(num/3 + num % 3);
}

int main()
{
    int num;
    while(cin >> num)
    {
        if(num == 0){
            break;
        }
        else{
            int count = max_value(num);
            cout << count << endl;
        }
    }
    return 0;
}