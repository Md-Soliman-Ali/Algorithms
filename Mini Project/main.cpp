#include <iostream>
#include<windows.h>
using namespace std;
void search_car(int slot[])
{
    int n = 4, i, car_num;
    cout<<"\t \tEnter Car Number: ";
    cin>>car_num;
    for(i=0;i<n;i++)
    {
    if (slot[i]==car_num)
    {
        cout<<"\t ********** Car "<<car_num<<" found in Slot "<<i+1<<"**********\n"<<endl;
        break;
    }
    }
    if(i==n)
    {
    cout<<"\t ********** Car "<<car_num<<" not found in any Parking Slot **********\n"<<endl;
    }
}
void view_slot(int slot[])
{
    int n=4,i;
    for(i=0;i<n;i++)
    {
        if(slot[i]==999)
        {
            cout<<"\t \t Slot "<<i+1<<" Empty\n"<<endl;
        }
        else
            {
            cout<<"\t \t Slot "<<i+1<<" Car Number"<<slot[i]<<endl;
            }
    }
}
int check_car(int slot[], int key)
{
    int n=4,i;
    for(i=0;i<n;i++)
    {
    if(slot[i] == key)
    {
        cout<<"\t ********** Car "<<key<<" is already in Slot"<<i+1<<endl;
        return 1;
        break;
    }
    }
    if(i==n)
    {return 0;}
}
int get_car_slot_pos(int slot[],int car_num)
{
    int n=4,i;
    for(i=0;i<n;i++)
    {
    if(slot[i]==car_num)
    {
        return i;
        break;
    }
    }
    return 0;
}
int is_slot_full(int slot[])
{
    int n=4,i;
    for(i=0;i<n;i++)
    {
        if(slot[i]==999)
        {
            return 0;
            break;
        }
    }
    return 1;
}
int remove_car_prompt(int slot[],int time[])
	{
		int n=4,i,j,temp,command;
        for(i=0;i<n;i++)
		{
		  j=i;
			while(j>0&&time[j]<time[j-1])
			{
                temp=time[j];
				time[j]=time[j-1];
				time[j-1]=temp;
                temp=slot[j];
				slot[j]=slot[j-1];
				slot[j-1]=temp;
				j--;
			}
		}
        cout<<"\t \t Car Number "<<slot[0]<<" need to be removed first.\n";
		cout<<"\t \t Press 1 => Yes Remove and Park New Car\n";
		cout<<"\t \t Press 0 => No, Don't Park the New Car\n";
        cout<<"\t \t Your Choice: ";
		cin>>command;
		if(command == 1)
        {
            return slot[0];
        }
        else{return 0;}
    }
int main()
{
    system("color 5f");
    int n_slot=4,command,i;
    int car_num,car_time;
    int slot[] = {999, 999, 999, 999};
    int time[] = {999, 999, 999, 999};
    goto menu;
        menu:
        cout<<"\t ========== Car Parking System ==========\n";
        cout<<"\t \t Press 1 => Insert Car \n";
        cout<<"\t \t Press 2 => View Slot Details \n";
        cout<<"\t \t Press 3 => Search Car \n";
        cout<<"\t \t Your Choice: ";
        cin>>command;
        if(command==1)
        {
            cout<<"\t********** Enter Car Details **********\n";
            cout<<"\t \t Car Number: ";
            cin>>car_num;
            cout<<"\t \t Car Waiting Time: ";
            cin>>car_time;
            if(check_car(slot, car_num)==0)
            {
              if(is_slot_full(slot)==0)
                {
                  for(i=0;i<n_slot;i++)
                    {
                       if(slot[i]==999)
                        {
                            slot[i]=car_num;
                            time[i]=car_time;
                            cout<<"\t ********** Car Parked at Slot "<<i+1<<" **********\n";
                            goto menu;
                            break;
                        }
                    }
               }
               else
                {
                    cout<<"\t ********** No Slot is Empty **********\n";
                    int remove_car_num=remove_car_prompt(slot, time);
                    if(remove_car_num==0)
                    {
                        cout<<"\t ********** New Car "<<i+1<<" not parked **********\n";
                        goto menu;
                    }
               else
                   {
                        int slot_id=get_car_slot_pos(slot, remove_car_num);
                        slot[slot_id]=car_num;
                        time[slot_id]=car_time;
                        cout<<"\t ********** Car Number "<<remove_car_num<<" Removed. **********\n";
                        cout<<"\t ********** Car Number "<<car_num<<" Parked at Slot"<<slot_id+1<<"**********\n";
                        goto menu;
                   }
                }
            }
            else{goto menu;}
        }
        else if(command==2)
        {
                view_slot(slot);
                goto menu;
        }
        else if(command==3)
        {
                search_car(slot);
                goto menu;
        }
        else
            {
            cout<<"\t ********** Invalid Command **********\n";
            goto menu;
            }
    }

