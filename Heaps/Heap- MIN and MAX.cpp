#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int maxheap[MAX], minheap[MAX];


    void maxinsert(int index)
    {
        int temp = maxheap[index];
        while(( index > 1) and (temp > maxheap[index/2]))
        {
            maxheap[index] = maxheap[index/2];
            index = index/2;
        }
        maxheap[index] = temp;
    }

    void mininsert(int index)
    {
        int temp = minheap[index];
        while(( index > 1 ) and (temp < minheap[index/2]))
        {
            minheap[index] = minheap[index/2];
            index = index/2;
        }
        minheap[index] = temp;
    }

    void display(int len)
    {
        cout<<"\n========================================\n";
        cout<<"MAX HEAP: ";
        for(int i=1; i < len; i++)
            cout<<maxheap[i]<<" ";
        cout<<endl;

        cout<<"MIN HEAP: ";
        for(int i=1; i < len; i++)
            cout<<minheap[i]<<" ";
        cout<<"\n========================================";
    }
int main()
{
    int len,data;
    cout<<"Enter the number of elements to be entered in Heap: ";
    cin>>len;
    /****Initialise the array*****/
    maxheap[0] = 0;
    minheap[0] = 0;
    for(int i=1;i <= len; i++)
    {
        cout<<"Enter "<<i<<" element: ";
        cin>>data;
        maxheap[i] = data;
        minheap[i] = data;
    }

    /*******Organising each element properly in heap******/
    for(int i=2;i<=len;i++)
    {
       maxinsert(i);
       mininsert(i);
    }

    int newindex = len+1;
    int choice;


    /*******Printing the MAX Heap Generated**********/

    display(newindex);

    while(1)
    {
        cout<<"\nPress 1 to insert a new number: ";
        cout<<"\nPress 2 to Display: ";
        cout<<"\nPress 3 to Exit: ";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: cout<<"Enter "<<newindex<<" element: ";
                    cin>>data;
                    maxheap[newindex] = data;
                    minheap[newindex] = data;
                    maxinsert(newindex);
                    mininsert(newindex);
                    newindex++;
                    break;

            case 2: display(newindex);
                    break;

            case 3: return 0;

            default: cout<<"Enter a valid choice !"<<endl;
        }
    }
}
