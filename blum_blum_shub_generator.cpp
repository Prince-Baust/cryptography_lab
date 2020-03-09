#include<iostream>
using namespace std;

int main()
{
    long long p,q,n,s,x[100],b[100],i,j,m;

    cout<<"Enter two prime number(such as p=q=3(mod 4)):"<<endl;
    cin>>p;
    cin>>q;

    n=p*q;

    cout<<"Enter the value of s:"<<endl;
    cin>>s;

    x[0]=(s*s)%n;

    for(i=1; i<100; i++)
    {
        x[i]=((x[i-1])*(x[i-1]))%n;
        b[i]=x[i]%2;
    }

    for(i=1; i<100; i++)
    {
        cout<<x[i]<<"\t"<<b[i]<<"\t";
        cout<<endl;
    }

    for(i=1; i<100; i++)
    {
        if(i%8==0)
        {
            m=(b[i-7]*128)+(b[i-6]*64)+(b[i-5]*32)+(b[i-4]*16)+(b[i-3]*8)+(b[i-2]*4)+(b[i-1]*2)+b[i];
            cout<<(char)m;
        }
    }

    return 0;
}
