#include <iostream>
using namespace std;
int main()
{
    int count[6], n, num;
    cout << "ENter number of voters: ";
    cin >> n;
    for (int i = 0; i <= 5; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter ballot number: ";
        cin >> num;
        if (num >= 1 && num <= 5)
            count[num]++;
        else
            count[0]++;
    }
    cout << "Number of votes for candidate: ";
    for (int i = 1; i <= 5; i++)
        cout << "\ncandidate " << i << " : " << count[i];
    cout << "\nInvalid ballots: " << count[0];
}