#include <iostream>
using namespace std;

class A
{
public:
    int a;
    A(int n)
    {
        a = n;
    }
};

class B : public A
{
public:
    int b;
    B() : A(10)
    {
        b = a;
    }
    void disp()
    {
        cout << "\nb= " << b;
    }
};

int main()
{
    B b;
    b.disp();
}
