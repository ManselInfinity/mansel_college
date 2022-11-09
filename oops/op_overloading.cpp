// unary postfix and prefix increment overloading
#include <iostream>
using namespace std;

class over
{
    int m, n;

public:
    over(int a, int b)
    {
        m = a;
        n = b;
    }
    void operator++()
    {
        ++m;
        ++n;
    }
    void operator++(int)
    {
        ++m;
        ++n;
    }
    void display()
    {
        cout << "A = " << m << " B = " << n << endl;
    }
    void operator--()
    {
        --m;
        --n;
    }
    friend void operator--(over &, int);
};

void operator--(over &o, int n)
{
    o.m--;
    o.n--;
}

int main()
{
    over o(1, 2);
    o.display();
    ++o;
    o.display();
    o--;
    o.display();
    o++;
    o.display();
}