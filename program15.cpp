#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;

class SinglyCL
{
    private:
           PNODE first;
           PNODE last;
           int size;

    public:
           SinglyCL();
           void Display();
           int Count();
           void InsertFirst(int no);
           void InsertLast(int no);
           void InsertAtPos(int no,int pos);
           void DeleteFirst();
           void DeleteLast();
           void DeleteAtPos(int pos);
};

SinglyCL::SinglyCL()
{
    first=NULL;
    last=NULL;
    size=0;
}

void SinglyCL::Display()
{
    PNODE temp=first;

    do
    {
        cout<<"|"<<temp->data<<"|"<<"->";
        temp=temp->next;
    } while(temp!=last->next);
}

int SinglyCL::Count()
{
    return size;
}

void SinglyCL::InsertFirst(int no)
{
    PNODE newn=NULL;

    newn=new NODE;

    newn->data=no;
    newn->next=NULL;

    if(first==NULL && last==NULL)
    {
        first=newn;
        last=newn;
    }
    else
    {
        newn->next=first;
        first=newn;
    }
    last->next=first;
    size++;
}


void SinglyCL::InsertLast(int no)
{
    PNODE newn=NULL;

    newn=new NODE;

    newn->data=no;
    newn->next=NULL;

    if(first==NULL && last==NULL)
    {
        first=newn;
        last=newn;
    }
    else
    {
        last->next=newn;
        last=newn;
    }
    last->next=first;
    size++;
}

void SinglyCL::InsertAtPos(int no,int pos)
{
    if(pos < 1 || pos > size+1)
    {
        return;
    }

    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos==size+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn=NULL;
        PNODE temp=first;

        newn=new NODE;

        newn->data=no;
        newn->next=NULL;

        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        size++;
    }
}

void SinglyCL::DeleteFirst()
{
    if(first==NULL && last==NULL)
    {
        return;
    }
    else if(first==last)
    {
        delete first;
        first=NULL;
        last=NULL;
    }
    else
    {
        first=first->next;
        delete last->next;
        last->next=first;
    }
    size--;
}

void SinglyCL::DeleteLast()
{
    if(first==NULL && last==NULL)
    {
        return;
    }
    else if(first==last)
    {
        delete last;
        first=NULL;
        last=NULL;
    }
    else
    {
        PNODE temp=first;

        while(temp->next!=last)
        {
            temp=temp->next;
        }
        delete last;
        last=temp;
        last->next=first;
    }
    size--;
}

void SinglyCL::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > size)
    {
        return;
    }

    if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos==size)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp=first;
        PNODE targeted=NULL;

        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        targeted=temp->next;
        temp->next=targeted->next;
        delete targeted;

        size--;
    }
}
int main()
{
    int iChoice = 1, value = 0, iRet = 0, pos = 0;
    SinglyCL obj;
    
    while(iChoice != 0)
    {
        printf("\n_________________________________________________________\n");
        printf("Enter the desired operation that you want to perform on LinkedList\n");
        printf("1 : Insert the node at first position\n");
        printf("2 : Insert the node at last position\n");
        printf("3 : Insert the node at  the desired position\n");
        printf("4 : Delete the first node\n");
        printf("5 : Delete the last node\n");
        printf("6 : Delete the node at desired position\n");
        printf("7 : Display the contents of linked list\n");
        printf("8 : Count the number of nodes from linked list\n");
        printf("0 : Terminate the application\n");
        printf("\n_________________________________________________________\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter the data to insert : \n");
                scanf("%d",&value);
                obj.InsertFirst(value);
                break;
                
            case 2:
                printf("Enter the data to insert : \n");
                scanf("%d",&value);
                obj.InsertLast(value);
                break;
                
            case 3:
                printf("Enter the data to insert : \n");
                scanf("%d",&value);
                printf("Enter the position : \n");
                scanf("%d",&pos);
                obj.InsertAtPos(value,pos);
                break;
                
            case 4:
                obj.DeleteFirst();
                break;
                
            case 5:
                obj.DeleteLast();
                break;
                
            case 6 :
                printf("Enter the position : \n");
                scanf("%d",&pos);
                obj.DeleteAtPos(pos);
                break;
                
            case 7:
                printf("Element of Linked list are : \n");
                obj.Display();
                break;
                
            case 8:
                iRet = obj.Count();
                printf("Number of elements are : %d\n",iRet);
                break;
                
            case 0:
                printf("Thank for using Marvellous Linked List\n");
                break;
                
            default:
                printf("Please enter proper choice\n");
                break;
        }
    }
    return 0;
}