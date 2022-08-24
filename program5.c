#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,int no)
{
    PNODE newn=NULL;
    
    //step 1:Allocate the Memory
    newn=(PNODE)malloc(sizeof(NODE));
    
    //step 2:Initialise the Node
    newn->data=no;
    newn->next=NULL;

    //step 3:Insert the node
    if((*Head)==NULL) //LL is Empty
    {
      *Head=newn;
    }
    else  //LL contain atleast one node
    {
      newn->next=*Head;
      *Head=newn;
    }
}

void InsertLast(PPNODE Head,int no)
{
    PNODE newn=NULL;
    PNODE temp=*Head;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
          temp=temp->next;
        }
        temp->next=newn;
    }
}

void Display(PNODE Head)
{
    while(Head!=NULL)
    {
        printf("%d\n",Head->data);
        Head=Head->next;
    }
}

int Count(PNODE Head)
{
    int iCnt=0;
    while(Head!=NULL)
    {
        iCnt++;
        Head=Head->next;
    }
    return iCnt;
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp=*Head;

    if(*Head!=NULL) //LL contain atleast one node
    {
     *Head=(*Head)->next;
     free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp=*Head;

    if(*Head==NULL) //LL is Empty
    {
        return;
    }
    else if((*Head)->next==NULL) //LL contain one node
    {
        free(*Head);
        *Head=NULL;
    }
    else //LL contain more than one node
    {
     while(temp->next->next!=NULL)
     {
        temp=temp->next;
     }
     free(temp->next);
     temp->next=NULL;
    }
}
int main()
{
    PNODE first=NULL;
    int iRet=0;

    InsertFirst(&first,44);  //InsertFirst(50,44);
    InsertFirst(&first,33);  //InsertFirst(50,33);
    InsertFirst(&first,22);  //InsertFirst(50,22);
    InsertFirst(&first,11);  //InsertFirst(50,11);

    InsertLast(&first,55); 

    Display(first); //Display(100)

    iRet=Count(first);
    printf("Number of Elements are : %d\n",iRet);

    DeleteFirst(&first);

    Display(first);

    iRet=Count(first);
    printf("Number of Elements are : %d\n",iRet);

    DeleteLast(&first);

    Display(first);

    iRet=Count(first);
    printf("Number of Elements are : %d\n",iRet);
    return 0;
}

/*
   void InsertFirst(PPNODE Head, int no)
   void InsertLast(PPNODE Head, int no)
   void  InsertAtPos(PPNODE Head,  int no, int pos)
   
   void  DeleteFirst(PPNODE Head)
   void  DeleteLast(PPNODE Head)
   void  DeleteAtPos(PPNODE Head, int pos)
   
    void Display(PNODE Head)
    int Count(PNODE Head)
 */