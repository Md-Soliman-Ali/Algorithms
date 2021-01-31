#include <iostream>
using namespace std;

int main()
{
    int n,i,arr[100],search,first=0,last,middle;
	cout<<"Enter total number of elements: ";
	cin>>n;
	cout<<"Enter number: \n";
	for (i=0; i<n; i++){cin>>arr[i];}
	cout<<"Enter a number to find: ";
	cin>>search;
	last = n-1;
	middle = (first+last)/2;
	while (first <= last)
	{
		if(arr[middle]<search)
		{
			first = middle + 1;
        }
		else if(arr[middle]==search)
		{
			cout<<search<<" found at: "<<middle+1<<"\n";
			break;
		}
		else{last = middle - 1;}
		middle = (first + last)/2;
    }
	if(first > last)
	{
		cout<<"Not found! "<<search<<" is not present in the list.";
	}
    return 0;
}
