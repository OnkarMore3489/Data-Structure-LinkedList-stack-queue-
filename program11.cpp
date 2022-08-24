#include<iostream>
using namespace std;

typedef struct node 
{
   int data;
   struct node *next;
   struct node *prev;

}NODE,*PNODE,**PPNODE;

class SinglyLL
{
    private:
            PNODE first;
            int size;

    public:
           SinglyLL()
           {
               first=NULL;
               size=0;
           }

           void InsertFirst(int no)
           {
              PNODE newn=NULL;

              newn=new NODE;

              newn->data=no;
              newn->next=NULL;
              newn->prev=NULL;

              if(first==NULL)
              {
                  first=newn;
              }
              else
              {
                  newn->next=first;
                  first->prev=newn;
                  first=newn;
              }
              size++;
           }

           void InsertLast(int no)
           {
              PNODE newn=NULL;

              newn=new NODE;

              newn->data=no;
              newn->next=NULL;
              newn->prev=NULL;

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
                 newn->prev=temp;
              }
              size++;
           }

           void InsertAtPos(int no,int pos)
           {
               if(pos < 1 || pos > size+1)
               {
                   cout<<"Invalid position"<<"\n";
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
                   newn->prev=NULL;

                   for(int i=1;i<pos-1;i++)
                   {
                       temp=temp->next;
                   }
                   newn->next=temp->next;
                   newn->next->prev=newn;
                   temp->next=newn;
                   newn->prev=temp;
               }
               size++;
           }

           void DeleteFirst()
           {
              if(first==NULL)
              {
                  return;
              }
              else if(first->next==NULL)
              {
                  delete first;
                  first=NULL;
              }
              else
              {
                  first=first->next;
                  delete first->prev;
                  first->prev=NULL;
              }
              size--;
           }

           void DeleteLast()
           {
               PNODE temp=first;

               if(first==NULL)
               {
                   return;
               }
               else if(first->next==NULL)
               {
                   delete first;
                   first=NULL;
                   
               }
               else
               {
                   while(temp->next!=NULL)
                   {
                       temp=temp->next;
                   }
                   temp->prev->next=NULL;
                   free(temp);
               }
               size--;
           }

           void DeleteAtPos(int pos)
           {
               if(pos < 1 || pos > size)
               {
                   cout<<"Invalid position"<<"\n";
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
                   temp->next->prev=temp;
                   delete targeted;

                   size--;
               }
           }

           void Display()
           {
               PNODE temp=first;

               while(temp != NULL)
               {
                printf("|%d| -> ",temp->data);
                temp =temp -> next;
               }
           }

           int Count()
           {
               return size;
           }
};

int main()
{
    int iChoice = 1, value = 0, iRet = 0, pos = 0;
    SinglyLL obj;
    
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
