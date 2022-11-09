// to add two strinf type obects
//  to compare two string lengths and print the smaller one
#include <iostream>
#include <string.h>
using namespace std;
class String
{
    string s1;

public:
    String(string s)
    {
        s1 = s;
    }
    String operator+(String &s)
    {
        String x("");
        x.s1 = s1 + s.s1;
        return x;
    }
    bool operator>(String &s)
    {
        if (s.s1.size() > s1.size())
            return true;
        else
            return false;
    }
    void display()
    {
        cout << "\nstring: " << s1 << endl;
    }
};

int main()
{
    String s1(""), s2("string 2"), s3("string 3 bigger");
    s1 = s2 + s3;
    s1.display();
    if (s2 > s3)
    {
        cout << "Smaller ";
        s2.display();
    }
    else
    {
        cout << "Smaller ";
        s3.display();
    }
}