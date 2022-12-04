// entert a string and output 1.no of lines, 2. no of words , 3. no of characters strings left justifies and numbers right justified
#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    int length = s.length(), numWords = 0, numLines = 1;
    for (int i = 0; i < length; i++)
    {
        if (s[i] == ' ')
        {
            numWords++;
            continue;
        }
        else if (s[i] == '.')
        {
            numWords++;
            numLines++;
            continue;
        }
    }
    cout.width(15);
    cout << "No of lines";
    cout.width(15);
    cout << "No of words";
    cout.width(15);
    cout << "No of chars";

    cout << endl;
    cout.setf(ios::right, ios::adjustfield);
    cout.width(15);
    cout << numLines;
    cout.width(15);
    cout << numWords;
    cout.width(15);
    cout << length;
}
