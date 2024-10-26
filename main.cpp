#include<iostream>
using namespace std;
#include<fstream>
#include<string.h>
#include "mycontact.cpp"

my_contact obj,obj2;

void add_contact()
{
    obj2.accept();    //input values in memory

    fstream rd1;
    rd1.open("datafile.txt", ios::in);
    rd1.seekg(0, ios::end);
    int size1 = rd1.tellg()/sizeof(obj);    //finding size, to add at last

    rd1.seekg(0,ios::beg);  //set ptr to beg

    for(int i=1; i<=size1; i++)
    {
        rd1.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.mobile_no, obj2.mobile_no)==0)    //check by mobile
        {
            rd1.close();
            cout<<endl<<"\aContact Already Exists"<<endl;
            return;
        }
    }
    rd1.close();    //reading done

    //start writing
    fstream wr;
    wr.open("datafile.txt", ios::app);
    wr.write((char *)&obj2, sizeof(obj));
    wr.close();
    cout<<endl<<"\aContact Added"<<endl;
}

void remove_contact()
{
    char name[30];
    cout<<endl<<"Enter Name: ";
    cin>>name;  //enter name to check

    fstream rd1;
    rd1.open("datafile.txt", ios::in);
    rd1.seekg(0, ios::end);
    int size1=rd1.tellg()/sizeof(obj);  //find total size

    rd1.seekg(0, ios::beg);  //set ptr to beg

    for(int i=1; i<=size1; i++)
    {
        rd1.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.name, name)==0)    //deletion by name
        {
            rd1.close();
            cout<<"Record Found";

            //start creating new file
            fstream rd;
            rd.open("datafile.txt", ios::in);
            rd.seekg(0, ios::end);
            int size1=rd.tellg()/sizeof(obj);   //finding size
            rd.seekg(0, ios::beg);

            //create temp file for storing remaining data
            fstream wr;
            wr.open("tempfile.txt", ios::app);
            for(int i=1; i<=size1; i++)
            {
                rd.read((char *)&obj, sizeof(obj));
                if(strcmp(obj.name, name)==0)
                {
                    cout<<endl<<"\aRecord Removed"<<endl;
                }
                else
                {
                    wr.write((char *)&obj, sizeof(obj));
                }
            }
            rd.close();
            wr.close();
            remove("datafile.txt");
            rename("tempfile.txt", "datafile.txt");
            return;
        }
    }

    //if name not found
    rd1.close();
    cout<<"\aContact not in List"<<endl;
}


void update_contact()
{
    char name[30];
    cout<<endl<<"Enter Name: ";
    cin>>name;  //update by name

    fstream rd1;
    rd1.open("datafile.txt", ios::in);
    rd1.seekg(0, ios::end);
    int size1=rd1.tellg()/sizeof(obj);  //finding size

    rd1.seekg(0, ios::beg);  //set ptr to beg
    for(int i=1; i<=size1; i++)
    {
        rd1.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.name, name)==0)
        {
            rd1.close();
            cout<<endl<<"Record Found";

            //start creating new file
            fstream rd;
            rd.open("datafile.txt", ios::in);
            rd.seekg(0, ios::end);
            int size1=rd.tellg()/sizeof(obj);   //finding size

            rd.seekg(0,ios::beg);   //set ptr to beg

            //create temp file for storing updated + remaining data
            fstream wr;
            wr.open("tempfile.txt", ios::app);
            for(int i=1; i<=size1; i++)
            {
                rd.read((char *)&obj, sizeof(obj));
                if(strcmp(obj.name, name)==0)
                {
                    //use new object for updation
                    obj.accept();
                    cout<<"\aContact Updated"<<endl;
                }
                wr.write((char *)&obj, sizeof(obj));
            }
            rd.close();
            wr.close();
            remove("datafile.txt");
            rename("tempfile.txt", "datafile.txt");
            return;
        }
    }

    //else contact not found
    rd1.close();
    cout<<"\aContact not in List"<<endl;
}

void search_name()
{
    char name[30];
    cout<<endl<<"Enter Name: ";
    cin>>name;  //enter name

    fstream rd;
    rd.open("datafile.txt", ios::in);
    rd.seekg(0, ios::end);
    int s=rd.tellg()/sizeof(obj);   //finding size

    rd.seekg(0, ios::beg);  //set ptr to beg
    for(int i=1; i<=s; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.name, name)==0)
        {
            cout<<"Contact Found"<<endl;
            obj.initial();
            obj.display();
            cout<<endl;
            break;
        }
        if(i==s)
        {
            cout<<"\aContact Not in List"<<endl;
        }
    }

    rd.close();
}

void search_mobile()
{
    char mobile[15];
    cout<<endl<<"Enter Mobile Number: ";
    cin>>mobile;                            //enter mobile

    fstream rd;
    rd.open("datafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);           //finding size

    rd.seekg(0,ios::beg);                   //set ptr to beg
    for(int i=1; i<=s; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.mobile_no, mobile)==0)
        {
            cout<<"Contact Found"<<endl;
            obj.initial();
            obj.display();
            cout<<endl;
            break;
        }
        if(i==s)
        {
            cout<<"\aContact Not in List"<<endl;
        }
    }
    rd.close();
}

void search_email()
{
    char email[35];
    cout<<endl<<"Enter E-Mail: ";
    cin>>email;                         //enter email

    fstream rd;
    rd.open("datafile.txt", ios::in);
    rd.seekg(0, ios::end);
    int s=rd.tellg()/sizeof(obj);           //finding size

    rd.seekg(0, ios::beg);                  //set ptr to beg
    for(int i=1; i<=s; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        if(strcmp(obj.email, email)==0)
        {
            cout<<"Contact Found"<<endl;
            obj.initial();
            obj.display();
            cout<<endl;
            break;
        }
        if(i==s)
        {
            cout<<"\aContact Not in List"<<endl;
        }
    }
    rd.close();
}

void read_data()
{
    fstream rd;
    rd.open("datafile.txt", ios::in);
    rd.seekg(0, ios::end);
    int s=rd.tellg()/sizeof(obj);        //finding size
    rd.seekg(0, ios::beg);

    obj.initial();
    for(int i=1; i<=s; i++)
    {
        rd.read((char *)&obj, sizeof(obj));
        obj.display();
    }
    cout<<endl;
    rd.close();
}


int main()
{
    int choice;
    while(1)
    {
        cout<<endl<<"Press 1 to Add Contact";
        cout<<endl<<"Press 2 to Delete Contact";
        cout<<endl<<"Press 3 to Update Contact";
        cout<<endl<<"Press 4 to Search Contact by Name";
        cout<<endl<<"Press 5 to Search Contact by Mobile No.";
        cout<<endl<<"Press 6 to Search Contact by E-Mail";
        cout<<endl<<"Press 7 to Display all Contacts";
        cout<<endl<<"Press 8 to Exit";
        cout<<endl<<"Enter your choice: ";
        cin>>choice;

        if(choice==1)
        {
            add_contact();
        }
        else if(choice==2)
        {
            remove_contact();
        }
        else if(choice==3)
        {
            update_contact();
        }
        else if(choice==4)
        {
            search_name();
        }
        else if(choice==5)
        {
            search_mobile();
        }
        else if(choice==6)
        {
            search_email();
        }
        else if(choice==7)
        {
            read_data();
        }
        else if(choice==8)
        {
            break;
        }
        else
        {
            cout<<endl<<"\aInvalid input!!!";
            break;
        }
    }
}
