// Write a C++ program to study implementation of Hierarchical form of Inheritance
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

class B : public A
{
public:
    int b;
    B()
    {
        b = 20;
    }
    void add()
    {
        cout << " B sum= " << (a + b);
    }
};

class C : public A
{
public:
    int c;
    C()
    {
        c = 30;
    }
    void add()
    {
        cout << " C sum= " << (a + c);
    }
};

int main()
{
    C c;
    c.add();
    B b;
    b.add();
}