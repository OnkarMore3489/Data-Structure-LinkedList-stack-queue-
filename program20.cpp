#include<iostream>
using namespace std;

void Swap(int *p,int *q)
{
    int temp=0;
    temp=*p;
    *p=*q;
    *q=temp;
}
int main()
{
    int x=0,y=0;

    cout<<"Enter the First Number : "<<"\n";
    cin>>x;

    cout<<"Enter the Second Number : "<<"\n";
    cin>>y;
 
    Swap(&x,&y);
    cout<<"values after swap : "<<x<<" and "<<y;
    return 0;
}