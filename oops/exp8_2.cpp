// vector of n elements
// scaler multiply with each element
// add 2 vectors

#include <iostream>
using namespace std;

template<class T>
class vector
{
    T *n;
    int l;

public:
    vector(int m)
    {
        n = new T(m);
        l = m;
    }
    void input()
    {
        int b = l;
        for (int i = 0; i < b; i++)
        {
            cout << "Enter value: ";
            cin >> n[i];
            cout << endl;
        }
    }

    friend vector operator+(vector &v, vector &v2)
    {
        int b = v.l;
        vector X(b);
        for (int i = 0; i < b; i++)
        {
            X.n[i] = v.n[i] + v2.n[i];
        }
        return X;
    }

    friend vector operator*(vector &v, int n)
    {
        int b = v.l;
        vector X(b);
        for (int i = 0; i < b; i++)
        {
            X.n[i] = v.n[i] * n;
        }
        return X;
    }

    void print()
    {
        int b = l;
        for (int i = 0; i < b; i++)
        {
            cout << " " << n[i];
        }
    }
};

int main()
{
    int l;
    cout << "Enter lenght: ";
    cin >> l;
    vector<int> v1(l), v2(l), v3(l), v4(l);
    v2.input();
    cout << "\nEnter v2:\n";
    v3.input();
    v1 = v2 * 5;
    cout << "V1 * 5 = ";
    v1.print();
    v4 = v2 + v3;
    cout << "\nv1 + v2 =";
    v4.print();
}
