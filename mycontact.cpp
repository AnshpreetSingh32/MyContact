#include<iostream>
using namespace std;
#include<iomanip>

class my_contact
{
    char name[50], mobile_no[50], email[50], insta[50], twit[50];
    public:
        void accept()
        {
            cout<<endl<<"Enter Name-> ";
            cin>> name;
        //----------------------------------------------
            cout<<endl<<"Enter Mobile Number-> ";
            cin>> mobile_no;
        //----------------------------------------------
            cout<<endl<<"Enter E-Mail-> ";
            cin>> email;
        //----------------------------------------------
            cout<<endl<<"Enter Instagram Account-> ";
            cin>>insta;
        //----------------------------------------------
            cout<<endl<<"Enter Twitter Account-> ";
            cin>>twit;
        }

        void initial()
        {
            cout<<endl;
            cout<<left;
            cout<<setw(30);
            cout<<"NAME";
        //----------------------------------------------
            cout<<setw(15);
            cout<<"MOBILE NUMBER";
        //----------------------------------------------
            cout<<setw(35);
            cout<<"EMAIL ADDRESS";
        //----------------------------------------------
            cout<<setw(20);
            cout<<"INSTAGRAM";
        //----------------------------------------------
            cout<<setw(20);
            cout<<"TWITTER";
            cout<<endl;
            cout<<"***************************** ************** ********************************** ******************* ********************";
        }
        void display()
        {
            cout<<endl;
            cout<<left;
            cout<<setw(30);
            cout<<name;
        //----------------------------------------------
            cout<<setw(15);
            cout<<mobile_no;
        //----------------------------------------------
            cout<<setw(35);
            cout<<email;
        //----------------------------------------------
            cout<<setw(20);
            cout<<insta;
        //----------------------------------------------
            cout<<setw(20);
            cout<<twit;
        }
        friend void add_contact();
        friend void remove_contact();
        friend void update_contact();
        friend void search_name();
        friend void search_mobile();
        friend void search_email();
};
void add_contact();
void remove_contact();
void update_contact();
void search_name();
void search_mobile();
void search_email();
