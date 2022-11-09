#include <iostream>
using namespace std;

class DB;
class DM
{
    float m, cm;

public:
    void get()
    {
        cout << "Enter meters and cm: ";
        cin >> m >> cm;
    }
    friend void sum(DM, DB);
};

class DB
{
    float ft, in;

public:
    void get()
    {
        cout << "Enter feet and inches";
        cin >> ft >> in;
    }
    friend void sum(DM, DB);
};

void sum(DM a, DB b)
{
    a.m += (b.ft / 3.28);
    a.cm += (b.in * 2.54);
    cout << a.m << "m "
         << " " << a.cm << " cm\n";
}

int main()
{
    DB a;
    DM b;
    a.get();
    b.get();
    cout << "Added value in m and cm is : ";
    sum(b, a);
}
