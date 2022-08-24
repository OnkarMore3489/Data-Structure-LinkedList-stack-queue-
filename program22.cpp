#include<iostream>
using namespace std;

void Swap(char *p,char *q)
{
    char temp='\0';
    temp=*p;
    *p=*q;
    *q=temp;
}
int main()
{
    char x='\0',y='\0';

    cout<<"Enter the First character : "<<"\n";
    cin>>x;

    cout<<"Enter the Second character : "<<"\n";
    cin>>y;
 
    Swap(&x,&y);
    cout<<"values after swap : "<<x<<" and "<<y;
    return 0;
}