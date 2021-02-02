#include <iostream>
using namespace std;

int main()
{
    int total_amount,i,total_note,num,x,y=0;
    cout<<"Enter Total Amount: "<<endl;
    cin>>total_amount;
    cout<<"How Many Notes?"<<endl;
    cin>>total_note;
    int note[total_note];
    for(i=1;i<=total_note;i++)
    {
        cout<<"Enter Note: "<<i<<endl;
        cin>>note[i];
    }
    for(i=1;i<=total_note;i++)
    {
        if (note[i]<=total_amount)
        {
            num=total_amount/note[i];
            cout<<num<<" notes of "<<note[i]<<" tk"<<endl;
            total_amount=total_amount-num*note[i];
            x=num;
            y=y+x;
            if(total_amount==0)
            cout<<"\nMinimum required is: "<<y<<endl;
        }
    }
         return 0;
}

