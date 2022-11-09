#include<iostream>
using namespace std;

class complex
{
    int real, img;
    public:
    void display()
    {
        cout<<real<<" "<<img<<"i\n";
    }
    void inp()
    {
    cout<<"\nEnter number : ";
    cin>>real>>img;
    }
    friend complex sum(complex &a, complex &b);
};

complex sum(complex &a, complex &b)
{
    complex c;
    c.real=a.real + b.real;
    c.img = a.img + b.img;
    return c;
}

int main()
{
    complex a, b, c;
   
    a.inp();
    b.inp();
    c=sum(a ,b);
    c.display();
    }

