// 5+y
// x*y
// y-5
#include <iostream>
using namespace std;

class over
{
    int m;

public:
    over(int a)
    {
        m = a;
    }
    friend over operator+(int, over &);
    over operator*(over &w)
    {
        over o(0);
        o.m = m * w.m;
        return o;
    }
    over operator-(int n)
    {
        over o(0);
        o.m = m + n;
        return o;
    }
    void display()
    {
        cout << "A = " << m << endl;
    }
};

over operator+(int n, over &o)
{
    o.m += n;
    return o;
}

int main()
{
    over x(2), y(3);
    x = 5 + y;
    x.display();
    x = x * y;
    x.display();
    x = y - 5;
    x.display();
}