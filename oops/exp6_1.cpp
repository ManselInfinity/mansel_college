#include <iostream>
using namespace std;

class A
{
public:
    virtual void show()
    {
        cout << "inside A\n ";
    }
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