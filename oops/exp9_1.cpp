#include<iostream>
using namespace std;

void test(const int &a,const int &b)
{
    if(b == 0)
        throw b;
    else
        cout << "Answer= " << (a / b);
}

int main()
{
    int a = 5, b = 0;
    try
    {
        test(a, b);
    }
    catch(int i)
    {
        cout << "Error";
    }    
}
