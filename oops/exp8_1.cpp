#include <iostream>
using namespace std;

template <class T>
void swapp(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10, b = 20;
    swapp(a, b);
    cout << "a= " << a << "b= " << b;
}
