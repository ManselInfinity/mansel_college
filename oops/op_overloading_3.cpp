// binary insertion and extraction
#include <iostream>
using namespace std;

class test
{
    int n;

public:
    friend void operator>>(istream &w1, test &w2)
    {
        w1 >> w2.n;
    }
    friend void operator<<(ostream &w1, test &w2)
    {
        w1 << w2.n;
    }
};
int main()
{
    test t1;
    cout << "enter value";
    cin >> t1;
    cout << t1;
    return 0;
}