#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE,**PPNODE;

int size=0;

void Display(PNODE Head,PNODE Tail)
{
    PNODE temp=(Head);

    for(int i=1;i<=size;i++)
    {
        printf("|%d| ->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
    printf("\n");
}

int Count()
{
    return size;
}
void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((*Head==NULL) && (*Tail==NULL))
    {
        (*Head)=newn;
        (*Tail)=newn;
    }
    else
    {
        newn->next=(*Head);
        (*Head)->prev=newn;
        (*Head)=newn;
    }
    (*Tail)->next=(*Head);
    (*Head)->prev=(*Tail);
    size++;
}

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((*Head==NULL) && (*Tail==NULL))
    {
        (*Head)=newn;
        (*Tail)=newn;
    }
    else
    {
        newn->prev=(*Tail);
        (*Tail)->next=newn;
        (*Tail)=newn;
    }
    (*Tail)->next=(*Head);
    (*Head)->prev=(*Tail);
    size++;
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if((*Head==NULL) && (*Tail==NULL))
    {
        return;
    }
    else if((*Head)==(*Tail))
    {
        free((*Head));
        (*Head)=NULL;
        (*Tail)=NULL;
    }
    else
    {
        (*Head)=(*Head)->next;
        free((*Tail)->next);

        (*Tail)->next=(*Head);
        (*Head)->prev=(*Tail);
    }
    size--;
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
    if((*Head)==NULL && (*Tail)==NULL)
    {
        return;
    }
    else if((*Head)==(*Tail))
    {
        free((*Tail));
        (*Head)=NULL;
        (*Tail)=NULL;
    }
    else
    {
        (*Tail)=(*Tail)->prev;
        free((*Tail)->next);

        (*Head)->prev=(*Tail);
        (*Tail)->next=(*Head);
    }
    size--;
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int pos)
{
    if(pos < 1 || pos > size+1)
    {
        return;
    }

    if(pos==1)
    {
        InsertFirst(Head,Tail,no);
    }
    else if(pos==size+1)
    {
        InsertLast(Head,Tail,no);
    }
    else
    {
        PNODE temp=(*Head);
        PNODE newn=NULL;

        newn=(PNODE)malloc(sizeof(NODE));

        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size ++;
    }
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }
    if(ipos ==1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(ipos == size)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        PNODE temp = (*Head);
        
        for(int i = 1; i < ipos -1 ; i ++)
        {
            temp = temp -> next;
        }
       
        temp -> next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
        
        size--;
    }
}
int main()
{
    PNODE first=NULL;
    PNODE last=NULL;
    int iRet=0;

    InsertFirst(&first,&last,101);
    InsertFirst(&first,&last,51);
    InsertFirst(&first,&last,21);
    InsertFirst(&first,&last,11);

    InsertLast(&first,&last,150);

    InsertAtPos(&first,&last,31,3);

    Display(first,last);
    iRet=Count();
    printf("Number of Elements are : %d\n",iRet);

    DeleteFirst(&first,&last);

    Display(first,last);
    iRet=Count();
    printf("Number of Elements are : %d\n",iRet);

    DeleteAtPos(&first,&last,3);

    Display(first,last);
    iRet=Count();
    printf("Number of Elements are : %d\n",iRet);

     DeleteLast(&first,&last);

    Display(first,last);
    iRet=Count();
    printf("Number of Elements are : %d\n",iRet);

    return 0;
}