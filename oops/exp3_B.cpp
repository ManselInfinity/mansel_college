#include<iostream>
using namespace std;

class add
{
    int a, b;
    public:
    add(int m, int n)
    {
        a=m;
        b=n;
    }
    add(add &x)
    {
        a=x.a;
        b=x.b;
    }
    int ad()
    {
        return a+b;
    }
};

int main()
{
    int a, b;
    cout<<"enter values: ";
    cin>>a>>b;
    add A(a, b);
    add B(A);
    cout<<endl<<"Sum: "<<B.ad();
}