#include <iostream>
using namespace std;
void marge(int a[],int s,int mid,int l)
{
    int i,j,k;
    int n=mid-s+1;
    int n2=l-mid;
    int rr[n+1],cc[n2+1];
    for(i=0;i<n;i++)
    {rr[i]= a[s+i];}
    for(j=0; j<n2; j++)
    {cc[j]=a[mid+j+1];}
    cc[n2]=99999;
    rr[n]=99999;
    i=0;
    j=0;
    for(k=s;k<=l;k++)
    {
        if (cc[i]<=rr[j])
            a[k]=cc[i++];
        else
            a[k]=rr[j++];
    }
}
void devide(int a[],int s,int l)
{
    if(s>=l)
    {return;}
    int mid= (s+l)/2;
    devide(a,s,mid);
    devide(a,mid+1,l);
    marge(a,s,mid,l);
}
int main()
{
    int i,l=9;
    int a[10]= {5,7,2,1,6,9,3,8,10,4};
    cout<<"Before sorted: \n";
    for(i=0; i<=l; i++)
    {
        cout<<a[i]<<endl;
    }
    devide(a,0,9);
    cout<<"\nAfter sorted: \n"<<endl;
    for(i=0;i<=l;i++)
    cout<<a[i]<<endl;
    return 0;
}
