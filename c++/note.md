# Data structure        
int variable = 9; // -2billion - 2billion 1 byte  =  8 bits,4个byte一个int 2^31 interger,
char // 1byte,
short//2byte,
int //4 byte,
long //4byte,
long long // 8 byte

# 输入(input)
scan char **s**[int] type  cin.getline(**s**, **length**)
scan string **s** type getline(**cin**, **s**) 
void 表示没有输出结果不能使用cout输出结果
endl means enter equals "\n" 
数组变量无法修改： 因为数组本质上是一个指针

# 输出(output)
puts(s) equals to printf("%s\n", s)

常用函数：strlen,strcmp, strcpy赋值

字典序和贪心算法相关，

一般不使用 char s[int], 一般使用string,使用库**#include<cstring>**
读入string s 方法： getline(cin, string); cin >> string

# String
# Array
# Stack Heap and Ptr
the  public var use heap(dui) from bottom to top, the pravite var use stack(zhan) from the top to bottom
a = 10;
int* p = &a;
*p = 12
cout << *p << endl; //output:12
cout << a << endl; //output: 12

int** q = &p;

int &p = a (equals) int *p = &a

#  Linked
struct Node
{
    int val;
    Node* next;
    Node(int _val): val(_val), next(NULL) {}

};
int main()
{
    Node* p= new Node(1); //return address;
    Node* q = new Node(2);    
    p -> next = q;
    p -> val;
    Node p;
    p.next
    p.val

}