#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float sum = 0;

    cout << setw(2) << "n";
    cout << setw(15) << "Inverse_of_n";
    cout << setw(15) << "Sum_of_terms" << endl;

    for (int i = 1; i <= 10; i++)
    {
        cout << setw(2) << setiosflags(ios::right) << i;
        sum += 1.0 / i;
        cout << setw(15) << setprecision(4) << setiosflags(ios::scientific) << (1.0 / i);
        cout << setw(12) << resetiosflags(ios::scientific) << setprecision(5) << setiosflags(ios::left) << setiosflags(ios::showpoint) << sum << endl;
    }
}