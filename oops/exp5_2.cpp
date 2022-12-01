#include <iostream>
using namespace std;

class student
{
public:
    int number = 100;
    void disp()
    {
        cout << "\nStudent:"
             << number;
    }
};

class arts : virtual public student
{
public:
    int art_marks = 100;
    void disp()
    {
        cout << "\nArt marks: "
             << art_marks;
    }
};

class engineering : virtual public student
{
public:
    int eng_mks = 100;
    void disp()
    {
        cout << "\nEng marks: "
             << eng_mks;
    }
};

class medical : virtual public student
{
public:
    int med_mks = 100;
    void disp()
    {
        cout << "\nMed marks: "
             << med_mks;
    }
};

class mech : virtual public engineering
{
public:
    int mech_mks = 100;
    // engineering::disp();
    void disp()
    {
        cout << "\nmech marks: "
             << eng_mks;
    }
};

class elect : virtual public engineering
{
public:
    int elect_mks = 100;
    void disp()
    {
        cout << "\nElect marks: "
             << elect_mks;
    }
};

class civil : virtual public engineering
{
public:
    int civil_mks = 100;
    void disp()
    {
        cout << "\nCivil marks: "
             << civil_mks;
    }
};

int main()
{
    arts a;
    medical m;
    mech mh;
    elect e;
    civil c;
    a.disp();
    m.disp();
    mh.disp();
    e.disp();
    c.disp();
}
