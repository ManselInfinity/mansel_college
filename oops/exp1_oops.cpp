// 1. insert, 2.search(name, ath), 3.display entire book list 4. exit

#include <iostream>
#include <string>
using namespace std;

class one
{
public:
    int num;
    string name, ath;
    void ins(int count)
    {
        cout << endl
             << "Enter author name: ";
        cin>>ath;
        cout << endl
             << "Enter book name: ";
        cin>>name;
        num = 1000 + count;
    }

    void scr(int count, one o[])
    {
        cout << "Enter 1 to search for author or 2 for title: ";
        int cho, i,flag=0;
        cin >> cho;
        string na;
        switch (cho)
        {
        case 1:
            cout << "Enter author name: ";
            cin >> na;
            for (i = 0; i < count; i++)
            {
                if (o[i].ath.compare(na) == 0)
                {
                    cout << endl << "Found book :" << endl;
                    cout << "Title: " << o[i].name << endl;
                    cout << "Author: " << o[i].ath << endl;
                    cout << "serial no: " << o[i].num << endl;
                    flag=1;
                    break;
                }
            }
            if (flag != 1)
                cout << "Book not found" << endl;
            break;

        case 2:
            cout << "Enter Book title: ";
            cin >> na;
            for (i = 0; i < count; i++)
            {
                if (o[i].name.compare(na) == 0)
                {
                    cout << endl << "Found book :" << endl;
                    cout << "Title: " << o[i].name << endl;
                    cout << "Author: " << o[i].ath << endl;
                    cout << "serial no: " << o[i].num << endl;
                    flag =1;
                    break;
                }
            }
            if (flag != 1)
                cout << "Book not found" << endl;
            break;

        default:
            cout << "Wrong choice";
        }
    }

    void printo()
        {
            cout << "Title: " << name << endl;
            cout << "Author: " << ath << endl;
            cout << "serial no: " << num << endl;
        }
};
int main()
{
    int cho = 0, count = 0;
    one o[50];
    while (cho != 4)
    {
        cout << "Enter :\n1.To insert book\n2.To search book\n3.to Dislay all books\n4.To exit\nChoice: ";
        cin >> cho;
        cout<<endl;
        switch (cho)
        {
        case 1:
            o[count].ins(count);
            count++;
            break;

        case 2:      
            o[0].scr(count, o);
            break;

        case 3:
            int i;
            for (i = 0; i < count; i++)
                o[i].printo();
             break;
        }
    }
}