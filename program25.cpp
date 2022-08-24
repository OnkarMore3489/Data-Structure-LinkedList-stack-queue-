//Stack practice

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;

class Stack
{
    private:
            PNODE first;
            int size;

    public:
           Stack();
           void Push(int no);
           int Pop();
           void Display();
           int Count();
};

Stack::Stack()
{
    first=NULL;
    size=0;
}

void Stack::Push(int no)
{
    PNODE newn=NULL;

    newn=new NODE;

    newn->data=no;
    newn->next=NULL;

    if(first==NULL)
    {
        first=newn;
    }
    else 
    {
        newn->next=first;
        first=newn;
    }
    size++;
}

int Stack::Pop()
{
    int no=0;
    PNODE temp=first;

    if(first==NULL)
    {
        cout<<"Stack is Empty"<<"\n";
        return -1;
    }
    else if(first->next==NULL)
    {
        no=first->data;
        delete first;
        first=NULL;
    }
    else 
    {
        no=first->data;
        first=first->next;
        delete temp;
    }
    size--;
    return no;
}

void Stack::Display()
{
    PNODE temp=first;

    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"\n";
        temp=temp->next;
    }
}

int Stack::Count()
{
    return size;
}
int main()
{
    Stack obj;
    int iRet1=0;
    int iRet2=0;

    obj.Push(101);
    obj.Push(51);
    obj.Push(21);
    obj.Push(11);

    cout<<"Elements in the stack are : "<<"\n";
    obj.Display();
    iRet1=obj.Count();
    cout<<"Number of Elements in stack are : "<<iRet1<<"\n";

    iRet2=obj.Pop();
    cout<<"Poped Element is : "<<iRet2<<"\n";

    cout<<"Elements in the stack are : "<<"\n";
    obj.Display();
    iRet1=obj.Count();
    cout<<"Number of Elements in stack are : "<<iRet1<<"\n";

    return 0;
}