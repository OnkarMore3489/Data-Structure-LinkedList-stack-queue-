#include<iostream>
using namespace std;

void Swap(float *p,float *q)
{
    float temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
int main()
{
    float x=0,y=0;

    cout<<"Enter the First Number : "<<"\n";
    cin>>x;

    cout<<"Enter the Second Number : "<<"\n";
    cin>>y;
 
    Swap(&x,&y);
    cout<<"values after swap : "<<x<<" and "<<y;
    return 0;
}