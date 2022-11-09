#include<iostream>
using namespace std;
class over
{
    public:
    int area(int a, int b)
    {
        return a*b;
    }
    int area(int r)
    {
        return r*r*3.14;
    }
};

int main()
{
    int a, b,cho;
    over A;
    cout<<"Enter 1 t ofind area of rectangle, 2 for circle: ";
    cin>>cho;
    if(cho == 1)
    {
        cout<<endl<<"Input l and b: ";;
        cin>>a>>b;
        cout<<endl<<"area: "<<A.area(a, b);
    }
    else
    {   
        cout<<endl<<"Input r: ";;
        cin>>a;
        cout<<endl<<"area: "<<A.area(a);
    }
}

