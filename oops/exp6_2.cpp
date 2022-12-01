#include <iostream>
using namespace std;

class A
{
public:
    virtual void show() = 0;
};

class B : public A
{
public:
    void show()
    {
        cout << "Inside B\n";
    }
};

int main()
{
    A *ptr;
    B b;
    ptr = &b;
    ptr->show();
}