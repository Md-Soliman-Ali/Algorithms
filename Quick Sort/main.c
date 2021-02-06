#include <stdio.h>
#include <stdlib.h>
void quick(int a[],int left,int right)
{
    if(right>left)
    {
        int q=partition(a,left,right);
        quick(a,left,q-1);
        quick(a,q+1,right);
    }
}
int partition(int a[],int left,int right)
{
    int privot,i,j,key;
    privot=left;
    i=left;
    j=right;
    while(i<j)
    {
        while(a[privot]>=a[i] && i<right)
        {i++;}
        while(a[j]>a[privot])
        {j--;}
        if(i<j)
        {
            key=a[i];
            a[i]=a[j];
            a[j]=key;
        }
    }
    key=a[privot];
    a[privot]=a[j];
    a[j]=key;
    return j;
}
int main()
{
    int i,n;
    printf("Array size: ");
    scanf("%d",&n);
    int a[n];
    printf("Insert array element: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quick(a,0,n-1);
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
