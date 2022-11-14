// Write a C++ program to study implementation of Hybrid form of Inheritance(Virtual Base
// Class)
#include <iostream>
using namespace std;

class A
{
public:
    int a;
    A()
    {
        a = 10;
    }
};

class B : virtual public A
{
public:
    int b;
    B()
    {
        b = 20;
    }
};

class C : virtual public A
{
public:
    int c;
    C()
    {
        c = 30;
    }
};

class D : public B, public C
{
public:
    int d;
    D()
    {
        d = 48;
    }
    void add()
    {
        cout << "D sum = " << (a + b + c + d);
    }
};

int main()
{
    D d;
    d.add();
}