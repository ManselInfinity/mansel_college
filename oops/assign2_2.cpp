//100 - 60p
//next 200 - 80p
//beyond 300 - 90p
//min 50rs, >300=>15% extra


#include<iostream>
using namespace std;

class bill
{
    int units;
    float cost;
    string name;
    public:
    void compute()
    {
    cout<<"\nEnter name: ";
    cin>>name;
    cout<<"\nEnter units: ";
    cin>>units;
    if(units<=100)
        cost=units*60;
    else if(units<=300)
        cost=units * 80;
    else
        cost = units * 90;
   
    if((cost/100)<50)
     cost = 50;
    else if((cost/100) > 300)
     cost += cost*0.15;
    cout<<"Name: "<<name<<"Bill: "<<(cost/100);
    }
};


void main()
{
    bill b;
    b.compute();
}