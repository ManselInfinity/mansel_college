#include <iostream>
using namespace std;

class add
{
    int a, b;

public:
    add(int m, int n)
    {
        cout << "\nCreating object";
        a = m;
        b = n;
    }
    add(add &x)
    {
        a = x.a;
        b = x.b;
    }
    ~add()
    {
        cout << "\nDestroying object\n";
    }
    int ad()
    {
        return a + b;
    }
};

int main()
{
    int a, b;
    cout << "enter values: ";
    cin >> a >> b;
    add A(a, b);
    add B(A);
    {
        cout << "\nInside block in main\n";
        add C(5, 9);
    }
    cout<<"\nIn main again";
    cout << endl
         << "\nSum: " << B.ad();
}