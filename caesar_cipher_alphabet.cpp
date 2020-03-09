#include<iostream>
using namespace std;

int main()
{
    char ch,result;

    cout<<"Enter an alphabet: ";
    cin>>ch;

    if(isupper(ch))
    {
        result+=char(int(ch+4-65)%26+65);
    }
    else
    {
        result+=char(int(ch+4-97)%26+97);
    }

    cout<<"After caesar cipher: "<<result;

    return 0;
}
