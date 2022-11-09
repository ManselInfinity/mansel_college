#include<iostream>
using namespace std;

class add
{
    public:
    int ad(int &a, int &b)
    {
        return a+b;
    }
};

int main()
{
    int a, b;
    add A;
    cout<<"enter values: ";
    cin>>a>>b;
    cout<<endl<<"Sum: "<<A.ad(a, b);
}