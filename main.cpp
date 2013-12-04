#include <iostream>
#include <stdlib.h>
#include "tree.h"

using namespace std;

class ConsoleSet: public Set
{
public:
    void output() const;
    ConsoleSet(int n):Set(n) {}
    ConsoleSet():Set() {}
    ConsoleSet &operator=(const Set &other)
    {
        Set::operator=(other);
        return *this;
    }
};

int main()
{
    int w=0,kol_vo,choice;
    ConsoleSet tr;
    cout<<"Input a size of sequence: ";
    cin>>kol_vo;
    cout<<"Manual input(1) or random(any value)?"<<endl;
    cin>>choice;
    int data;
    if (choice==1)
    {
        for(int i=0; i<kol_vo; i++)
        {
            cout<<"Enter value ";
            cin>>data;
            if(tr.check(data)!=0)
                cout<<"value already in sequence"<<endl;
            else
                tr.push(data);
        }
    }
    else
    {
        for(int i=0; i<kol_vo; i++)
        {
            int data=rand()%100;
            if(tr.check(data)==0)
                tr.push(data);
            else
                kol_vo++;
        }
    }
    do
    {
        cout<<"select the required operation:"<<endl;
        cout<<" 1 - show sequence"<<endl;
        cout<<" 2 - is in sequence"<<endl;
        cout<<" 3 - exit"<<endl<<endl;
        cin>>w;
        switch(w)
        {
        case 1:
            if(tr.is_empty()==true)
                cout<<"Sequence empty";
            else
            {
                tr.output();
            }
            cout<<endl<<endl;
            break;
        case 2:
        {
            if(tr.is_empty()==true)
                cout<<"Sequence empty";
            else
            {
                bool u;
                int key;
                cout<<"enter value to check: ";
                cin>>key;
                if((u=tr.check(key))!=false)
                {
                    cout<<"Founded"<<endl<<endl;
                }
                else
                    cout<<"Nothing";
            }
            break;
        }
        case 3:
            break;
        }
    }
    while(w!=3);
}

void ConsoleSet::output() const
{
    int *datum;
    int q,m;
    q=quantity();
    datum=new int[q];
    cout<<"Show by left(1) or right(any value)?"<<endl;
    cin>>m;
    if (m==1)
    nextDatum(datum);
    else
    nextDatum_right(datum);
    for(int i=0; i<q; i++)
        cout<<datum[i]<<"  ";
}
