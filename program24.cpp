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
    char x='A',y='Z';
    SwapX(&x,&y);
    cout<<"values after swap : "<<x<<" and "<<y<<"\n";

    int i=11,j=21;
    SwapX(&i,&j);
    cout<<"values after swap : "<<i<<" and "<<j<<"\n";
    return 0;
}