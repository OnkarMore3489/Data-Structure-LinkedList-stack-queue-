#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

void Display(PNODE Head,PNODE Tail)
{
    if(Head==NULL && Tail==NULL)
    {
        return;
    }

     do
     {
        printf("|%d| ->",Head->data);
        Head=Head->next;
     } while(Head!=Tail->next);

     printf("NULL");
     printf("\n");
}

int Count(PNODE Head,PNODE Tail)
{
    if(Head==NULL && Tail==NULL)
    {
        return 0;
    }

    int iCnt=0;

    do
    {
        iCnt++;
        Head=Head->next;
    } while(Head!=Tail->next);

    return iCnt;
    
}
void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if((*Head==NULL) && (*Tail==NULL))
    {
       (*Head)=newn;
       (*Tail)=newn;
       (*Tail)->next=(*Head);
    }
    else
    {
       newn->next=(*Head);
       (*Head)=newn;
       (*Tail)->next=(*Head);
    }
}

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if((*Head==NULL) && (*Tail==NULL))
    {
        (*Head)=newn;
        (*Tail)=newn;
        (*Tail)->next=(*Head);
    }
    else
    {
        (*Tail)->next=newn;
        (*Tail)=newn;
        (*Tail)->next=(*Head);
    }
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if((*Head==NULL) && (*Tail==NULL))
    {
        return;
    }
    else if(*Head==*Tail)
    {
        free(*Head);
        (*Head)=NULL;
        (*Tail)=NULL;
    }
    else
    {
        (*Head)=(*Head)->next;
        free((*Tail)->next);
        (*Tail)->next=(*Head);
    }
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
    if((*Head==NULL) && (*Tail==NULL))
    {
        return;
    }
    else if((*Head==*Tail))
    {
        free(*Head);
        (*Head)=NULL;
        (*Tail)=NULL;
    }
    else
    {
        PNODE temp=(*Head);

        while(temp->next!=(*Tail))
        {
            temp=temp->next;
        }
        free(temp->next);
        (*Tail)=temp;
        (*Tail)->next=(*Head);
    }
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int pos)
{
    int size=Count((*Head),(*Tail));

    if((pos < 1) || (pos > size+1))
    {
        return;
    }
    else if(pos==1)
    {
        InsertFirst(Head,Tail,no);
    }
    else if(pos==size+1)
    {
        InsertLast(Head,Tail,no);
    }
    else
    {
        PNODE newn=NULL;
        PNODE temp=(*Head);

        newn=(PNODE)malloc(sizeof(NODE));

        newn->data=no;
        newn->next=NULL;

        for(int i=1;i<pos-1;i++)
        {
           temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int pos)
{
     int size=Count((*Head),(*Tail));

    if((pos < 1) || (pos > size))
    {
        return;
    }
    else if(pos==1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(pos==size)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        PNODE temp=(*Head);
        PNODE targated=NULL;

        for(int i=1;i<pos-1;i++)
        {
           temp=temp->next;
        }
        targated=temp->next;
        temp->next=targated->next;
        free(targated);
    }
}
int main()
{
    PNODE first=NULL;
    PNODE last=NULL;
    int iRet=0;

    InsertFirst(&first,&last,50);
    InsertFirst(&first,&last,40);
    InsertFirst(&first,&last,30);
    InsertFirst(&first,&last,20);
    InsertFirst(&first,&last,10);

    Display(first,last);
    iRet=Count(first,last);
    printf("Number of Elements are : %d\n",iRet);

    InsertLast(&first,&last,60);

    Display(first,last);
    iRet=Count(first,last);
    printf("Number of Elements are : %d\n",iRet);

    DeleteFirst(&first,&last);

    Display(first,last);
    iRet=Count(first,last);
    printf("Number of Elements are : %d\n",iRet);

    DeleteLast(&first,&last);

    Display(first,last);
    iRet=Count(first,last);
    printf("Number of Elements are : %d\n",iRet);

    InsertAtPos(&first,&last,35,3);

    Display(first,last);
    iRet=Count(first,last);
    printf("Number of Elements are : %d\n",iRet);

    DeleteAtPos(&first,&last,3);

    Display(first,last);
    iRet=Count(first,last);
    printf("Number of Elements are : %d\n",iRet);
    return 0;
}