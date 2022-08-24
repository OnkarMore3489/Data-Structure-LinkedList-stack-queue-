#include<iostream>
using namespace std;

//specific Function
void Swap(char *p,char *q)
{
    char temp='\0';
    temp=*p;
    *p=*q;
    *q=temp;
}

//Generic Function
template <class T>
void SwapX(T *p,T *q)
{
    T temp='\0';
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
 
    SwapX(&x,&y);
    cout<<"values after swap : "<<x<<" and "<<y;
    return 0;
}