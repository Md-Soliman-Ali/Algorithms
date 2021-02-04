#include <iostream>
using namespace std;

int main()
{
  int array[100],search,c,n,count=0;
  cout<<"Enter how many numbers in array: ";
  cin>>n;
  cout<<"Enter numbers: \n";
  for(c=0;c<n;c++)
  cin>>array[c];
  cout<<"Enter the number to search: ";
  cin>>search;
  for(c=0;c<n;c++)
   {
      if(array[c]==search)
      {
         cout<<"The Search number is: " << search <<"\n"<<"The Search number position is: " << c+1<<endl;
         count++;
      }
   }
   if (count==0)
     cout<< "not present in array.\n"<<search;
   else
      cout<<"present times in array: "<<count<<endl;
    return 0;
}
