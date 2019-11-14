#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct Node
{
    char *name;
    char *classtype;
    Node *next;
};
///
//Declare starting (Head) node
struct Node *head=NULL;
//Insert node at start
void insertNode(char *n, char *c)
{
    int flag=0;
    struct Node *temp=head;
    while(temp!=NULL)
    {
        if(strcmp( temp->name, n )==0)
        {
            flag=1;
        }
        temp = temp->next;
    }
    if(flag==0)
    {
        struct Node *newNode=new Node;
        newNode->name=n;
        newNode->classtype=c; //
        newNode->next=head;
        head=newNode;
    }
    else
    {
        cout<<"This entry already exist"<<endl;
    }
}
//Update
void update(char *n, char *c, char *cNew)
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        if(!strcmp(temp->name,n) && !strcmp(temp->classtype,c))
        {
            temp->classtype=cNew;
        }
        temp = temp->next;
    }
}
//delete node from start
void delete_position(int pos)
{
    pos=pos+1;
    int i;
    //beginning
    if(pos==1)
    {
        Node *temp=new Node;
        temp=head;
        head=head->next;
        delete temp;
    }
    //middle or last
    else
    {
        Node *current=new Node;
        Node *previous=new Node;
        current=head;
        for(i=1;i<pos;i++)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
    }
}

//Search
void Search(char *n, char *c)
{
    int cnt=0;
    int flag1=0;
    struct Node *temp=head;
    while(temp!=NULL)
    {
        cnt++;
        if(!strcmp(temp->name,n) && !strcmp(temp->classtype,c))
        {
            flag1=1;
            //return true;
            cout<<"Found at position: "<<cnt<<" --->";
            cout<<temp->name<<":"<<temp->classtype<<endl;
            break;
        }
        temp = temp->next;
    }
    if(flag1==0)
    {
        cout<<"Not Found"<<endl;
    }
}
//Traverse/ display all nodes (print items)
void display()
{
    if(head==NULL)
    {
        cout<<"List is empty!"<<endl;
        return;
    }
    struct Node *temp=head;
    cout<<endl<<endl<<endl<<"--------------------------Symbolic Table----------------------------"<<endl;
    cout<<"name : class type"<<endl;
    cout<<"-----------------"<<endl;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        cout<<cnt<<"- "<<temp->name<<" : "<<temp->classtype<<endl;
        temp=temp->next;
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
}



int showMenu()
{
    system("color F");
    cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Welcome to the Main Menu \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    string message = "1: Insert (name, class type)\n"
                     "2: Update (name, class type, new class type)\n"
                     "3: Search (name, class type)\n"
                     "4: Delete (name, class type)\n"
                     "5: View Table\n";
    cout << message << "\n";


    cout << "User Choice: ";
    int select;
    //scanf("%d", &choice);
    cin>>select;

    return select;
}

int main()
{
    int select = showMenu();
    while(1)
    {
        char *name = new char[100];
        char *classtype = new char[100];
        char *newClasstype = new char[100];

        switch(select)
        {
        case 1:
            {
                cout <<"Insert Operation:\n";
                cin>>name>>classtype;

                if(name[strlen(name)-1]==',')
                    name[strlen(name)-1]='\0';

                insertNode(name,classtype);
            }
            break;
        case 2:
            {
                cout<<"Update Operation:"<<endl;
                cin>>name>>classtype>>newClasstype;

                if(name[strlen(name)-1]==',')
                    name[strlen(name)-1]='\0';
                if(classtype[strlen(classtype)-1]==',')
                    classtype[strlen(classtype)-1]='\0';

                update(name,classtype,newClasstype);
            }
            break;
        case 3:
            {
                cout<<"Search Operation:"<<endl;
                cin>>name>>classtype;

                if(name[strlen(name)-1]==',')
                    name[strlen(name)-1]='\0';

                Search(name,classtype);
            }
            break;
        case 4:
            {
                cout<<"Delete Operation:"<<endl;
                cin>>name>>classtype;

                if(name[strlen(name)-1]==',')
                    name[strlen(name)-1]='\0';

                int pos=-1;
                int flag=0;
                struct Node *temp=head;
                while(temp!=NULL)
                {
                    pos++;
                    if(!strcmp(temp->name,name) && !strcmp(temp->classtype,classtype))
                    {
                        //return true;
                        flag=1;
                        break;
                    }
                    temp = temp->next;
                }
                if(flag==0)
                {
                    cout<<"Data you have wanted to delete is not in the List"<<endl;
                }
                if(flag==1)
                {
                    delete_position(pos);
                }
            }
            break;
        case 5:
            {
                cout<<"Display Operation:"<<endl;
                display();
            }
            break;
        default:
            {
                cout<<"Input Correctly among 1 to 5"<<endl;
                break;
            }
        }
        cout<<"\n\npress 'y' to go to main menu again: ";
        char yes;
        cin>>yes;
        if(yes=='y')
        {
            system("cls");
            select = showMenu();
        }
    }

    return 0;
}

