//Queue practice

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;

class Queue
{
    private:
            PNODE first;
            int size;

    public:
           Queue();
           void Enqueue(int no);
           int Dequeue();
           void Display();
           int Count();
};

Queue::Queue()
{
    first=NULL;
    size=0;
}

void Queue::Enqueue(int no)
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
       PNODE temp=first;

       while(temp->next!=NULL)
       {
           temp=temp->next;
       }
       temp->next=newn;
   }
   size++;
}

int Queue::Dequeue()
{
    int no=0;
    PNODE temp=first;

    if(first==NULL)
    {
        cout<<"Queue is Empty"<<"\n";
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

void Queue::Display()
{
    PNODE temp=first;

    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"\n";
        temp=temp->next;
    }
}

int Queue::Count()
{
    return size;
}
int main()
{
    Queue obj;
    int iRet1=0;
    int iRet2=0;

    obj.Enqueue(101);
    obj.Enqueue(51);
    obj.Enqueue(21);
    obj.Enqueue(11);

    cout<<"Elements in the Queue are : "<<"\n";
    obj.Display();
    iRet1=obj.Count();
    cout<<"Number of Elements in Queue are : "<<iRet1<<"\n";

    iRet2=obj.Dequeue();
    cout<<"dequeued Element is : "<<iRet2<<"\n";

    cout<<"Elements in the Queue are : "<<"\n";
    obj.Display();
    iRet1=obj.Count();
    cout<<"Number of Elements in Queue are : "<<iRet1<<"\n";

    return 0;
}