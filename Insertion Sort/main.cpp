#include <iostream>
using namespace std;

int main()
{
    int i,j,temp,n=5,p=0,m;
    int data[5]={8,5,6,1,3};
    for(i=0;i<n;i++)
    {
       j=i;
       while(j>0&&data[j]<data[j-1])
       {   temp=data[j];
           data[j]=data[j-1];
           data[j-1]=temp;
           j--;
           cout<<"iteration:"<<i<<" "<<"step:"<<p<<endl;
           for(m=0;m<n;m++)
           cout<<"\t"<<data[m];
           p++;
           cout<<"\n";
       }
           p=0;
    }
           return 0;
}
